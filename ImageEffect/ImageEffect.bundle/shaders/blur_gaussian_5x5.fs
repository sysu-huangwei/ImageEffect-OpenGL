precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;
varying vec4 texcoordOutNear[2];

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    
    vec4 sum = srcColor * 0.4;
    sum += texture2D(u_texture, texcoordOutNear[0].xy) * 0.2;
    sum += texture2D(u_texture, texcoordOutNear[0].zw) * 0.2;
    sum += texture2D(u_texture, texcoordOutNear[1].xy) * 0.1;
    sum += texture2D(u_texture, texcoordOutNear[1].zw) * 0.1;
    
    gl_FragColor = vec4(sum.rgb, srcColor.a);
}
