#pragma once

#include <glm/glm.hpp>

#include "Common.h"
#include "Object.h"

class LIB_API Node : Object {
public:
    Node();
    void set_base_matrix(const glm::mat4 base_matrix);
    void set_position(const glm::vec3 position);
    void set_rotation(const glm::vec3 rotation);
    void set_scale(const glm::vec3 scale);
    glm::mat4 get_local_matrix() const override;
    glm::vec3 get_position() const;
    glm::vec3 get_rotation() const;
    glm::vec3 get_scale() const;
    void render(const glm::mat4 world_matrix) const override;
private:
    glm::mat4 base_matrix;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};
