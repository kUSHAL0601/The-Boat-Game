#include "man.h"

#include "main.h"

color_t COLOR_TORSO={0,0,0};
color_t COLOR_HANDS={255, 230, 204};
color_t COLOR_FACE={255, 206, 153};
color_t COLOR_LEGS={255, 224, 102};

GLfloat vertex_buffer_data[] = {
    //Central part
    -0.4f,2.5f,2.5f, // triangle 1 : begin
    -0.4f,2.5f, 3.5f,
    -0.4f, 4.0f, 3.5f, // triangle 1 : end
    0.4f, 4.0f,2.5f, // triangle 2 : begin
    -0.4f,2.5f,2.5f,
    -0.4f, 4.0f,2.5f, // triangle 2 : end
    0.4f,2.5f, 3.5f,
    -0.4f,2.5f,2.5f,
    0.4f,2.5f,2.5f,
    0.4f, 4.0f,2.5f,
    0.4f,2.5f,2.5f,
    -0.4f,2.5f,2.5f,
    -0.4f,2.5f,2.5f,
    -0.4f, 4.0f, 3.5f,
    -0.4f, 4.0f,2.5f,
    0.4f,2.5f, 3.5f,
    -0.4f,2.5f, 3.5f,
    -0.4f,2.5f,2.5f,
    -0.4f, 4.0f, 3.5f,
    -0.4f,2.5f, 3.5f,
    0.4f,2.5f, 3.5f,
    0.4f, 4.0f, 3.5f,
    0.4f,2.5f,2.5f,
    0.4f, 4.0f,2.5f,
    0.4f,2.5f,2.5f,
    0.4f, 4.0f, 3.5f,
    0.4f,2.5f, 3.5f,
    0.4f, 4.0f, 3.5f,
    0.4f, 4.0f,2.5f,
    -0.4f, 4.0f,2.5f,
    0.4f, 4.0f, 3.5f,
    -0.4f, 4.0f,2.5f,
    -0.4f, 4.0f, 3.5f,
    0.4f, 4.0f, 3.5f,
    -0.4f, 4.0f, 3.5f,
    0.4f,2.5f, 3.5f
};
GLfloat head[] = {
    //Central part
    -0.4f,4.0f,2.5f, // triangle 1 : begin
    -0.4f,4.0f, 3.5f,
    -0.4f, 5.0f, 3.5f, // triangle 1 : end
    0.4f, 5.0f,2.5f, // triangle 2 : begin
    -0.4f,4.0f,2.5f,
    -0.4f, 5.0f,2.5f, // triangle 2 : end
    0.4f,4.0f, 3.5f,
    -0.4f,4.0f,2.5f,
    0.4f,4.0f,2.5f,
    0.4f, 5.0f,2.5f,
    0.4f,4.0f,2.5f,
    -0.4f,4.0f,2.5f,
    -0.4f,4.0f,2.5f,
    -0.4f, 5.0f, 3.5f,
    -0.4f, 5.0f,2.5f,
    0.4f,4.0f, 3.5f,
    -0.4f,4.0f, 3.5f,
    -0.4f,4.0f,2.5f,
    -0.4f, 5.0f, 3.5f,
    -0.4f,4.0f, 3.5f,
    0.4f,4.0f, 3.5f,
    0.4f, 5.0f, 3.5f,
    0.4f,4.0f,2.5f,
    0.4f, 5.0f,2.5f,
    0.4f,4.0f,2.5f,
    0.4f, 5.0f, 3.5f,
    0.4f,4.0f, 3.5f,
    0.4f, 5.0f, 3.5f,
    0.4f, 5.0f,2.5f,
    -0.4f, 5.0f,2.5f,
    0.4f, 5.0f, 3.5f,
    -0.4f, 5.0f,2.5f,
    -0.4f, 5.0f, 3.5f,
    0.4f, 5.0f, 3.5f,
    -0.4f, 5.0f, 3.5f,
    0.4f,4.0f, 3.5f
};

