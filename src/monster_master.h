#include "main.h"

#ifndef MMonster_H
#define MMonster_H


class MMonster {
public:
    MMonster() {}
    MMonster(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    bounding_box_t bounding_box;
    double speed;
    float health=100.0;
private:
    VAO *object;
    VAO *object1;
    VAO *object2;
};

#endif
