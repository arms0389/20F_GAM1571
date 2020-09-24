
attribute vec2 a_Position;

void main()
{
    vec2 pos = a_Position;

    gl_Position = vec4( pos, 0, 1 );
}
