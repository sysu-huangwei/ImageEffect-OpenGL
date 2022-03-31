precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;
varying vec4 texcoordOutNear[4];

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
    sum *= 0.1111111;
    
    gl_FragColor = vec4(mix(srcColor.rgb, sum, alpha), srcColor.a);
}
