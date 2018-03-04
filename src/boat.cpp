#include "boat.h"

#include "main.h"

color_t COLOR_MAIN={175,64,30};
color_t COLOR_CANON={255, 204, 0};

Boat::Boat(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->rotationx = 0;
    speed=0.01;
    flag=0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        //Central part
        -1.5f,-1.0f,-2.5f, // triangle 1 : begin
        -1.5f,-1.0f, 2.5f,
        -1.5f, 1.0f, 2.5f, // triangle 1 : end
        1.5f, 1.0f,-2.5f, // triangle 2 : begin
        -1.5f,-1.0f,-2.5f,
        -1.5f, 1.0f,-2.5f, // triangle 2 : end
        1.5f,-1.0f, 2.5f,
        -1.5f,-1.0f,-2.5f,
        1.5f,-1.0f,-2.5f,
        1.5f, 1.0f,-2.5f,
        1.5f,-1.0f,-2.5f,
        -1.5f,-1.0f,-2.5f,
        -1.5f,-1.0f,-2.5f,
        -1.5f, 1.0f, 2.5f,
        -1.5f, 1.0f,-2.5f,
        1.5f,-1.0f, 2.5f,
        -1.5f,-1.0f, 2.5f,
        -1.5f,-1.0f,-2.5f,
        -1.5f, 1.0f, 2.5f,
        -1.5f,-1.0f, 2.5f,
        1.5f,-1.0f, 2.5f,
        1.5f, 1.0f, 2.5f,
        1.5f,-1.0f,-2.5f,
        1.5f, 1.0f,-2.5f,
        1.5f,-1.0f,-2.5f,
        1.5f, 1.0f, 2.5f,
        1.5f,-1.0f, 2.5f,
        1.5f, 1.0f, 2.5f,
        1.5f, 1.0f,-2.5f,
        -1.5f, 1.0f,-2.5f,
        1.5f, 1.0f, 2.5f,
        -1.5f, 1.0f,-2.5f,
        -1.5f, 1.0f, 2.5f,
        1.5f, 1.0f, 2.5f,
        -1.5f, 1.0f, 2.5f,
        1.5f,-1.0f, 2.5f
    };

    static const GLfloat pyramids[] = {
        //Pyramid1
        -1.5f,1.0f,2.5f,
        1.5f,1.0f,2.5f,
        0.0f,2.0f,7.0f,
//side rect1
        //tri1
        0.0f,2.0f,7.0f,
        1.5f,1.0f,2.5f,
        0.0f,1.0f,7.0f,
        //tri2
        1.5,-1.0f,2.5f,
        1.5f,1.0f,2.5f,
        0.0f,1.0f,7.0f,
//side rect2
        //tri1
        0.0f,2.0f,7.0f,
        -1.5f,1.0f,2.5f,
        0.0f,1.0f,7.0f,
        //tri2
        -1.5,-1.0f,2.5f,
        -1.5f,1.0f,2.5f,
        0.0f,1.0f,7.0f,

        //Pyramid2
        -1.5f,1.0f,-2.5f,
        1.5f,1.0f,-2.5f,
        0.0f,2.0f,-7.0f,
//side rect1
        //tri1
        0.0f,2.0f,-7.0f,
        1.5f,1.0f,-2.5f,
        0.0f,1.0f,-7.0f,
        //tri2
        1.5,-1.0f,-2.5f,
        1.5f,1.0f,-2.5f,
        0.0f,1.0f,-7.0f,
//side rect2
        //tri1
        0.0f,2.0f,-7.0f,
        -1.5f,1.0f,-2.5f,
        0.0f,1.0f,-7.0f,
        //tri2
        -1.5f,-1.0f,-2.5f,
        -1.5f,1.0f,-2.5f,
        0.0f,1.0f,-7.0f,
    };
    static const GLfloat canons[] = {
        //Canon1
        0.5f,1.2f,5.5f, // triangle 1 : begin
        0.5f,1.2f, 8.0f,
        0.5f, 1.4f, 8.0f, // triangle 1 : end
        1.0f, 1.4f,5.5f, // triangle 2 : begin
        0.5f,1.2f,5.5f,
        0.5f, 1.4f,5.5f, // triangle 2 : end
        1.0f,1.2f, 8.0f,
        0.5f,1.2f,5.5f,
        1.0f,1.2f,5.5f,
        1.0f, 1.4f,5.5f,
        1.0f,1.2f,5.5f,
        0.5f,1.2f,5.5f,
        0.5f,1.2f,5.5f,
        0.5f, 1.4f, 8.0f,
        0.5f, 1.4f,5.5f,
        1.0f,1.2f, 8.0f,
        0.5f,1.2f, 8.0f,
        0.5f,1.2f,5.5f,
        0.5f, 1.4f, 8.0f,
        0.5f,1.2f, 8.0f,
        1.0f,1.2f, 8.0f,
        1.0f, 1.4f, 8.0f,
        1.0f,1.2f,5.5f,
        1.0f, 1.4f,5.5f,
        1.0f,1.2f,5.5f,
        1.0f, 1.4f, 8.0f,
        1.0f,1.2f, 8.0f,
        1.0f, 1.4f, 8.0f,
        1.0f, 1.4f,5.5f,
        0.5f, 1.4f,5.5f,
        1.0f, 1.4f, 8.0f,
        0.5f, 1.4f,5.5f,
        0.5f, 1.4f, 8.0f,
        1.0f, 1.4f, 8.0f,
        0.5f, 1.4f, 8.0f,
        1.0f,1.2f, 8.0f,
        //Canon2
        -0.5f,1.2f,5.5f, // triangle 1 : begin
        -0.5f,1.2f, 8.0f,
        -0.5f, 1.4f, 8.0f, // triangle 1 : end
        -1.0f, 1.4f,5.5f, // triangle 2 : begin
        -0.5f,1.2f,5.5f,
        -0.5f, 1.4f,5.5f, // triangle 2 : end
        -1.0f,1.2f, 8.0f,
        -0.5f,1.2f,5.5f,
        -1.0f,1.2f,5.5f,
        -1.0f, 1.4f,5.5f,
        -1.0f,1.2f,5.5f,
        -0.5f,1.2f,5.5f,
        -0.5f,1.2f,5.5f,
        -0.5f, 1.4f, 8.0f,
        -0.5f, 1.4f,5.5f,
        -1.0f,1.2f, 8.0f,
        -0.5f,1.2f, 8.0f,
        -0.5f,1.2f,5.5f,
        -0.5f, 1.4f, 8.0f,
        -0.5f,1.2f, 8.0f,
        -1.0f,1.2f, 8.0f,
        -1.0f, 1.4f, 8.0f,
        -1.0f,1.2f,5.5f,
        -1.0f, 1.4f,5.5f,
        -1.0f,1.2f,5.5f,
        -1.0f, 1.4f, 8.0f,
        -1.0f,1.2f, 8.0f,
        -1.0f, 1.4f, 8.0f,
        -1.0f, 1.4f,5.5f,
        -0.5f, 1.4f,5.5f,
        -1.0f, 1.4f, 8.0f,
        -0.5f, 1.4f,5.5f,
        -0.5f, 1.4f, 8.0f,
        -1.0f, 1.4f, 8.0f,
        -0.5f, 1.4f, 8.0f,
        -1.0f,1.2f, 8.0f

    };

    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, COLOR_MAIN, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 10*3, pyramids, COLOR_MAIN, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 24*3, canons, COLOR_CANON, GL_FILL);
}

void Boat::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 rotatex    = glm::rotate((float) (this->rotationx * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotatex * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object2);
    draw3DObject(this->object);
    draw3DObject(this->object1);
}

void Boat::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

void Boat::tick(int move) {
//    printf("%f\n",this->rotationz);
    if(move)
    {
    if(this->rotationx>=10)
    {
        flag=1;
    }
    if(this->rotationx<=-4)
    {
        flag=0;
    }
    if(flag==0)
        this->rotationx+=0.2;
    else
        this->rotationx-=0.2;
    }
}