#pragma once

namespace fw {

class vec2
{
public:
    vec2() { x = 0; y = 0; }
    vec2(float nx, float ny) { x = nx; y = ny; }

public:
    float x;
    float y;
};

} // namespace fw
