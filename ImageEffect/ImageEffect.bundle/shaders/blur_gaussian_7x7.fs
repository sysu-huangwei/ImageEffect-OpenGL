precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;
varying vec4 texcoordOutNear[3];

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    
    vec4 sum = srcColor * 0.24;
    sum += texture2D(u_texture, texcoordOutNear[0].xy) * 0.17;
    sum += texture2D(u_texture, texcoordOutNear[0].zw) * 0.17;
    sum += texture2D(u_texture, texcoordOutNear[1].xy) * 0.13;
    sum += texture2D(u_texture, texcoordOutNear[1].zw) * 0.13;
    sum += texture2D(u_texture, texcoordOutNear[2].xy) * 0.08;
    sum += texture2D(u_texture, texcoordOutNear[2].zw) * 0.08;
    
    gl_FragColor = vec4(sum.rgb, srcColor.a);
}
