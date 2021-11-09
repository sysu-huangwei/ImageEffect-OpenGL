precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;
varying vec4 texcoordOutNear[4];

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    
    vec4 sum = srcColor * 0.18;
    sum += texture2D(u_texture, texcoordOutNear[0].xy) * 0.15;
    sum += texture2D(u_texture, texcoordOutNear[0].zw) * 0.15;
    sum += texture2D(u_texture, texcoordOutNear[1].xy) * 0.12;
    sum += texture2D(u_texture, texcoordOutNear[1].zw) * 0.12;
    sum += texture2D(u_texture, texcoordOutNear[2].xy) * 0.09;
    sum += texture2D(u_texture, texcoordOutNear[2].zw) * 0.09;
    sum += texture2D(u_texture, texcoordOutNear[3].xy) * 0.05;
    sum += texture2D(u_texture, texcoordOutNear[3].zw) * 0.05;
    
    gl_FragColor = vec4(sum.rgb, srcColor.a);
}
