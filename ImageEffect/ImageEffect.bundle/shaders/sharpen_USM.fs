precision highp float;

uniform sampler2D u_texture;
varying vec2 texcoordOut;

varying vec2 texcoordOutLeft;
varying vec2 texcoordOutTop;
varying vec2 texcoordOutRight;
varying vec2 texcoordOutBottom;

uniform float alpha;

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    
    float sum = srcColor.g;
    sum += texture2D(u_texture, texcoordOutLeft).g;
    sum += texture2D(u_texture, texcoordOutTop).g;
    sum += texture2D(u_texture, texcoordOutRight).g;
    sum += texture2D(u_texture, texcoordOutBottom).g;
    sum *= 0.2;
    
    vec4 resultColor = clamp(srcColor + 2.0 * (srcColor.g - sum), 0.0, 1.0);
    
    gl_FragColor = vec4(mix(srcColor, resultColor, alpha).rgb, srcColor.a);
}
