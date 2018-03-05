#include "main.h"

#ifndef BOAT_H
#define BOAT_H


class Boat {
public:
    Boat() {}
    Boat(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    float rotationx;
    void draw(glm::mat4 VP, int nos);
    void set_position(float x, float y,float z);
    bounding_box_t bounding_box;
    void tick(int move);
    double speed;
    double speedy;
    int flag;
private:
    VAO *object;
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
};

#endif
