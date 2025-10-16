#pragma once

#include "common.h"

class Engine;

class ENG_API MetalRenderer {
public:
    MetalRenderer();
    ~MetalRenderer();
    void run(Engine *engine);
};
