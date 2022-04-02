attribute vec2 a_position;
attribute vec2 a_texCoord;
varying vec2 texcoordOut;
uniform vec2 offset;

varying vec4 texcoordOutNear[6];

void main()
{
    texcoordOut = a_texCoord;
    gl_Position = vec4(a_position, 0.0, 1.0);
    
    texcoordOutNear[0].xy = a_texCoord + vec2(offset.x, 0.0);
    texcoordOutNear[0].zw = a_texCoord + vec2(-offset.x, 0.0);
    texcoordOutNear[1].xy = a_texCoord + vec2(0.0, offset.y);
    texcoordOutNear[1].zw = a_texCoord + vec2(0.0, -offset.y);
    
    texcoordOutNear[2].xy = a_texCoord + vec2(offset.x, offset.y);
    texcoordOutNear[2].zw = a_texCoord + vec2(offset.x, -offset.y);
    texcoordOutNear[3].xy = a_texCoord + vec2(-offset.x, offset.y);
    texcoordOutNear[3].zw = a_texCoord + vec2(-offset.x, -offset.y);
    
    texcoordOutNear[4].xy = a_texCoord + vec2(2.0 * offset.x, 0);
    texcoordOutNear[4].zw = a_texCoord + vec2(-2.0 * offset.x, 0);
    texcoordOutNear[5].xy = a_texCoord + vec2(0, 2.0 * offset.y);
    texcoordOutNear[5].zw = a_texCoord + vec2(0, -2.0 * offset.y);
    
//    texcoordOutNear[6].xy = a_texCoord + vec2(2.0 * offset.x, 2.0 * offset.y);
//    texcoordOutNear[6].xy = a_texCoord + vec2(2.0 * offset.x, -2.0 * offset.y);
//    texcoordOutNear[7].xy = a_texCoord + vec2(-2.0 * offset.x, 2.0 * offset.y);
//    texcoordOutNear[7].zw = a_texCoord + vec2(-2.0 * offset.x, -2.0 * offset.y);
    
//    texcoordOutNear[8].xy = a_texCoord + vec2(2.0 * offset.x, offset.y);
//    texcoordOutNear[8].zw = a_texCoord + vec2(-2.0 * offset.x, offset.y);
//    texcoordOutNear[9].xy = a_texCoord + vec2(offset.x, 2.0 * offset.y);
//    texcoordOutNear[9].zw = a_texCoord + vec2(-offset.x, 2.0 * offset.y);
    
//    texcoordOutNear[10].xy = a_texCoord + vec2(2.0 * offset.x, -offset.y);
//    texcoordOutNear[10].zw = a_texCoord + vec2(-2.0 * offset.x, -offset.y);
//    texcoordOutNear[11].xy = a_texCoord + vec2(offset.x, -2.0 * offset.y);
//    texcoordOutNear[11].zw = a_texCoord + vec2(-offset.x, -2.0 * offset.y);

}
