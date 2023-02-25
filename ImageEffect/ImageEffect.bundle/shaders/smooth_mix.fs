precision highp float;

uniform sampler2D u_texture;
uniform sampler2D u_blur;
uniform sampler2D u_border;
varying vec2 texcoordOut;

uniform float alpha;

void main()
{
    vec3 srcColor = texture2D(u_texture, texcoordOut).rgb;
    vec3 blurColor = texture2D(u_blur, texcoordOut).rgb;
    vec3 borderColor = texture2D(u_border, texcoordOut).rgb;
    
    highp float border = (borderColor.r + borderColor.g + borderColor.b) / 3.0;
    vec3 smoothColor = mix(blurColor, srcColor, border);
    
    gl_FragColor = vec4(mix(srcColor, smoothColor, alpha), 1.0);
}
