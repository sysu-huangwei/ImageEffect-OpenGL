attribute vec2 a_position;
attribute vec2 a_texCoord;
varying vec2 texcoordOut;
uniform vec2 offset;

varying vec4 texcoordOutNear;

void main()
{
    texcoordOut = a_texCoord;
    gl_Position = vec4(a_position, 0.0, 1.0);
    
    texcoordOutNear.xy = a_texCoord - offset;
    texcoordOutNear.zw = a_texCoord + offset;
}
