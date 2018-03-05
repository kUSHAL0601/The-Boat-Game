#include "main.h"

#ifndef TARGET_H
#define TARGET_H


class Target {
public:
    Target() {}
    Target(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float vertices;
    void draw(glm::mat4 VP,glm::vec3 boat_pos);
    void set_position(float x, float y,glm::vec3 boat_pos);
    void tick();
    bounding_box_t bounding_box;
    double speed;
private:
    VAO *object;
};

#endif // Target_H