GLfloat legs[] = {
    //Central part
    -0.4f,1.0f,2.5f, // triangle 1 : begin
    -0.4f,1.0f, 3.5f,
    -0.4f, 2.5f, 3.5f, // triangle 1 : end
    -0.2f, 2.5f,2.5f, // triangle 2 : begin
    -0.4f,1.0f,2.5f,
    -0.4f, 2.5f,2.5f, // triangle 2 : end
    -0.2f,1.0f, 3.5f,
    -0.4f,1.0f,2.5f,
    -0.2f,1.0f,2.5f,
    -0.2f, 2.5f,2.5f,
    -0.2f,1.0f,2.5f,
    -0.4f,1.0f,2.5f,
    -0.4f,1.0f,2.5f,
    -0.4f, 2.5f, 3.5f,
    -0.4f, 2.5f,2.5f,
    -0.2f,1.0f, 3.5f,
    -0.4f,1.0f, 3.5f,
    -0.4f,1.0f,2.5f,
    -0.4f, 2.5f, 3.5f,
    -0.4f,1.0f, 3.5f,
    -0.2f,1.0f, 3.5f,
    -0.2f, 2.5f, 3.5f,
    -0.2f,1.0f,2.5f,
    -0.2f, 2.5f,2.5f,
    -0.2f,1.0f,2.5f,
    -0.2f, 2.5f, 3.5f,
    -0.2f,1.0f, 3.5f,
    -0.2f, 2.5f, 3.5f,
    -0.2f, 2.5f,2.5f,
    -0.4f, 2.5f,2.5f,
    -0.2f, 2.5f, 3.5f,
    -0.4f, 2.5f,2.5f,
    -0.4f, 2.5f, 3.5f,
    -0.2f, 2.5f, 3.5f,
    -0.4f, 2.5f, 3.5f,
    -0.2f,1.0f, 3.5f,

    0.4f,1.0f,2.5f, // triangle 1 : begin
    0.4f,1.0f, 3.5f,
    0.4f, 2.5f, 3.5f, // triangle 1 : end
    0.2f, 2.5f,2.5f, // triangle 2 : begin
    0.4f,1.0f,2.5f,
    0.4f, 2.5f,2.5f, // triangle 2 : end
    0.2f,1.0f, 3.5f,
    0.4f,1.0f,2.5f,
    0.2f,1.0f,2.5f,
    0.2f, 2.5f,2.5f,
    0.2f,1.0f,2.5f,
    0.4f,1.0f,2.5f,
    0.4f,1.0f,2.5f,
    0.4f, 2.5f, 3.5f,
    0.4f, 2.5f,2.5f,
    0.2f,1.0f, 3.5f,
    0.4f,1.0f, 3.5f,
    0.4f,1.0f,2.5f,
    0.4f, 2.5f, 3.5f,
    0.4f,1.0f, 3.5f,
    0.2f,1.0f, 3.5f,
    0.2f, 2.5f, 3.5f,
    0.2f,1.0f,2.5f,
    0.2f, 2.5f,2.5f,
    0.2f,1.0f,2.5f,
    0.2f, 2.5f, 3.5f,
    0.2f,1.0f, 3.5f,
    0.2f, 2.5f, 3.5f,
    0.2f, 2.5f,2.5f,
    0.4f, 2.5f,2.5f,
    0.2f, 2.5f, 3.5f,
    0.4f, 2.5f,2.5f,
    0.4f, 2.5f, 3.5f,
    0.2f, 2.5f, 3.5f,
    0.4f, 2.5f, 3.5f,
    0.2f,1.0f, 3.5f

};

