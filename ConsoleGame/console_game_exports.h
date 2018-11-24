#pragma once


#ifdef CONSOLEGAME_EXPORTS
	#define CONSOLEGAME_API __declspec(dllexport)
#else
	#define CONSOLEGAME_API __declspec(dllimport)
#endif