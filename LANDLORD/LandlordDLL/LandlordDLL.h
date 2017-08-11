//LandlordDLL.h

#pragma once
#ifdef LandlordDLL_EXPORTS
#define LandlordDLL_API __declspec(dllexport) 
#else
#define LandlordDLL_API __declspec(dllimport) 
#endif