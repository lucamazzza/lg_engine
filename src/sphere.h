/**
 * @file	sphere.h
 * @brief	TODO:
 *
 * @author	Luca Mazza
 */

#pragma once

#include <glm/glm.hpp>

#include "common.h"
#include "mesh.h"

struct SphereImpl;

/**
 * @brief Sphere mesh class.
 */
class ENG_API Sphere : public Mesh {
public:
    Sphere();
    ~Sphere();
	void render(const glm::mat4 world_matrix) const override;
private:
    SphereImpl* impl;
};
