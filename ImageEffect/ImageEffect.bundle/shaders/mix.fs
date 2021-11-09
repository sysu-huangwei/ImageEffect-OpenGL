precision highp float;

uniform sampler2D u_texture;
uniform sampler2D u_texture1;
varying vec2 texcoordOut;

uniform float alpha;

void main()
{
    vec4 srcColor = texture2D(u_texture, texcoordOut);
    vec4 srcColor1 = texture2D(u_texture1, texcoordOut);
    
    gl_FragColor = mix(srcColor, srcColor1, alpha);
}
