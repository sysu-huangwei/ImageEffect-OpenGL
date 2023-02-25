precision highp float;

uniform sampler2D u_texture;
uniform sampler2D u_mean;
varying vec2 texcoordOut;

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    vec4 meanColor = texture2D(u_mean, texcoordOut);
    
    highp vec3 diff = (srcColor.rgb - meanColor.rgb) * 7.07;
    diff = diff * diff;
    diff.r = min(diff.r, 1.0);
    diff.g = min(diff.g, 1.0);
    diff.b = min(diff.b, 1.0);
    
    gl_FragColor = vec4(diff, 1.0);
}
