precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;

uniform float brightness;

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    gl_FragColor = vec4(clamp(srcColor.rgb + brightness, 0.0, 1.0), srcColor.a);
}
