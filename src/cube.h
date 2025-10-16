/**
 * @file	cube.h
 * @brief	TODO:
 *
 * @author	Luca Mazza
 */

#pragma once

#include <glm/glm.hpp>

#include "common.h"
#include "mesh.h"

#ifdef _METAL
struct CubeImpl;
#endif

/**
 * @brief Cube mesh class.
 */
class ENG_API Cube : public Mesh {
public:
    Cube();
    ~Cube();
	void render(const glm::mat4 world_matrix) const override;
private:
#ifdef _METAL
    CubeImpl* impl;
#endif
};
