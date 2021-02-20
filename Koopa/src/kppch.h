#pragma once

#include "Koopa/Core/PlatformDetection.h"

#ifdef KP_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif
#endif


#include <iostream>
#include <memory>
#include <array>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Koopa/Core/Base.h"
#include "Koopa/Core/Log.h"
#include "Koopa/Debug/Instrumentor.h"

#ifdef KP_PLATFORM_WINDOWS
	#include <Windows.h>
#endif