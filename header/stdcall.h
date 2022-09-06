#ifndef STDCALL_H_

#define STDCALL_H_

/* Includes for the header file */

#ifdef __cplusplus
#define LANGUAGE extern "C"
#elif defined __GNUC__
#define LANGUAGE extern
#endif

#ifdef STDCALL_STATIC_
#define DLLIMPORT
#elif defined BUILDING
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

//#define CALLING __cdecl
#define CALLING __stdcall

/* Macros and definitions for the source file. */
#ifdef STDCALL_DEFINITIONS_
#define elif else if
#define null NULL
#define String char*
#endif

LANGUAGE DLLIMPORT CALLING int factorial(int nro);
CALLING void printArray(char* array);

#if !defined BUILDING
#undef LANGUAGE
#undef DLLIMPORT
#undef CALLING
#endif

#endif
