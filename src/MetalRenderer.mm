#import <Metal/Metal.h>
#import <QuartzCore/CAMetalLayer.h>

#include <iostream>

#include "MetalRenderer.h"
#include "Engine.h"
#include "Common.h"

LIB_API MetalRenderer::MetalRenderer() {
    DEBUG("MetalRenderer Initialized");
}

LIB_API MetalRenderer::~MetalRenderer() {
    DEBUG("MetalRenderer Destroyed");
}

void LIB_API MetalRenderer::run(Engine *engine) {
    id<MTLDevice> device = MTLCreateSystemDefaultDevice();
    if (!device) {
        ERROR("Metal is not supported on this device");
        return;
    }
    INFO("Running Metal app...");
    engine->update();
}
