#pragma once

#ifdef _WIN32
#pragma warning(disable:4091)

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif

#if defined(__MINGW32__) && !defined(__NO_MINGW_DEFINES__)
#include "../Windows/mingw_defines.h"
#endif

#include <Windows.h>

#undef min
#undef max
#undef DrawText
#endif
