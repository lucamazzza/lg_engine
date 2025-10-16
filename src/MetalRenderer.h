#pragma once

#include "Common.h"

class Engine;

class LIB_API MetalRenderer {
public:
    MetalRenderer();
    ~MetalRenderer();
    void run(Engine *engine);
};
