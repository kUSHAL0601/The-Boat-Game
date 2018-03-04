#include "main.h"

#ifndef BULLET_H
#define BULLET_H


class Bullet {
public:
    Bullet() {}
    Bullet(float x, float y, color_t color,float rotation);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    bounding_box_t bounding_box;
    double speed;
private:
    VAO *object;
};

#endif
