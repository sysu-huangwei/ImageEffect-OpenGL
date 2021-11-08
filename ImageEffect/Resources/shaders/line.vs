attribute vec2 a_position;

void main()
{
    gl_PointSize = 5.0;
    gl_Position = vec4(a_position * 2.0 - 1.0, 0.0, 1.0);
}
