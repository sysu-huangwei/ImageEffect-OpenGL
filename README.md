# 图像特效库-OpenGLES版本
### 1.亮度
* PS里的亮度调整，主要是控制图片整体的亮度，可以弥补曝光过度和曝光补足需要补光的问题。
![PS](https://img-blog.csdnimg.cn/558ef05c760a41958f514e428652b7b1.png)

* 对RGB图像来说，亮度算法有很多种，最简单的一种就是直接整体提升或降低像素的RGB值。（RGB值为0到1，0纯黑，1纯白）
* 公式如下：
	* 新RGB值 = 旧RGB值 + 亮度值
	* 亮度值在-1到1之间
	* 新RGB值需要控制范围0到1

##### 使用OpenGL实现：

* 顶点着色器：

```c
attribute vec2 a_position;
attribute vec2 a_texCoord;
varying vec2 texcoordOut;

void main()
{
    texcoordOut = a_texCoord;
    gl_Position = vec4(a_position, 0.0, 1.0);
}
```

* 片段着色器：

	* `u_texture`为原图，`brightness`为调整亮度值，变化范围-1到1

```c
precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;

uniform float brightness;

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    gl_FragColor = vec4(clamp(srcColor.rgb + brightness, 0.0, 1.0), srcColor.a);
}
```

##### 效果：
![效果](https://img-blog.csdnimg.cn/6ca14400a7f64b928ec5da32154c2986.gif)


### 2.对比度
* PS里的对比度调整，可以增大图片明暗区别，两处更亮，暗处更暗，使得明暗更分明。
![PS](https://img-blog.csdnimg.cn/a553acd6897c459e8ce6c551ed39e94a.png)

* 对RGB图像来说，对比度算法依然有很多种，在不知道图像平均亮度的情况下，可以取0.5作为图像的平均亮度。超出0.5的像素做类似提亮的操作，低于0.5的像素做类似压暗的操作。（RGB值为0到1，0纯黑，1纯白）
* 公式如下：
	* 新RGB值 = 旧RGB值 + （旧RGB值 - 0.5）× 对比度值
	* 对比度值在0到1之间
	* 新RGB值需要控制范围0到1

##### 使用OpenGL实现：

* 顶点着色器：

```c
attribute vec2 a_position;
attribute vec2 a_texCoord;
varying vec2 texcoordOut;

void main()
{
    texcoordOut = a_texCoord;
    gl_Position = vec4(a_position, 0.0, 1.0);
}
```

* 片段着色器：

	* `u_texture`为原图，`contrast `为调整亮度值，变化范围0到1

```c
precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;

uniform float contrast;

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    vec3 contrastColor = srcColor.rgb + (srcColor.rgb - vec3(0.5)) * contrast;
    gl_FragColor = vec4(clamp(contrastColor, 0.0, 1.0), srcColor.a);
}
```

##### 效果：
![效果](https://img-blog.csdnimg.cn/3293093c3b1c466c8171760e77c50800.gif)


### 3.饱和度
* PS里的饱和度调整，可以使得颜色更饱满，更鲜艳。降低饱和度时，图片会越接近灰色（相当于失去了所有的色彩）。
![PS](https://img-blog.csdnimg.cn/8e2d64fe17ba48dab254712fd31457e9.png)

* 饱和度调整算法，需要先将RGB颜色转为HSV颜色，然后调整其S部分，最后再传唤回RGB颜色。从而达到线性调整饱和度的目的。（RGB值为0到1，0纯黑，1纯白）
* PS饱和度调整算法主要是利用HSL颜色空间进行饱和度S的上下限控制，对RGB空间进行补丁式调整。调整过程是在RGB空间进行，其原理简单的说就是判断每个像素点R/G/B值是否大于或小于平均值，大于加上调整值，小于则减去调整值，如何计算各个像素点的调整系数是关键。本算法主体思想就是利用HSL来计算各点的调整系数
* 公式如下：
![](https://img-blog.csdnimg.cn/dd7f29e9d91045318321ce05114a1940.png)
![](https://img-blog.csdnimg.cn/5e0fd560d138404394a1e38c1d68ae59.png)
![](https://img-blog.csdnimg.cn/096e60c93f1244cca0f8c3e7821f6a80.png)
##### 使用OpenGL实现：

* 顶点着色器：

```c
attribute vec2 a_position;
attribute vec2 a_texCoord;
varying vec2 texcoordOut;

void main()
{
    texcoordOut = a_texCoord;
    gl_Position = vec4(a_position, 0.0, 1.0);
}
```

* 片段着色器：

	* `u_texture`为原图，`saturation `为调整亮度值，变化范围-1到1

```c
precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;

uniform float saturation;

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    
    float rgbMax = max(max(srcColor.r, srcColor.g), srcColor.g);
    float rgbMin = min(min(srcColor.r, srcColor.g), srcColor.g);
    
    float delta = rgbMax - rgbMin;
    
    float value = rgbMax + rgbMin;
    
    // HSL
    float L = value / 2.0;
    float S;
    if (L < 0.5) {
        S = delta / value;
    } else {
        S = delta / (2.0 - value);
    }
    
    float alpha;
    vec3 resultColor;
    if (saturation < 0.0) {
        alpha = saturation;
        resultColor = vec3(L) + (srcColor.rgb - vec3(L)) * (1.0 + alpha);
    } else {
        if (saturation + S >= 1.0) {
            alpha = S;
        } else {
            alpha = 1.0 - saturation;
        }
        alpha = 1.0 / alpha - 1.0;
        resultColor = srcColor.rgb + (srcColor.rgb - vec3(L)) * alpha;
    }
    
    gl_FragColor = vec4(clamp(resultColor, 0.0, 1.0), srcColor.a);
}
```

##### 效果：
![效果](https://img-blog.csdnimg.cn/5c600d11e25d4b808bc7364b345f09a3.gif)




