/**
 * @file    engine.h
 * @brief	Graphics engine main include file
 *
 * @author	Luca Mazza
 */

#pragma once 

#include <memory>
#include <string>
#include <vector>
#include <sstream>

#include <glm/glm.hpp>

#include "common.h"
#include "object.h"
#include "camera.h"
#include "material.h"

class ENG_API Engine final {
public:
    Engine(Engine const&) = delete;
    ~Engine();
    Engine& operator=(Engine const&) = delete;
    static bool init(const std::string& window_title, int window_width, int window_height);
    static void run();
    static void set_keyboard_callback(void (*func)(int key, int scancode, int action, int mods));
    static void set_sky_color(float red, float green, float blue);
    static bool is_running();
    static void render();
    static void timer_callback(int val);
    static void update();
    static void clear_screen();
    static void swap_buffers();
    static void stop();
    static void quit();
    static std::shared_ptr<Object> get_scene();
    static void set_scene(const std::shared_ptr<Object> scene);
    static void set_active_camera(const std::shared_ptr<Object> camera);
    static std::shared_ptr<Object> find_obj_by_name(const std::string name);
    static void set_screen_text(const std::string text);
    static bool free();
private:
    static void resize_callback(int width, int height);
    static std::vector<std::pair<std::shared_ptr<Object>, glm::mat4>> build_render_list(const std::shared_ptr<Object> obj, const glm::mat4 parent_matrix);
    static std::shared_ptr<Object> find_obj_by_name(const std::string name, const std::shared_ptr<Object> root);
    static int window_id;
    static int window_width;
    static int window_height;
    static std::shared_ptr<Object> scene;
    static std::shared_ptr<Camera> active_camera;
    static std::shared_ptr<Material> shadow_material;
    static std::string screen_text;
    static int frames;
    static float fps;
    static bool is_init_f;
    static bool is_running_f;
    Engine();
};
