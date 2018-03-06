#include "magnet.h"
#include "main.h"

Magnet::Magnet(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    static const GLfloat vertex_buffer_data[] = {
        -0.15,0.4,0,//top1
        -0.15,0.7,0,
        1.3,0.7,0,

        -0.15,0.4,0,//top2
        1.3,0.7,0,
        1.3,0.4,0,

        -0.15,-0.4,0,//bottom1
        -0.15,-0.7,0,
        1.3,-0.7,0,

        -0.15,-0.4,0,//bottom2
        1.3,-0.7,0,
        1.3,-0.4,0,

        -0.15,0.4,0,//mid1
        0.15,0.4,0,
        -0.15,-0.4,0,

        0.15,-0.4,0,//mid2
        0.15,0.4,0,
        -0.15,-0.4,0,

        0.15,0.4,0,
        0.24,0.4,0,
        0.15,0.3,0,

        0.15,-0.4,0,
        0.24,-0.4,0,
        0.15,-0.3,0,

    };

    this->object = create3DObject(GL_TRIANGLES, 24, vertex_buffer_data, color, GL_FILL);
}

void Magnet::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.3f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Magnet::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

bounding_box_t Magnet::bounding_box() {
    float x = this->position.x, y = this->position.y;
    bounding_box_t bbox = { x, y, 8.0, 8.0 };
    return bbox;
}
