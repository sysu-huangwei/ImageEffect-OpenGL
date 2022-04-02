precision highp float;

uniform sampler2D u_texture;
uniform sampler2D u_texture1;
varying vec2 texcoordOut;

uniform float addOrSubstract;

void main()
{
    vec3 srcColor = texture2D(u_texture, texcoordOut).rgb;
    vec3 srcColor1 = texture2D(u_texture1, texcoordOut).rgb;
    if (addOrSubstract > 0.5) {
        gl_FragColor = vec4(srcColor + srcColor1, 1.0);
    } else {
        gl_FragColor = vec4(srcColor - srcColor1, 1.0);
    }
}
