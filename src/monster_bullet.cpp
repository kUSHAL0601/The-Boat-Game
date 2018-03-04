#include "monster_bullet.h"
#include "main.h"

MBullet::MBullet(float x, float y, color_t color,float rotation) {
    this->position = glm::vec3(x, 0, y);
    this->rotation = rotation;
    this->initx=x;
    this->initz=y;
    speed = 1;
    this->factor=1.0;
    if(y>0)
        this->factor=-1.0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        1.0f,1.2f,0.8*this->factor, // triangle 1 : begin
        1.0f,1.2f, 1.2*this->factor,
        1.0f, 1.4f, 1.2*this->factor, // triangle 1 : end
        1.5f, 1.4f,0.8*this->factor, // triangle 2 : begin
        1.0f,1.2f,0.8*this->factor,
        1.0f, 1.4f,0.8*this->factor, // triangle 2 : end
        1.5f,1.2f, 1.2*this->factor,
        1.0f,1.2f,0.8*this->factor,
        1.5f,1.2f,0.8*this->factor,
        1.5f, 1.4f,0.8*this->factor,
        1.5f,1.2f,0.8*this->factor,
        1.0f,1.2f,0.8*this->factor,
        1.0f,1.2f,0.8*this->factor,
        1.0f, 1.4f, 1.2*this->factor,
        1.0f, 1.4f,0.8*this->factor,
        1.5f,1.2f, 1.2*this->factor,
        1.0f,1.2f, 1.2*this->factor,
        1.0f,1.2f,0.8*this->factor,
        1.0f, 1.4f, 1.2*this->factor,
        1.0f,1.2f, 1.2*this->factor,
        1.5f,1.2f, 1.2*this->factor,
        1.5f, 1.4f, 1.2*this->factor,
        1.5f,1.2f,0.8*this->factor,
        1.5f, 1.4f,0.8*this->factor,
        1.5f,1.2f,0.8*this->factor,
        1.5f, 1.4f, 1.2*this->factor,
        1.5f,1.2f, 1.2*this->factor,
        1.5f, 1.4f, 1.2*this->factor,
        1.5f, 1.4f,0.8*this->factor,
        1.0f, 1.4f,0.8*this->factor,
        1.5f, 1.4f, 1.2*this->factor,
        1.0f, 1.4f,0.8*this->factor,
        1.0f, 1.4f, 1.2*this->factor,
        1.5f, 1.4f, 1.2*this->factor,
        1.0f, 1.4f, 1.2*this->factor,
        1.5f,1.2f, 1.2*this->factor,
        //Canon2
        -1.0f,1.2f,0.8*this->factor, // triangle 1 : begin
        -1.0f,1.2f, 1.2*this->factor,
        -1.0f, 1.4f, 1.2*this->factor, // triangle 1 : end
        -1.5f, 1.4f,0.8*this->factor, // triangle 2 : begin
        -1.0f,1.2f,0.8*this->factor,
        -1.0f, 1.4f,0.8*this->factor, // triangle 2 : end
        -1.5f,1.2f, 1.2*this->factor,
        -1.0f,1.2f,0.8*this->factor,
        -1.5f,1.2f,0.8*this->factor,
        -1.5f, 1.4f,0.8*this->factor,
        -1.5f,1.2f,0.8*this->factor,
        -1.0f,1.2f,0.8*this->factor,
        -1.0f,1.2f,0.8*this->factor,
        -1.0f, 1.4f, 1.2*this->factor,
        -1.0f, 1.4f,0.8*this->factor,
        -1.5f,1.2f, 1.2*this->factor,
        -1.0f,1.2f, 1.2*this->factor,
        -1.0f,1.2f,0.8*this->factor,
        -1.0f, 1.4f, 1.2*this->factor,
        -1.0f,1.2f, 1.2*this->factor,
        -1.5f,1.2f, 1.2*this->factor,
        -1.5f, 1.4f, 1.2*this->factor,
        -1.5f,1.2f,0.8*this->factor,
        -1.5f, 1.4f,0.8*this->factor,
        -1.5f,1.2f,0.8*this->factor,
        -1.5f, 1.4f, 1.2*this->factor,
        -1.5f,1.2f, 1.2*this->factor,
        -1.5f, 1.4f, 1.2*this->factor,
        -1.5f, 1.4f,0.8*this->factor,
        -1.0f, 1.4f,0.8*this->factor,
        -1.5f, 1.4f, 1.2*this->factor,
        -1.0f, 1.4f,0.8*this->factor,
        -1.0f, 1.4f, 1.2*this->factor,
        -1.5f, 1.4f, 1.2*this->factor,
        -1.0f, 1.4f, 1.2*this->factor,
        -1.5f,1.2f, 1.2*this->factor
    };
    this->bounding_box.x=this->position.x;
    this->bounding_box.y=this->position.z;
    this->bounding_box.width=1.0;
    this->bounding_box.height=0.8;
    this->object = create3DObject(GL_TRIANGLES, 24*3, vertex_buffer_data, color, GL_FILL);
}

void MBullet::draw(glm::mat4 VP) {
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

void MBullet::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void MBullet::tick() {
}
