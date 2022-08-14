#pragma once

#ifdef SP_PLATFORM_WINDOWS
	#ifdef SP_BUILD_DLL
		#define SPRING_API __declspec(dllexport)
	#else
		#define SPRING_API __declspec(dllimport)
	#endif
#else
	#error Spring only support Windows!
#endif