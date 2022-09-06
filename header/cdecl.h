#ifndef CDECL_H_

#define CDECL_H_

/* Includes for the header file */

#ifdef __cplusplus
#define LANGUAGE extern "C"
#elif defined __GNUC__
#define LANGUAGE extern
#endif

#ifdef CDECL_STATIC_
#define DLLIMPORT
#elif defined BUILDING
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

#define CALLING __cdecl
//#define CALLING __stdcall

/* Macros and definitions for the source file. */
#ifdef CDECL_DEFINITIONS_
#define elif else if
#define null NULL
#define String char*
#endif

LANGUAGE DLLIMPORT CALLING void helloWorld(int nro, int nargs, ...);
CALLING void printNumber(int nro);

#if !defined BUILDING
#undef LANGUAGE
#undef DLLIMPORT
#undef CALLING
#endif

#endif
