#pragma once


#ifdef CONSOLEGAMECONTROL_EXPORTS
	#define CONSOLEGAMECONTROL_API __declspec(dllexport)
#else
	#define CONSOLEGAMECONTROL_API __declspec(dllimport)
#endif