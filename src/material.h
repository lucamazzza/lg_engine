/**
 * @file	material.h
 * @brief	TODO:
 *
 * @author	Luca Mazza 
 */

#pragma once

#include <memory>

#include <glm/glm.hpp>

#include "common.h"
#include "object.h"
#include "texture.h"

/**
 * @brief Material object class.
 */
class ENG_API Material : public Object {
public:
	Material();
	void render(const glm::mat4 world_matrix) const override;
	void set_emission_color(const glm::vec3 color);
	void set_ambient_color(const glm::vec3 color);
	void set_diffuse_color(const glm::vec3 color);
	void set_specular_color(const glm::vec3 color);
	void set_shininess(const float shininess);
	void set_texture(const std::shared_ptr<Texture> texture);
private:
	glm::vec3 emission_color;
	glm::vec3 ambient_color;
	glm::vec3 diffuse_color;
	glm::vec3 specular_color;
	float shininess;
	std::shared_ptr<Texture> texture;
};
