precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;

uniform float highLight;
uniform float shadow;
uniform float midtone;

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    
    float diff = highLight - shadow;
    vec3 rgbDiff = max(srcColor.rgb - shadow, 0.0);
    
    gl_FragColor = vec4(clamp(pow(rgbDiff / diff, vec3(1.0 / midtone)), 0.0, 1.0), srcColor.a);
}
