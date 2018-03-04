#include "bullet.h"
#include "main.h"

Bullet::Bullet(float x, float y, color_t color,float rotation) {
    this->position = glm::vec3(x, 0, y);
    this->rotation = rotation;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        0.5f,1.2f,7.5f, // triangle 1 : begin
        0.5f,1.2f, 8.0f,
        0.5f, 1.4f, 8.0f, // triangle 1 : end
        1.0f, 1.4f,7.5f, // triangle 2 : begin
        0.5f,1.2f,7.5f,
        0.5f, 1.4f,7.5f, // triangle 2 : end
        1.0f,1.2f, 8.0f,
        0.5f,1.2f,7.5f,
        1.0f,1.2f,7.5f,
        1.0f, 1.4f,7.5f,
        1.0f,1.2f,7.5f,
        0.5f,1.2f,7.5f,
        0.5f,1.2f,7.5f,
        0.5f, 1.4f, 8.0f,
        0.5f, 1.4f,7.5f,
        1.0f,1.2f, 8.0f,
        0.5f,1.2f, 8.0f,
        0.5f,1.2f,7.5f,
        0.5f, 1.4f, 8.0f,
        0.5f,1.2f, 8.0f,
        1.0f,1.2f, 8.0f,
        1.0f, 1.4f, 8.0f,
        1.0f,1.2f,7.5f,
        1.0f, 1.4f,7.5f,
        1.0f,1.2f,7.5f,
        1.0f, 1.4f, 8.0f,
        1.0f,1.2f, 8.0f,
        1.0f, 1.4f, 8.0f,
        1.0f, 1.4f,7.5f,
        0.5f, 1.4f,7.5f,
        1.0f, 1.4f, 8.0f,
        0.5f, 1.4f,7.5f,
        0.5f, 1.4f, 8.0f,
        1.0f, 1.4f, 8.0f,
        0.5f, 1.4f, 8.0f,
        1.0f,1.2f, 8.0f,
        //Canon2
        -0.5f,1.2f,7.5f, // triangle 1 : begin
        -0.5f,1.2f, 8.0f,
        -0.5f, 1.4f, 8.0f, // triangle 1 : end
        -1.0f, 1.4f,7.5f, // triangle 2 : begin
        -0.5f,1.2f,7.5f,
        -0.5f, 1.4f,7.5f, // triangle 2 : end
        -1.0f,1.2f, 8.0f,
        -0.5f,1.2f,7.5f,
        -1.0f,1.2f,7.5f,
        -1.0f, 1.4f,7.5f,
        -1.0f,1.2f,7.5f,
        -0.5f,1.2f,7.5f,
        -0.5f,1.2f,7.5f,
        -0.5f, 1.4f, 8.0f,
        -0.5f, 1.4f,7.5f,
        -1.0f,1.2f, 8.0f,
        -0.5f,1.2f, 8.0f,
        -0.5f,1.2f,7.5f,
        -0.5f, 1.4f, 8.0f,
        -0.5f,1.2f, 8.0f,
        -1.0f,1.2f, 8.0f,
        -1.0f, 1.4f, 8.0f,
        -1.0f,1.2f,7.5f,
        -1.0f, 1.4f,7.5f,
        -1.0f,1.2f,7.5f,
        -1.0f, 1.4f, 8.0f,
        -1.0f,1.2f, 8.0f,
        -1.0f, 1.4f, 8.0f,
        -1.0f, 1.4f,7.5f,
        -0.5f, 1.4f,7.5f,
        -1.0f, 1.4f, 8.0f,
        -0.5f, 1.4f,7.5f,
        -0.5f, 1.4f, 8.0f,
        -1.0f, 1.4f, 8.0f,
        -0.5f, 1.4f, 8.0f,
        -1.0f,1.2f, 8.0f
    };
    this->bounding_box.x=this->position.x;
    this->bounding_box.y=this->position.z;
    this->bounding_box.width=2.0;
    this->bounding_box.height=2.0;
    this->object = create3DObject(GL_TRIANGLES, 24*3, vertex_buffer_data, color, GL_FILL);
}

void Bullet::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    this->bounding_box.x=this->position.x;
    this->bounding_box.y=this->position.z;
}

void Bullet::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Bullet::tick() {
}
