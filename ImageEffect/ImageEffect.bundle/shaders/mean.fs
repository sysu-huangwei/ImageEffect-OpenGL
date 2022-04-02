precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;
varying vec4 texcoordOutNear[6];

uniform float alpha;

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    
    vec3 sum = srcColor.rgb;
    sum += texture2D(u_texture, texcoordOutNear[0].xy).rgb;
    sum += texture2D(u_texture, texcoordOutNear[0].zw).rgb;
    sum += texture2D(u_texture, texcoordOutNear[1].xy).rgb;
    sum += texture2D(u_texture, texcoordOutNear[1].zw).rgb;
    sum += texture2D(u_texture, texcoordOutNear[2].xy).rgb;
    sum += texture2D(u_texture, texcoordOutNear[2].zw).rgb;
    sum += texture2D(u_texture, texcoordOutNear[3].xy).rgb;
    sum += texture2D(u_texture, texcoordOutNear[3].zw).rgb;
    sum += texture2D(u_texture, texcoordOutNear[4].xy).rgb;
    sum += texture2D(u_texture, texcoordOutNear[4].zw).rgb;
    sum += texture2D(u_texture, texcoordOutNear[5].xy).rgb;
    sum += texture2D(u_texture, texcoordOutNear[5].zw).rgb;
//    sum += texture2D(u_texture, texcoordOutNear[6].xy).rgb;
//    sum += texture2D(u_texture, texcoordOutNear[6].zw).rgb;
//    sum += texture2D(u_texture, texcoordOutNear[7].xy).rgb;
//    sum += texture2D(u_texture, texcoordOutNear[7].zw).rgb;
//    sum += texture2D(u_texture, texcoordOutNear[8].xy).rgb;
//    sum += texture2D(u_texture, texcoordOutNear[8].zw).rgb;
//    sum += texture2D(u_texture, texcoordOutNear[9].xy).rgb;
//    sum += texture2D(u_texture, texcoordOutNear[9].zw).rgb;
//    sum += texture2D(u_texture, texcoordOutNear[10].xy).rgb;
//    sum += texture2D(u_texture, texcoordOutNear[10].zw).rgb;
//    sum += texture2D(u_texture, texcoordOutNear[11].xy).rgb;
//    sum += texture2D(u_texture, texcoordOutNear[11].zw).rgb;
    sum /= 13.0;
    
    gl_FragColor = vec4(mix(srcColor.rgb, sum, alpha), srcColor.a);
}
