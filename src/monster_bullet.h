#include "main.h"

#ifndef MONSTER_MBullet_H
#define MONSTER_MBullet_H


class MBullet {
public:
    MBullet() {}
    MBullet(float x, float y, color_t color,float rotation);
    glm::vec3 position;
    float rotation;
    float factor;
    float initx,initz;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    bounding_box_t bounding_box;
    double speed;
private:
    VAO *object;
};

#endif
