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
