# LGEngine 

Minimal C++ project using Metal API on macOS.

## Build

```sh
make
```

## Run

```sh
./metal_demo
```

## Requirements

- macOS
- Xcode Command Line Tools (`xcode-select --install`)
- Metal-compatible Mac

## Structure

- `main.mm`: Entry point (Objective-C++ for Metal interoperability)
- `Engine.*`: Core engine logic (C++)
- `MetalRenderer.*`: Metal API wrapper (Objective-C++)

## Extend

Add your graphics logic into `Engine` and real Metal rendering to `MetalRenderer`.
