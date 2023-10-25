#include <math.h>

struct Vector2 {
    float x;
    float y;

    float magnitude() {
        return std::sqrt(x*x+y*y);
    }

    Vector2 normalized() {
        float len = magnitude();
        return {x/len, y/len};
    }

    Vector2 dot(Vector2 vec) {
        return {x*vec.x, y*vec.y};
    }
};