#include "target.h"
#include "main.h"

Target::Target(float x, float y, color_t color) {
    this->position = glm::vec3(x, y,12.0);
    this->rotation = 0;
    speed = 1;
    vertices=102;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[100001] = {};
    for(int i=0;i<vertices;i+=1)
    {
        vertex_buffer_data[9*i]=0.2*cos((float)(2*M_PI*i)/vertices);
        vertex_buffer_data[9*i+1]=0.2*sin((float)(2*M_PI*i)/vertices);
        vertex_buffer_data[9*i+2]=0.0f;

        vertex_buffer_data[9*i+3]=0.2*cos((float)(2*M_PI*(i+1)/vertices));
        vertex_buffer_data[9*i+4]=0.2*sin((float)(2*M_PI*(i+1)/vertices));
        vertex_buffer_data[9*i+5]=0.0f;

        vertex_buffer_data[9*i+6]=0.0f;
        vertex_buffer_data[9*i+7]=0.0f;
        vertex_buffer_data[9*i+8]=0.0f;
        for(int j=0;j<9;j++)
        {
            if((fabs(vertex_buffer_data[9*i+j]))<=0.0000001)
                vertex_buffer_data[9*i+j]=0.0  ;
        }
    }

    this->object = create3DObject(GL_TRIANGLES, vertices*9, vertex_buffer_data, color, GL_POINT);
}

void Target::draw(glm::mat4 VP, glm::vec3 boat_pos) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(boat_pos.x, 1, boat_pos.z));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Target::set_position(float x, float y, glm::vec3 boat_pos) {
    this->position = glm::vec3(x, y, boat_pos.z+12.0);
}

void Target::tick() {
}
