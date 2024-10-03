#pragma once


//	----- STD ------
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <omp.h>
#include <memory>
#include <string>
#include <functional>
#include <sstream>

#include "Almond/Log.h"

#ifdef ALMND_PLATFORM_WINDOWS
	#include <Windows.h>
#endif