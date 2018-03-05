#include "island.h"
#include "main.h"

Island::Island(float x, float y, color_t color) {
    this->position = glm::vec3(x, 0, y);
    this->rotation = 0;
    color_t COLOR_TREASURE={204, 153, 255};
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        0.0,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0),0.0f,
        -16.0f,0.0f,-16.0*tan(M_PI/6.0),
        16.0f,0.0f,-16.0*tan(M_PI/6.0),

    };
    static const GLfloat vertex_buffer_data1[] = {
        0.0,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0),0.0f,
        -16.0f,0.0f,-16.0*tan(M_PI/6.0),
        0.0f,0.0f,32.0*cos(M_PI/6.0)-16.0*tan(M_PI/6.0),

    };
    static const GLfloat vertex_buffer_data2[] = {
        0.0,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0),0.0f,
        0.0f,0.0f,32.0*cos(M_PI/6.0)-16.0*tan(M_PI/6.0),
        16.0f,0.0f,-16.0*tan(M_PI/6.0),
    };
    static const GLfloat treasure[] = {
        -1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f,-1.0f, // triangle 1 : begin
        -1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f, 1.0f,
        -1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f, 1.0f, // triangle 1 : end
        1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f,-1.0f, // triangle 2 : begin
        -1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f,-1.0f,
        -1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f,-1.0f, // triangle 2 : end
        1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f, 1.0f,
        -1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f,-1.0f,
        1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f,-1.0f,
        1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f,-1.0f,
        1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f,-1.0f,
        -1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f,-1.0f,
        -1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f,-1.0f,
        -1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f, 1.0f,
        -1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f,-1.0f,
        1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f, 1.0f,
        -1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f, 1.0f,
        -1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f,-1.0f,
        -1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f, 1.0f,
        -1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f, 1.0f,
        1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f, 1.0f,
        1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f, 1.0f,
        1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f,-1.0f,
        1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f,-1.0f,
        1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f,-1.0f,
        1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f, 1.0f,
        1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f, 1.0f,
        1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f, 1.0f,
        1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f,-1.0f,
        -1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f,-1.0f,
        1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f, 1.0f,
        -1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f,-1.0f,
        -1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f, 1.0f,
        1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f, 1.0f,
        -1.0f, 32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+1.1f, 1.0f,
        1.0f,32.0f*cos(M_PI/6.0)*cos(M_PI/3.0)+0.1f, 1.0f
    };
    this->bounding_box.x=this->position.x;
    this->bounding_box.y=this->position.z;
    this->bounding_box.width=2.0;
    this->bounding_box.height=2.0;
    this->object = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data1, COLOR_BLACK, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data2, COLOR_RED, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 12*3, treasure, COLOR_TREASURE, GL_FILL);
}

void Island::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    Matrices.model = glm::mat4(1.0f);
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    Matrices.model *= (translate * rotate);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object3);
    this->bounding_box.x=this->position.x;
    this->bounding_box.y=this->position.z;
}

void Island::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Island::tick() {
    this->rotation+=1.0;
    if(this->rotation>=360)
        this->rotation=0.0;
}
