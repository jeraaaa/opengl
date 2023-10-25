#include <functional>
#include <unordered_map>
#include <vector>
#include <typeindex>
#include <algorithm>

std::unordered_map<std::type_index, std::vector<void*>> events = {};

struct KeyboardEvent {

};

namespace Events {
    template<typename Event>
    std::function<void(Event)>* connect(std::function<void(Event)> listener) {
        std::type_index id = typeid(Event);
        if (events.count(id) == 0) {
            events[id] = {};
        }

        std::function<void(Event)>* location = &listener;

        events[id].push_back(location);

        return location;
    }

    void disconnect(void* connection) {
        for (auto &[id, vec] : events) {
            for (int i = 0; i < vec.size(); i++) {
                if (connection == vec[i]) {
                    events[id].erase(vec.begin() + i);
                    connection = NULL;
                    return;
                }
            }
        }
    }

    template<typename Event>
    void fire(Event event) {
        if (events.count(typeid(event)) == 0) {
            return;
        }

        for (const auto listener : events[typeid(event)]) {
            (*reinterpret_cast<std::function<void(Event)>*>(listener))(event);
        }
    }
}