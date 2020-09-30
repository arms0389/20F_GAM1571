#include "GamePCH.h"

float meshAttribs_Human[] =
{
    -0.25f,  -0.25f,
     0.25f,   0.25f,
     0.25f,  -0.25f,
};
int meshPrimType_Human = GL_TRIANGLES;
int meshNumVerts_Human = sizeof(meshAttribs_Human) / (sizeof(float) * 2);

float meshAttribs_Enemy[] =
{
    0.0f, 0.0f,
};
int meshPrimType_Enemy = GL_POINTS;
int meshNumVerts_Enemy = sizeof(meshAttribs_Enemy) / (sizeof(float) * 2);
