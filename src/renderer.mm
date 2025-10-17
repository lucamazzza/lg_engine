#include "renderer.h"
#include "common.h"

#import <Metal/Metal.h>
#include <memory>
#include <vector>
#import <QuartzCore/CAMetalLayer.h>

struct MaterialData {
    glm::vec3 emission; float pad1;
    glm::vec3 ambient;  float pad2;
    glm::vec3 diffuse;  float pad3;
    glm::vec3 specular; float shininess;
    int hasTexture;
};

struct LightData {
    glm::vec3 position; float pad1;
    glm::vec3 color;    float pad2;
    int type;
};

struct CameraData {
    glm::mat4 view;
    glm::mat4 projection;
};

struct RendererImpl {
    id<MTLDevice> device;
    id<MTLCommandQueue> command_queue;
    id<MTLCommandBuffer> command_buf;
    id<MTLRenderCommandEncoder> enc;
    CAMetalLayer* metal_layer;
    int width, height;
    CameraData camera_data;
    std::vector<LightData> lights;
    RendererImpl()
        : device(nil), command_queue(nil), command_buf(nil), enc(nil), metal_layer(nil), width(0), height(0) {
        device = MTLCreateSystemDefaultDevice();
        command_queue = [device newCommandQueue];
    }
    ~RendererImpl() {
        enc = nil;
        command_buf = nil;
        command_queue = nil;
        device = nil;
    }
};

id<MTLTexture> ENG_API to_metal_texture(std::shared_ptr<Texture> texture) {
    return nil;
}

void ENG_API draw_metal(const Mesh *mesh, id<MTLRenderCommandEncoder>) {

}

ENG_API Renderer::Renderer() : impl(new RendererImpl()) {}

ENG_API Renderer::~Renderer() {
    delete impl;
}

void Renderer::resize(int width, int height) {
    impl->width = width;
    impl->height = height;
    if (impl->metal_layer) {
        impl->metal_layer.drawableSize = CGSizeMake(width, height);
    }
}

void Renderer::begin_frame() {
    id<CAMetalDrawable> drawable = [impl->metal_layer nextDrawable];
    impl->command_buf = [impl->command_queue commandBuffer];
    MTLRenderPassDescriptor* pass_desc = [MTLRenderPassDescriptor renderPassDescriptor];
    pass_desc.colorAttachments[0].texture = drawable.texture;
    pass_desc.colorAttachments[0].loadAction = MTLLoadActionClear;
    pass_desc.colorAttachments[0].storeAction = MTLStoreActionStore;
    pass_desc.colorAttachments[0].clearColor = MTLClearColorMake(0.1, 0.1, 0.1, 1.0);

    impl->enc = [impl->command_buf renderCommandEncoderWithDescriptor:pass_desc];
}

void Renderer::end_frame() {
    [impl->enc endEncoding];
    id<CAMetalDrawable> drawable = [impl->metal_layer nextDrawable];
    [impl->command_buf presentDrawable:drawable];
    [impl->command_buf commit];
    impl->enc = nil;
    impl->command_buf = nil;
}

void Renderer::set_camera(const Camera* camera) {
    impl->camera_data.view = camera->get_local_matrix();
    // Fill cameraData from Camera object
    // Example: impl->cameraData.view = camera->getViewMatrix();
    //          impl->cameraData.projection = camera->getProjectionMatrix();
}

void Renderer::set_lights(const std::vector<const Light*>& lights) {
    // Fill impl->lights from Light objects
    impl->lights.clear();
    for (const Light* l : lights) {
        LightData ld;
        // Fill ld from l
        impl->lights.push_back(ld);
    }
}

void Renderer::draw_mesh(const Mesh* mesh, const Material* material, const glm::mat4 modelMatrix) {
    // Prepare and bind mesh vertex/index buffers, pipeline state, etc.
    // Prepare material data
    MaterialData mat_data;
    mat_data.emission = material->get_emission_color();
    mat_data.ambient = material->get_ambient_color();
    mat_data.diffuse = material->get_diffuse_color();
    mat_data.specular = material->get_specular_color();
    mat_data.shininess = material->get_shininess();
    mat_data.hasTexture = (material->get_texture() != nullptr) ? 1 : 0;

    // Upload material data
    [impl->enc setFragmentBytes:&mat_data length:sizeof(MaterialData) atIndex:1];

    // Upload camera data
    [impl->enc setVertexBytes:&impl->camera_data length:sizeof(CameraData) atIndex:2];

    // Upload lights
    if (!impl->lights.empty()) {
        [impl->enc setFragmentBytes:impl->lights.data() length:sizeof(LightData)*impl->lights.size() atIndex:3];
    }

    // Upload model matrix
    [impl->enc setVertexBytes:&modelMatrix length:sizeof(glm::mat4) atIndex:4];

    // Bind texture if present
    if (material->get_texture() != nullptr) {
        id<MTLTexture> tex = to_metal_texture(material->get_texture());
        [impl->enc setFragmentTexture:tex atIndex:0];
    }

    // Draw mesh (assuming Mesh exposes Metal buffers)
    draw_metal(mesh, impl->enc);
}


