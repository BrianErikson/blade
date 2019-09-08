
#include "primitives.h"

BldMesh bld_mesh_plane_create()
{
    static const GLfloat vd[] = {
        -1.0f, -1.0f,
        1.0f, -1.0f,
        -1.0f, 1.0f,
        1.0f, 1.0f
    };
    static const GLushort ed[] = {0, 1, 2, 3};

    return bld_mesh_create(vd, sizeof(vd), ed, sizeof(ed), GL_STATIC_DRAW);
}
