#ifndef BLADE_MESH_H
#define BLADE_MESH_H

#include <GL/glew.h>

typedef struct
{
    const GLuint *vertex_data, *element_data;
    const GLsizei vertex_buf_size, element_buf_size;
    const GLenum vertex_buf_type; // elements are always GL_STATIC_DRAW, for now...
    GLuint vertex_buffer, element_buffer;
    GLuint textures[2];
} BldMesh;

BldMesh bld_mesh_create(const void *vertex_data, GLsizei vertex_data_size,
                        const void *element_data, GLsizei element_data_size, GLenum buffer_type);

#endif //BLADE_MESH_H