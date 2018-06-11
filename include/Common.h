#ifndef COMMON_H
#define COMMON_H
#define INCLUDE_SDL
#include "SDL_include.h"

namespace Common {
enum Layer { BG, DEFAULT, FG, LIGHT, HUD };

// From SDL wiki
char *file_read(const char *filename);
}  // namespace Common
#endif  // COMMON_H
