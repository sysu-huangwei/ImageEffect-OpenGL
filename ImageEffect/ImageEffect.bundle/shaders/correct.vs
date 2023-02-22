attribute vec2 a_position;
attribute vec2 a_texCoord;
varying vec2 texcoordOut;
uniform vec2 correctFactor;

void main()
{
    texcoordOut = a_texCoord;
    vec2 position = a_position * correctFactor;
    gl_Position = vec4(clamp(position, -1.0, 1.0), 0.0, 1.0);
}
