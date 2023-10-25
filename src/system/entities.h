#pragma once

#include <vector>
#include <queue>
#include <unordered_map>
#include <typeindex>
#include <typeinfo>

#define ENT_NULL 4294967295

typedef unsigned int Entity;

namespace Entities {
    std::vector<bool> entities = {};
    std::queue<Entity> fill = {};
    Entity add() {
        if (fill.empty()) {
            entities.push_back(true);
            return entities.size();
        } else {
            Entity entity = fill.front();
            entities[entity] = true;
            fill.pop();
            return entity;
        }
    }

    void remove(Entity* entity) {
        fill.push(*entity);
        *entity = ENT_NULL;
    }
}

class CSet {
    public:
        std::vector<void*> components = {};
        std::vector<Entity> sparse = {};
        std::vector<Entity> dense = {};

        CSet();

        void insert(Entity entity, void* component) {
            int temp = dense.size();
            for (int i = 0; i < entity - temp; i++) {
                sparse.push_back(ENT_NULL);
            }

            sparse[entity] = dense.size();
            dense.push_back(entity);
            components.push_back(component);
        }
};

namespace Components {
    std::unordered_map<std::type_index, CSet> components = {};

    template<typename Component>
    Component add(Entity entity, Component component) {
        std::type_index id = typeid(Component);
        if (components.count(id) == 0) {
            components[id] = new CSet();
        }
        components[id].insert(entity, &component);
        return component;
    }
}