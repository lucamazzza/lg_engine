#include <glm/glm.hpp>

#include "camera.h"
#include "common.h"
#include "light.h"
#include "material.h"
#include "mesh.h"
#include "object.h"

struct RendererImpl;

class ENG_API Renderer {
public:
    Renderer();
    ~Renderer();
    void set_metal_layer(void *metal_layer);
    void begin_frame();
    void end_frame();
    void set_lights(const std::vector<const Light*>& lights);
    void set_camera(const Camera *camera);
    void draw_mesh(const Mesh *mesh, const Material *material, const glm::mat4 model_matrix);
    void resize(int width, int height);
private:
    RendererImpl* impl; 
};
