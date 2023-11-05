#pragma once

#ifdef JM_PLATFORM_WINDOWS
#include <Windows.h>
#endif

#include <memory>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include <functional>
#include <algorithm>

#include <fstream>

#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <Jasmine/Core/Base.h>
#include <Jasmine/Core/Log.h>
#include <Jasmine/Core/Events/Event.h>

// Math
#include <Jasmine/Core/Math/Mat4.h>