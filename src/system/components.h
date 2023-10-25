#pragma once

#include <vector>

#include "../vector2.h"

struct Transform {
    Vector2 position;
    Vector2 velocity;
    bool anchored;
};

struct Collider {
    std::vector<float> vertices;
    bool aabb;
};