GLfloat hands[] = {
    1.3f,3.8f,2.5f, // triangle 1 : begin
    1.3f,3.8f, 3.5f,
    1.3f, 4.0f, 3.5f, // triangle 1 : end
    0.4f, 4.0f,2.5f, // triangle 2 : begin
    1.3f,3.8f,2.5f,
    1.3f, 4.0f,2.5f, // triangle 2 : end
    0.4f,3.8f, 3.5f,
    1.3f,3.8f,2.5f,
    0.4f,3.8f,2.5f,
    0.4f, 4.0f,2.5f,
    0.4f,3.8f,2.5f,
    1.3f,3.8f,2.5f,
    1.3f,3.8f,2.5f,
    1.3f, 4.0f, 3.5f,
    1.3f, 4.0f,2.5f,
    0.4f,3.8f, 3.5f,
    1.3f,3.8f, 3.5f,
    1.3f,3.8f,2.5f,
    1.3f, 4.0f, 3.5f,
    1.3f,3.8f, 3.5f,
    0.4f,3.8f, 3.5f,
    0.4f, 4.0f, 3.5f,
    0.4f,3.8f,2.5f,
    0.4f, 4.0f,2.5f,
    0.4f,3.8f,2.5f,
    0.4f, 4.0f, 3.5f,
    0.4f,3.8f, 3.5f,
    0.4f, 4.0f, 3.5f,
    0.4f, 4.0f,2.5f,
    1.3f, 4.0f,2.5f,
    0.4f, 4.0f, 3.5f,
    1.3f, 4.0f,2.5f,
    1.3f, 4.0f, 3.5f,
    0.4f, 4.0f, 3.5f,
    1.3f, 4.0f, 3.5f,
    0.4f,3.8f, 3.5f,

    -1.3f,3.8f,2.5f, // triangle 1 : begin
    -1.3f,3.8f, 3.5f,
    -1.3f, 4.0f, 3.5f, // triangle 1 : end
    -0.4f, 4.0f,2.5f, // triangle 2 : begin
    -1.3f,3.8f,2.5f,
    -1.3f, 4.0f,2.5f, // triangle 2 : end
    -0.4f,3.8f, 3.5f,
    -1.3f,3.8f,2.5f,
    -0.4f,3.8f,2.5f,
    -0.4f, 4.0f,2.5f,
    -0.4f,3.8f,2.5f,
    -1.3f,3.8f,2.5f,
    -1.3f,3.8f,2.5f,
    -1.3f, 4.0f, 3.5f,
    -1.3f, 4.0f,2.5f,
    -0.4f,3.8f, 3.5f,
    -1.3f,3.8f, 3.5f,
    -1.3f,3.8f,2.5f,
    -1.3f, 4.0f, 3.5f,
    -1.3f,3.8f, 3.5f,
    -0.4f,3.8f, 3.5f,
    -0.4f, 4.0f, 3.5f,
    -0.4f,3.8f,2.5f,
    -0.4f, 4.0f,2.5f,
    -0.4f,3.8f,2.5f,
    -0.4f, 4.0f, 3.5f,
    -0.4f,3.8f, 3.5f,
    -0.4f, 4.0f, 3.5f,
    -0.4f, 4.0f,2.5f,
    -1.3f, 4.0f,2.5f,
    -0.4f, 4.0f, 3.5f,
    -1.3f, 4.0f,2.5f,
    -1.3f, 4.0f, 3.5f,
    -0.4f, 4.0f, 3.5f,
    -1.3f, 4.0f, 3.5f,
    -0.4f,3.8f, 3.5f

};
GLfloat eyes[]={
    -0.25f,4.65f,3.4f, // triangle 1 : begin
    -0.25f,4.65f, 3.6f,
    -0.25f, 4.85f, 3.6f, // triangle 1 : end
    -0.15f, 4.85f,3.4f, // triangle 2 : begin
    -0.25f,4.65f,3.4f,
    -0.25f, 4.85f,3.4f, // triangle 2 : end
    -0.15f,4.65f, 3.6f,
    -0.25f,4.65f,3.4f,
    -0.15f,4.65f,3.4f,
    -0.15f, 4.85f,3.4f,
    -0.15f,4.65f,3.4f,
    -0.25f,4.65f,3.4f,
    -0.25f,4.65f,3.4f,
    -0.25f, 4.85f, 3.6f,
    -0.25f, 4.85f,3.4f,
    -0.15f,4.65f, 3.6f,
    -0.25f,4.65f, 3.6f,
    -0.25f,4.65f,3.4f,
    -0.25f, 4.85f, 3.6f,
    -0.25f,4.65f, 3.6f,
    -0.15f,4.65f, 3.6f,
    -0.15f, 4.85f, 3.6f,
    -0.15f,4.65f,3.4f,
    -0.15f, 4.85f,3.4f,
    -0.15f,4.65f,3.4f,
    -0.15f, 4.85f, 3.6f,
    -0.15f,4.65f, 3.6f,
    -0.15f, 4.85f, 3.6f,
    -0.15f, 4.85f,3.4f,
    -0.25f, 4.85f,3.4f,
    -0.15f, 4.85f, 3.6f,
    -0.25f, 4.85f,3.4f,
    -0.25f, 4.85f, 3.6f,
    -0.15f, 4.85f, 3.6f,
    -0.25f, 4.85f, 3.6f,
    -0.15f,4.65f, 3.6f,

    0.25f,4.65f,3.4f, // triangle 1 : begin
    0.25f,4.65f, 3.6f,
    0.25f, 4.85f, 3.6f, // triangle 1 : end
    0.15f, 4.85f,3.4f, // triangle 2 : begin
    0.25f,4.65f,3.4f,
    0.25f, 4.85f,3.4f, // triangle 2 : end
    0.15f,4.65f, 3.6f,
    0.25f,4.65f,3.4f,
    0.15f,4.65f,3.4f,
    0.15f, 4.85f,3.4f,
    0.15f,4.65f,3.4f,
    0.25f,4.65f,3.4f,
    0.25f,4.65f,3.4f,
    0.25f, 4.85f, 3.6f,
    0.25f, 4.85f,3.4f,
    0.15f,4.65f, 3.6f,
    0.25f,4.65f, 3.6f,
    0.25f,4.65f,3.4f,
    0.25f, 4.85f, 3.6f,
    0.25f,4.65f, 3.6f,
    0.15f,4.65f, 3.6f,
    0.15f, 4.85f, 3.6f,
    0.15f,4.65f,3.4f,
    0.15f, 4.85f,3.4f,
    0.15f,4.65f,3.4f,
    0.15f, 4.85f, 3.6f,
    0.15f,4.65f, 3.6f,
    0.15f, 4.85f, 3.6f,
    0.15f, 4.85f,3.4f,
    0.25f, 4.85f,3.4f,
    0.15f, 4.85f, 3.6f,
    0.25f, 4.85f,3.4f,
    0.25f, 4.85f, 3.6f,
    0.15f, 4.85f, 3.6f,
    0.25f, 4.85f, 3.6f,
    0.15f,4.65f, 3.6f
};

