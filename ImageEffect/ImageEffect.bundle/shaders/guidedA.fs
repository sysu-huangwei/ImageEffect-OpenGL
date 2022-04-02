precision highp float;

uniform sampler2D u_originMean;
uniform sampler2D u_origin2Mean;
varying vec2 texcoordOut;

uniform float eps;

void main()
{
    vec3 originMeanColor = texture2D(u_originMean, texcoordOut).rgb;
    vec3 origin2MeanColor = texture2D(u_origin2Mean, texcoordOut).rgb;
    
    vec3 variance = origin2MeanColor - originMeanColor * originMeanColor;
    
    vec3 A = variance / (variance + eps);
    
    gl_FragColor = vec4(A, 1.0);
}
