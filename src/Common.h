#pragma once

#include <cstdio>
#include <cstdlib>
#include <cassert>

#define NDEBUG

#if defined(__APPLE__)
#define PLATFORM_APPLE
#endif

#if defined(__MACH__)
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

#define UNUSED(x) (void)(x)

#define ENGINE_VERSION_MAJOR 1
#define ENGINE_VERSION_MINOR 0
#define ENGINE_VERSION_PATCH 0
#define ENGINE_VERSION_STRING "1.0.0"

#if defined(__GNUC__) || defined(__clang__)
#define LIB_API __attribute__((visibility("default")))
#define LIB_PRV __attribute__((visibility("hidden")))
#else
#define LIB_API
#define LIB_PRV
#endif
