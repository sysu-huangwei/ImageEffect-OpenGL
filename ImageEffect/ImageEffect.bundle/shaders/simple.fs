precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;
void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    gl_FragColor = vec4(1,0,0,1);//srcColor;
}
