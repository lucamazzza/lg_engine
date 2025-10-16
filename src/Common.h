#pragma once

#include <cstdio>
#include <cstdlib>
#include <cassert>

#define NDEBUG

#ifdef __APPLE__
#define PLATFORM_APPLE
#define _METAL
#endif

#ifdef __MACH__
#define PLATFORM_MACOS
#endif

#ifdef NDEBUG
#define DEBUG(fmt, ...)     std::fprintf(stdout, "[DEBUG]   " fmt "\n", ##__VA_ARGS__)
#else
#define DEBUG(fmt, ...)     ((void)0)
#endif

#define INFO(fmt, ...)      std::fprintf(stdout, "[INFO]    " fmt "\n", ##__VA_ARGS__)
#define WARNING(fmt, ...)   std::fprintf(stderr, "[WARNING] " fmt "\n", ##__VA_ARGS__)
#define ERROR(fmt, ...)     std::fprintf(stderr, "[ERROR]   " fmt "\n", ##__VA_ARGS__)

#define ASSERT(x) \
    do { \
        if (!(x)) { \
            ERROR("Assertion failed: %s (%s:%d)", #x, __FILE__, __LINE__); \
            assert(x); \
        } \
    } while (0)

#define UNUSED(x)           (void)(x)

#define ENGINE_VERSION_MAJOR 1
#define ENGINE_VERSION_MINOR 0
#define ENGINE_VERSION_PATCH 0
#define ENGINE_VERSION_STRING "1.0.0"

#ifdef _WINDOWS
#define _OPENGL
#ifdef ENGINE_EXPORTS
#define ENG_API __declspec(dllexport)
#else
#define ENG_API __declspec(dllimport)
#endif      
#pragma warning(disable : 4251) 
#define ENG_PRV
#else
#if defined(__GNUC__) || defined(__clang__)
#define ENG_API             __attribute__((visibility("default")))
#define ENG_PRV             __attribute__((visibility("hidden")))
#endif
#endif
