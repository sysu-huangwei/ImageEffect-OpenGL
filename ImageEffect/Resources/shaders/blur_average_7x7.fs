precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;
varying vec4 texcoordOutNear[3];

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    
    vec4 sum = srcColor;
    sum += texture2D(u_texture, texcoordOutNear[0].xy);
    sum += texture2D(u_texture, texcoordOutNear[0].zw);
    sum += texture2D(u_texture, texcoordOutNear[1].xy);
    sum += texture2D(u_texture, texcoordOutNear[1].zw);
    sum += texture2D(u_texture, texcoordOutNear[2].xy);
    sum += texture2D(u_texture, texcoordOutNear[2].zw);
    sum *= 0.1428571;
    
    gl_FragColor = sum;
}
