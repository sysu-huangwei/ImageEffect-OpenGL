precision highp float;

uniform sampler2D u_originMean;
uniform sampler2D u_A;
varying vec2 texcoordOut;

uniform float eps;

void main()
{
    vec3 originMeanColor = texture2D(u_originMean, texcoordOut).rgb;
    vec3 AColor = texture2D(u_A, texcoordOut).rgb;
    
    vec3 B = originMeanColor - AColor * originMeanColor;
    
    gl_FragColor = vec4(B, 1.0);
}
