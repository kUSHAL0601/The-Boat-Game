#include "health_gift.h"

#include "main.h"

//color_t COLOR_HEART={255, 255, 0};
color_t COLOR_BARREL1={0,0,0};

HGift::HGift(float x, float y) {
    this->position = glm::vec3(x, 0, y);
    this->rotation = 0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        //Central part
        -2.0f,-0.5f,-1.0f, // triangle 1 : begin
        -2.0f,-0.5f, 1.0f,
        -2.0f, 0.5f, 1.0f, // triangle 1 : end
        2.0f, 0.5f,-1.0f, // triangle 2 : begin
        -2.0f,-0.5f,-1.0f,
        -2.0f, 0.5f,-1.0f, // triangle 2 : end
        2.0f,-0.5f, 1.0f,
        -2.0f,-0.5f,-1.0f,
        2.0f,-0.5f,-1.0f,
        2.0f, 0.5f,-1.0f,
        2.0f,-0.5f,-1.0f,
        -2.0f,-0.5f,-1.0f,
        -2.0f,-0.5f,-1.0f,
        -2.0f, 0.5f, 1.0f,
        -2.0f, 0.5f,-1.0f,
        2.0f,-0.5f, 1.0f,
        -2.0f,-0.5f, 1.0f,
        -2.0f,-0.5f,-1.0f,
        -2.0f, 0.5f, 1.0f,
        -2.0f,-0.5f, 1.0f,
        2.0f,-0.5f, 1.0f,
        2.0f, 0.5f, 1.0f,
        2.0f,-0.5f,-1.0f,
        2.0f, 0.5f,-1.0f,
        2.0f,-0.5f,-1.0f,
        2.0f, 0.5f, 1.0f,
        2.0f,-0.5f, 1.0f,
        2.0f, 0.5f, 1.0f,
        2.0f, 0.5f,-1.0f,
        -2.0f, 0.5f,-1.0f,
        2.0f, 0.5f, 1.0f,
        -2.0f, 0.5f,-1.0f,
        -2.0f, 0.5f, 1.0f,
        2.0f, 0.5f, 1.0f,
        -2.0f, 0.5f, 1.0f,
        2.0f,-0.5f, 1.0f
    };

    static const GLfloat pyramids[] = {
        //tri1
        -1.5f,3.7f,0.0f,
        1.5f,3.7f,0.0f,
        0.0f,0.7f,0.0f,
        //tri2
        -1.5f,3.7f,0.0f,
        0.0f,3.7f,0.0f,
        -0.75f,4.7f,0.0f,
        //tri3
        1.5f,3.7f,0.0f,
        0.0f,3.7f,0.0f,
        0.75f,4.7f,0.0f,
        //rect1
        -1.5f,3.7f,0.0f,
        -1.5f,3.7f,0.3f,
        0.0f,0.7f,0.0f,
        0.0f,0.7f,0.3f,
        -1.5f,3.7f,0.0f,
        0.0f,0.7f,0.0f,
        //rect2
        1.5f,3.7f,0.0f,
        1.5f,3.7f,0.3f,
        0.0f,0.7f,0.0f,
        0.0f,0.7f,0.3f,
        1.5f,3.7f,0.0f,
        0.0f,0.7f,0.0f,
        //rect3
        -1.5f,3.7f,0.0f,
        -1.5f,3.7f,0.3f,
        -0.75f,4.7f,0.0f,
        -0.75f,4.7f,0.3f,
        -1.5f,3.7f,0.3f,
        -0.75f,4.7f,0.0f,
        //rect4
        0.0f,3.7f,0.0f,
        0.0f,3.7f,0.3f,
        -0.75f,4.7f,0.0f,
        -0.75f,4.7f,0.3f,
        0.0f,3.7f,0.3f,
        -0.75f,4.7f,0.0f,
        //rect5
        1.5f,3.7f,0.0f,
        1.5f,3.7f,0.3f,
        0.75f,4.7f,0.0f,
        0.75f,4.7f,0.3f,
        1.5f,3.7f,0.3f,
        0.75f,4.7f,0.0f,
        //rect6
        0.0f,3.7f,0.0f,
        0.0f,3.7f,0.3f,
        0.75f,4.7f,0.0f,
        0.75f,4.7f,0.3f,
        0.0f,3.7f,0.3f,
        0.75f,4.7f,0.0f,
    };

    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, COLOR_BARREL1, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 15*3, pyramids, COLOR_RED, GL_FILL);
    this->bounding_box.x=this->position.x;
    this->bounding_box.y=this->position.y;
    this->bounding_box.width=3.0f;
    this->bounding_box.height=4.7f;
}

void HGift::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    Matrices.model = glm::mat4(1.0f);
    translate = glm::translate (this->position);    // glTranslatef
    Matrices.model *= (translate);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    this->bounding_box.x=this->position.x;
    this->bounding_box.y=this->position.y;
}

void HGift::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

void HGift::tick() {
    this->rotation+=1.0;
    if(this->rotation>=360)
        this->rotation=0.0;
}
