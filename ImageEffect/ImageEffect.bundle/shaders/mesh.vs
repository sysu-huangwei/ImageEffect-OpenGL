attribute vec2 a_position;
attribute vec2 a_position_std;
varying vec2 texcoordOut;

void main()
{
   texcoordOut = a_position_std;
   gl_Position = vec4(a_position * 2.0 - 1.0, 0.0, 1.0);
}
