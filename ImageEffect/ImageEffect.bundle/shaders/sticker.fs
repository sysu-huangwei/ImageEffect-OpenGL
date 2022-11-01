precision highp float;

uniform sampler2D u_texture;
uniform sampler2D u_sticker;
varying vec2 texcoordOut;

void main()
{
    vec4 textureColor = texture2D(u_texture, texcoordOut);
    vec4 stickerColor = texture2D(u_sticker, texcoordOut);
    
    gl_FragColor = vec4(mix(textureColor.rgb, stickerColor.rgb, stickerColor.a), textureColor.a);
}
