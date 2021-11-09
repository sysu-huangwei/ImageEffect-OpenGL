attribute vec2 a_position;
attribute vec2 a_texCoord;
varying vec2 texcoordOut;
uniform vec2 offset;

varying vec2 texcoordOutLeft;
varying vec2 texcoordOutTop;
varying vec2 texcoordOutRight;
varying vec2 texcoordOutBottom;

void main()
{
    texcoordOut = a_texCoord;
    gl_Position = vec4(a_position, 0.0, 1.0);
    
    texcoordOutLeft = a_texCoord + vec2(-offset.x, 0.0);
    texcoordOutTop = a_texCoord + vec2(0.0, offset.y);
    texcoordOutRight = a_texCoord + vec2(offset.x, 0.0);
    texcoordOutBottom = a_texCoord + vec2(0.0, -offset.y);
}
