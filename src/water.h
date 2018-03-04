#include "main.h"

#ifndef WATER_H
#define WATER_H


class Water {
public:
    Water() {}
    Water(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
private:
    VAO *object;
};

#endif // BALL_H
