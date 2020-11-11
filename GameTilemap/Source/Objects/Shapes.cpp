#include "GamePCH.h"
#include "Shapes.h"

const fw::VertexFormat meshAttribs_Human[] =
{
    -0.25f,  -0.25f,    0, 0,
     0.25f,   0.25f,    1, 1,
     0.25f,  -0.25f,    1, 0,
};
const int meshPrimType_Human = GL_TRIANGLES;
const int meshNumVerts_Human = sizeof(meshAttribs_Human) / (sizeof(fw::VertexFormat));

const fw::VertexFormat meshAttribs_Enemy[] =
{
    0.0f, 0.0f,    0, 0,
};
const int meshPrimType_Enemy = GL_POINTS;
const int meshNumVerts_Enemy = sizeof(meshAttribs_Enemy) / (sizeof(fw::VertexFormat));
