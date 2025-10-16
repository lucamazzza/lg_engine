#import <Metal/Metal.h>
#import <QuartzCore/CAMetalLayer.h>

#include <iostream>

#include "metal_renderer.h"
#include "engine.h"
#include "common.h"

ENG_API MetalRenderer::MetalRenderer() {
    DEBUG("MetalRenderer Initialized");
}

ENG_API MetalRenderer::~MetalRenderer() {
    DEBUG("MetalRenderer Destroyed");
}

void ENG_API MetalRenderer::run(Engine *engine) {
    id<MTLDevice> device = MTLCreateSystemDefaultDevice();
    if (!device) {
        ERROR("Metal is not supported on this device");
        return;
    }
    INFO("Running Metal app...");
    engine->update();
}
