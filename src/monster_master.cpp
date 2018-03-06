#include "monster_master.h"
#include "main.h"

MMonster::MMonster(float x, float y, color_t color) {
    this->position = glm::vec3(x, 0, y);
    this->health=100.0;
    this->rotation = 0;
    speed = 1;
    float factor=1.0;
    if(y>0)
        factor=-1.0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        -2.0f,-2.0f,-2.0f, // triangle 1 : begin
        -2.0f,-2.0f, 2.0f,
        -2.0f, 6.0f, 2.0f, // triangle 1 : end
        2.0f, 6.0f,-2.0f, // triangle 2 : begin
        -2.0f,-2.0f,-2.0f,
        -2.0f, 6.0f,-2.0f, // triangle 2 : end
        2.0f,-2.0f, 2.0f,
        -2.0f,-2.0f,-2.0f,
        2.0f,-2.0f,-2.0f,
        2.0f, 6.0f,-2.0f,
        2.0f,-2.0f,-2.0f,
        -2.0f,-2.0f,-2.0f,
        -2.0f,-2.0f,-2.0f,
        -2.0f, 6.0f, 2.0f,
        -2.0f, 6.0f,-2.0f,
        2.0f,-2.0f, 2.0f,
        -2.0f,-2.0f, 2.0f,
        -2.0f,-2.0f,-2.0f,
        -2.0f, 6.0f, 2.0f,
        -2.0f,-2.0f, 2.0f,
        2.0f,-2.0f, 2.0f,
        2.0f, 6.0f, 2.0f,
        2.0f,-2.0f,-2.0f,
        2.0f, 6.0f,-2.0f,
        2.0f,-2.0f,-2.0f,
        2.0f, 6.0f, 2.0f,
        2.0f,-2.0f, 2.0f,
        2.0f, 6.0f, 2.0f,
        2.0f, 6.0f,-2.0f,
        -2.0f, 6.0f,-2.0f,
        2.0f, 6.0f, 2.0f,
        -2.0f, 6.0f,-2.0f,
        -2.0f, 6.0f, 2.0f,
        2.0f, 6.0f, 2.0f,
        -2.0f, 6.0f, 2.0f,
        2.0f,-2.0f, 2.0f

    };

    static const GLfloat eyes[]= {
        //eye1
        -1.6f,4.2f,1.6*factor, // triangle 1 : begin
        -1.6f,4.2f, 2.4*factor,
        -1.6f, 2.3f, 2.4*factor, // triangle 1 : end
        -1.2f, 2.3f,1.6*factor, // triangle 2 : begin
        -1.6f,4.2f,1.6*factor,
        -1.6f, 2.3f,1.6*factor, // triangle 2 : end
        -1.2f,4.2f, 2.4*factor,
        -1.6f,4.2f,1.6*factor,
        -1.2f,4.2f,1.6*factor,
        -1.2f, 2.3f,1.6*factor,
        -1.2f,4.2f,1.6*factor,
        -1.6f,4.2f,1.6*factor,
        -1.6f,4.2f,1.6*factor,
        -1.6f, 2.3f, 2.4*factor,
        -1.6f, 2.3f,1.6*factor,
        -1.2f,4.2f, 2.4*factor,
        -1.6f,4.2f, 2.4*factor,
        -1.6f,4.2f,1.6*factor,
        -1.6f, 2.3f, 2.4*factor,
        -1.6f,4.2f, 2.4*factor,
        -1.2f,4.2f, 2.4*factor,
        -1.2f, 2.3f, 2.4*factor,
        -1.2f,4.2f,1.6*factor,
        -1.2f, 2.3f,1.6*factor,
        -1.2f,4.2f,1.6*factor,
        -1.2f, 2.3f, 2.4*factor,
        -1.2f,4.2f, 2.4*factor,
        -1.2f, 2.3f, 2.4*factor,
        -1.2f, 2.3f,1.6*factor,
        -1.6f, 2.3f,1.6*factor,
        -1.2f, 2.3f, 2.4*factor,
        -1.6f, 2.3f,1.6*factor,
        -1.6f, 2.3f, 2.4*factor,
        -1.2f, 2.3f, 2.4*factor,
        -1.6f, 2.3f, 2.4*factor,
        -1.2f,4.2f, 2.4*factor,

        1.6f,4.2f,1.6*factor, // triangle 1 : begin
        1.6f,4.2f, 2.4*factor,
        1.6f, 2.3f, 2.4*factor, // triangle 1 : end
        1.2f, 2.3f,1.6*factor, // triangle 2 : begin
        1.6f,4.2f,1.6*factor,
        1.6f, 2.3f,1.6*factor, // triangle 2 : end
        1.2f,4.2f, 2.4*factor,
        1.6f,4.2f,1.6*factor,
        1.2f,4.2f,1.6*factor,
        1.2f, 2.3f,1.6*factor,
        1.2f,4.2f,1.6*factor,
        1.6f,4.2f,1.6*factor,
        1.6f,4.2f,1.6*factor,
        1.6f, 2.3f, 2.4*factor,
        1.6f, 2.3f,1.6*factor,
        1.2f,4.2f, 2.4*factor,
        1.6f,4.2f, 2.4*factor,
        1.6f,4.2f,1.6*factor,
        1.6f, 2.3f, 2.4*factor,
        1.6f,4.2f, 2.4*factor,
        1.2f,4.2f, 2.4*factor,
        1.2f, 2.3f, 2.4*factor,
        1.2f,4.2f,1.6*factor,
        1.2f, 2.3f,1.6*factor,
        1.2f,4.2f,1.6*factor,
        1.2f, 2.3f, 2.4*factor,
        1.2f,4.2f, 2.4*factor,
        1.2f, 2.3f, 2.4*factor,
        1.2f, 2.3f,1.6*factor,
        1.6f, 2.3f,1.6*factor,
        1.2f, 2.3f, 2.4*factor,
        1.6f, 2.3f,1.6*factor,
        1.6f, 2.3f, 2.4*factor,
        1.2f, 2.3f, 2.4*factor,
        1.6f, 2.3f, 2.4*factor,
        1.2f,4.2f, 2.4*factor

    };

    static const GLfloat canons[] = {
        //Canon1
        2.0f,1.2f,1.6*factor, // triangle 1 : begin
        2.0f,1.2f, 6.0*factor,
        2.0f, 1.4f, 6.0*factor, // triangle 1 : end
        3.0f, 1.4f,1.6*factor, // triangle 2 : begin
        2.0f,1.2f,1.6*factor,
        2.0f, 1.4f,1.6*factor, // triangle 2 : end
        3.0f,1.2f, 6.0*factor,
        2.0f,1.2f,1.6*factor,
        3.0f,1.2f,1.6*factor,
        3.0f, 1.4f,1.6*factor,
        3.0f,1.2f,1.6*factor,
        2.0f,1.2f,1.6*factor,
        2.0f,1.2f,1.6*factor,
        2.0f, 1.4f, 6.0*factor,
        2.0f, 1.4f,1.6*factor,
        3.0f,1.2f, 6.0*factor,
        2.0f,1.2f, 6.0*factor,
        2.0f,1.2f,1.6*factor,
        2.0f, 1.4f, 6.0*factor,
        2.0f,1.2f, 6.0*factor,
        3.0f,1.2f, 6.0*factor,
        3.0f, 1.4f, 6.0*factor,
        3.0f,1.2f,1.6*factor,
        3.0f, 1.4f,1.6*factor,
        3.0f,1.2f,1.6*factor,
        3.0f, 1.4f, 6.0*factor,
        3.0f,1.2f, 6.0*factor,
        3.0f, 1.4f, 6.0*factor,
        3.0f, 1.4f,1.6*factor,
        2.0f, 1.4f,1.6*factor,
        3.0f, 1.4f, 6.0*factor,
        2.0f, 1.4f,1.6*factor,
        2.0f, 1.4f, 6.0*factor,
        3.0f, 1.4f, 6.0*factor,
        2.0f, 1.4f, 6.0*factor,
        3.0f,1.2f, 6.0*factor,
        //Canon2
        -2.0f,1.2f,1.6*factor, // triangle 1 : begin
        -2.0f,1.2f, 6.0*factor,
        -2.0f, 1.4f, 6.0*factor, // triangle 1 : end
        -3.0f, 1.4f,1.6*factor, // triangle 2 : begin
        -2.0f,1.2f,1.6*factor,
        -2.0f, 1.4f,1.6*factor, // triangle 2 : end
        -3.0f,1.2f, 6.0*factor,
        -2.0f,1.2f,1.6*factor,
        -3.0f,1.2f,1.6*factor,
        -3.0f, 1.4f,1.6*factor,
        -3.0f,1.2f,1.6*factor,
        -2.0f,1.2f,1.6*factor,
        -2.0f,1.2f,1.6*factor,
        -2.0f, 1.4f, 6.0*factor,
        -2.0f, 1.4f,1.6*factor,
        -3.0f,1.2f, 6.0*factor,
        -2.0f,1.2f, 6.0*factor,
        -2.0f,1.2f,1.6*factor,
        -2.0f, 1.4f, 6.0*factor,
        -2.0f,1.2f, 6.0*factor,
        -3.0f,1.2f, 6.0*factor,
        -3.0f, 1.4f, 6.0*factor,
        -3.0f,1.2f,1.6*factor,
        -3.0f, 1.4f,1.6*factor,
        -3.0f,1.2f,1.6*factor,
        -3.0f, 1.4f, 6.0*factor,
        -3.0f,1.2f, 6.0*factor,
        -3.0f, 1.4f, 6.0*factor,
        -3.0f, 1.4f,1.6*factor,
        -2.0f, 1.4f,1.6*factor,
        -3.0f, 1.4f, 6.0*factor,
        -2.0f, 1.4f,1.6*factor,
        -2.0f, 1.4f, 6.0*factor,
        -3.0f, 1.4f, 6.0*factor,
        -2.0f, 1.4f, 6.0*factor,
        -3.0f,1.2f, 6.0*factor

    };

    this->bounding_box.x=this->position.x;
    this->bounding_box.y=this->position.z;
    this->bounding_box.width=4.0;
    this->bounding_box.height=4.0;
    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 24*3, canons, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 24*3, eyes, COLOR_GREEN, GL_FILL);
}

void MMonster::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -1.2, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    this->bounding_box.x=this->position.x;
    this->bounding_box.y=this->position.z;
}

void MMonster::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void MMonster::tick() {
}
