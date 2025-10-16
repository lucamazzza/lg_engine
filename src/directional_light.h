/**
 * @file	directional_light.h
 * @brief	TODO:
 *
 * @author	Luca Mazza
 */

#pragma once

#include <glm/glm.hpp>

#include "common.h"
#include "light.h"

/**
 * @brief Directional light class.
 */
class ENG_API DirectionalLight : public Light {
public:
	DirectionalLight();
	void set_direction(const glm::vec3 direction);
	void render(const glm::mat4 world_matrix) const override;
private:
	glm::vec3 direction;
};
