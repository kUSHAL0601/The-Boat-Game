#include "main.h"

#ifndef MAN_H
#define MAN_H


class Man {
public:
    Man() {}
    Man(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    float rotationx;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    bounding_box_t bounding_box;
    void tick(int move);
    double speed;
    int flag;
private:
    VAO *object;
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
};

#endif
