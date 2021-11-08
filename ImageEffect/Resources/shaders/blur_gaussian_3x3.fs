precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;
varying vec4 texcoordOutNear;

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    
    vec4 sum = srcColor * 0.5;
    sum += texture2D(u_texture, texcoordOutNear.xy) * 0.25;
    sum += texture2D(u_texture, texcoordOutNear.zw) * 0.25;
    
    gl_FragColor = vec4(sum.rgb, srcColor.a);
}
