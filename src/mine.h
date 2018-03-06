#include "main.h"

#ifndef MINE_H
#define MINE_H


class Mine {
public:
    Mine() {}
    Mine(float x, float y, color_t color);
    glm::vec3 position;
    void tick();
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    double speed;
    bounding_box_t bounding_box();
private:
    VAO *object;
};

#endif
