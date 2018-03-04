#include "water.h"
#include "main.h"
#include <limits.h>

color_t COLOR_WATER={0,134,219};

Water::Water(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        -1000.0f,-1000.0f,-1000.0f, // triangle 1 : begin
        -1000.0f,-1000.0f, 1000.0f,
        -1000.0f, 0.0f, 1000.0f, // triangle 1 : end
        1000.0f, 0.0f,-1000.0f, // triangle 2 : begin
        -1000.0f,-1000.0f,-1000.0f,
        -1000.0f, 0.0f,-1000.0f, // triangle 2 : end
        1000.0f,-1000.0f, 1000.0f,
        -1000.0f,-1000.0f,-1000.0f,
        1000.0f,-1000.0f,-1000.0f,
        1000.0f, 0.0f,-1000.0f,
        1000.0f,-1000.0f,-1000.0f,
        -1000.0f,-1000.0f,-1000.0f,
        -1000.0f,-1000.0f,-1000.0f,
        -1000.0f, 0.0f, 1000.0f,
        -1000.0f, 0.0f,-1000.0f,
        1000.0f,-1000.0f, 1000.0f,
        -1000.0f,-1000.0f, 1000.0f,
        -1000.0f,-1000.0f,-1000.0f,
        -1000.0f, 0.0f, 1000.0f,
        -1000.0f,-1000.0f, 1000.0f,
        1000.0f,-1000.0f, 1000.0f,
        1000.0f, 0.0f, 1000.0f,
        1000.0f,-1000.0f,-1000.0f,
        1000.0f, 0.0f,-1000.0f,
        1000.0f,-1000.0f,-1000.0f,
        1000.0f, 0.0f, 1000.0f,
        1000.0f,-1000.0f, 1000.0f,
        1000.0f, 0.0f, 1000.0f,
        1000.0f, 0.0f,-1000.0f,
        -1000.0f, 0.0f,-1000.0f,
        1000.0f, 0.0f, 1000.0f,
        -1000.0f, 0.0f,-1000.0f,
        -1000.0f, 0.0f, 1000.0f,
        1000.0f, 0.0f, 1000.0f,
        -1000.0f, 0.0f, 1000.0f,
        1000.0f,-1000.0f, 1000.0f
//        1000.0f,0.0f,1000.0f,
//        -1000.0f,0.0f,-1000.0f,
//        1000.0f,0.0f,-1000.0f,
//        1000.0f,0.0f,1000.0f,
//        -1000.0f,0.0f,-1000.0f,
//        -1000.0f,0.0f,1000.0f
    };

    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, COLOR_WATER, GL_FILL);
}

void Water::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= translate;
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}
