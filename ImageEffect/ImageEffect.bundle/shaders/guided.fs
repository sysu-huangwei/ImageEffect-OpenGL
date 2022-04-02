precision highp float;

uniform sampler2D u_origin;
uniform sampler2D u_meanA;
uniform sampler2D u_meanB;
varying vec2 texcoordOut;

void main()
{
    vec3 originColor = texture2D(u_origin, texcoordOut).rgb;
    vec3 meanAColor = texture2D(u_meanA, texcoordOut).rgb;
    vec3 meanBColor = texture2D(u_meanB, texcoordOut).rgb;
    
    vec3 result = meanAColor * originColor + meanBColor;
    
    gl_FragColor = vec4(result, 1.0);
}
