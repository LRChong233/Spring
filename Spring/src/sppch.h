#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Spring/Core/Log.h"

#include "Spring/Debug/Instrumentor.h"

#ifdef SP_PLATFORM_WINDOWS
	#include <Windows.h>
#endif