#include "main.h"

#ifndef GIFT_H
#define GIFT_H


class Gift {
public:
    Gift() {}
    Gift(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    bounding_box_t bounding_box;
    void tick();
    double speed;
    int flag;
private:
    VAO *object;
    VAO *object1;
};

#endif
