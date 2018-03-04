#include "main.h"

#ifndef HGIFT_H
#define HGIFT_H


class HGift {
public:
    HGift() {}
    HGift(float x, float y);
    glm::vec3 position;
    float rotation;
    float rotationx;
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
