attribute vec2 a_position;
attribute vec2 a_texCoord;
varying vec2 texcoordOut;
uniform vec2 offset;

varying vec4 texcoordOutNear[4];

void main()
{
    texcoordOut = a_texCoord;
    gl_Position = vec4(a_position, 0.0, 1.0);
    
    texcoordOutNear[0].xy = a_texCoord - offset;
    texcoordOutNear[0].zw = a_texCoord + offset;
    texcoordOutNear[1].xy = a_texCoord - 2.0 * offset;
    texcoordOutNear[1].zw = a_texCoord + 2.0 * offset;
    texcoordOutNear[2].xy = a_texCoord - 3.0 * offset;
    texcoordOutNear[2].zw = a_texCoord + 3.0 * offset;
    texcoordOutNear[3].xy = a_texCoord - 4.0 * offset;
    texcoordOutNear[3].zw = a_texCoord + 4.0 * offset;
}
