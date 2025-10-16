/**
 * @file	ortho_camera.h
 * @brief	TODO:
 *
 * @author	Luca Mazza
 */

#pragma once

#include <glm/glm.hpp>

#include "common.h"
#include "camera.h"

/**
 * @brief Orthographic camera class.
 */
class ENG_API OrthoCamera : public Camera {
public:
	void set_zoom(float zoom);
	float get_zoom() const;
	void render(const glm::mat4 world_matrix) const override;
private:
	float zoom;
};
