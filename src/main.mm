#import <Foundation/Foundation.h>

#include "Engine.h"
#include "MetalRenderer.h"

int main(int argc, char *argv[]) {
    @autoreleasepool {
        Engine engine;
        MetalRenderer renderer;
        renderer.run(&engine);
    }   
}
