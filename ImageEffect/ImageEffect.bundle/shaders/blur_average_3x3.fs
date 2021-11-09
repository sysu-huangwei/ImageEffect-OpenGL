precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;
varying vec4 texcoordOutNear;

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    
    vec4 sum = srcColor;
    sum += texture2D(u_texture, texcoordOutNear.xy);
    sum += texture2D(u_texture, texcoordOutNear.zw);
    sum *= 0.3333333;
    
    gl_FragColor = sum;
}
