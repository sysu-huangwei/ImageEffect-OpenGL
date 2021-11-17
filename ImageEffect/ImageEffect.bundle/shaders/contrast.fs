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
