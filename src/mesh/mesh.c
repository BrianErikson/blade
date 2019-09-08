#include "mesh.h"

BldMesh bld_mesh_create(const void *vertex_data, GLsizei vertex_data_size,
                        const void *element_data, GLsizei element_data_size, GLenum buffer_type)
{
    GLuint bufs[2];
    glGenBuffers(2, bufs);

    glBindBuffer(GL_ARRAY_BUFFER, bufs[0]);
    glBufferData(GL_ARRAY_BUFFER, vertex_data_size, vertex_data, buffer_type);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufs[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, element_data_size, element_data, GL_STATIC_DRAW);

    BldMesh result = {.vertex_data = vertex_data, .vertex_buf_size = vertex_data_size, .vertex_buf_type = buffer_type,
        .element_data = element_data, .element_buf_size = element_data_size};
    return result;
}