GLfloat hair[] = {
    //Central part
    -0.4f,5.0f,2.5f, // triangle 1 : begin
    -0.4f,5.0f, 3.5f,
    -0.4f, 5.5f, 3.5f, // triangle 1 : end
    0.4f, 5.5f,2.5f, // triangle 2 : begin
    -0.4f,5.0f,2.5f,
    -0.4f, 5.5f,2.5f, // triangle 2 : end
    0.4f,5.0f, 3.5f,
    -0.4f,5.0f,2.5f,
    0.4f,5.0f,2.5f,
    0.4f, 5.5f,2.5f,
    0.4f,5.0f,2.5f,
    -0.4f,5.0f,2.5f,
    -0.4f,5.0f,2.5f,
    -0.4f, 5.5f, 3.5f,
    -0.4f, 5.5f,2.5f,
    0.4f,5.0f, 3.5f,
    -0.4f,5.0f, 3.5f,
    -0.4f,5.0f,2.5f,
    -0.4f, 5.5f, 3.5f,
    -0.4f,5.0f, 3.5f,
    0.4f,5.0f, 3.5f,
    0.4f, 5.5f, 3.5f,
    0.4f,5.0f,2.5f,
    0.4f, 5.5f,2.5f,
    0.4f,5.0f,2.5f,
    0.4f, 5.5f, 3.5f,
    0.4f,5.0f, 3.5f,
    0.4f, 5.5f, 3.5f,
    0.4f, 5.5f,2.5f,
    -0.4f, 5.5f,2.5f,
    0.4f, 5.5f, 3.5f,
    -0.4f, 5.5f,2.5f,
    -0.4f, 5.5f, 3.5f,
    0.4f, 5.5f, 3.5f,
    -0.4f, 5.5f, 3.5f,
    0.4f,5.0f, 3.5f
};


Man::Man(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->rotationx = 0;
    speed=0.01;
    flag=0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices


    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, COLOR_TORSO, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 12*3, head, COLOR_FACE, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 24*3, hands, COLOR_HANDS, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 24*3, legs, COLOR_LEGS, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 24*3, eyes, COLOR_TORSO, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 12*3, hair, COLOR_TORSO, GL_FILL);
    this->bounding_box.x=this->position.x;
    this->bounding_box.y=this->position.z;
    this->bounding_box.width=2.6f;
    this->bounding_box.height=1.0f;
}

void Man::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 rotatex    = glm::rotate((float) (this->rotationx * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotatex * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    draw3DObject(this->object5);
    this->bounding_box.x=this->position.x;
    this->bounding_box.y=this->position.z;
}

void Man::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

void Man::tick(int move) {
//    printf("%f\n",this->rotationz);
    if(this->position.y>0)
    {
        this->position.y-=this->speedy;
        speedy+=0.005;
    }
    else
    {
        this->position.y=0;
        speedy=0.0;
    }
    if(move)
    {
    if(this->rotationx>=8)
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
void Man::translate(int man_move)
{
    if(man_move==0)
        this->position.z+=3.0f;
    else
        this->position.z-=3.0f;
    for(int i=0;i<36*3;i++)
    {
        if(i%3==2 && man_move==0)
        {
            vertex_buffer_data[i]+=3.0f;
            head[i]+=3.0f;
            hair[i]+=3.0f;
        }
        else if(i%3==2 && man_move==1)
        {
            vertex_buffer_data[i]-=3.0f;
            head[i]-=3.0f;
            hair[i]-=3.0f;
        }
    }
    for(int i=0;i<36*3;i++)
    {
        if(i%3==2 && man_move==0)
        {
            hands[i]+=3.0f;
            legs[i]+=3.0f;
            eyes[i]+=3.0f;
        }
        else if(i%3==2 && man_move==1)
        {
            hands[i]-=3.0f;
            legs[i]-=3.0f;
            eyes[i]-=3.0f;
        }
    }
    this->bounding_box.x=this->position.x;
    this->bounding_box.y=this->position.z;
}
