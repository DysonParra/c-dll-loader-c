/*
 * @fileoverview    {FileName}
 *
 * @version         2.0
 *
 * @author          Dyson Arley Parra Tilano <dysontilano@gmail.com>
 *
 * @copyright       Dyson Parra
 * @see             github.com/DysonParra
 *
 * History
 * @version 1.0     Implementación realizada.
 * @version 2.0     Documentación agregada.
 */
#include "cdecl.h"
#include <stdarg.h>
#include <stdio.h>
#include <windows.h>

#if (!defined STATIC_LIB_) && (!defined NO_DLL_MAIN_)
/**
 * Entrada principal de la dll (creado si no se indica que es biblioteca estática)
 *
 * @param instance identificador del módulo.
 * @param reason   razón de la llamada.
 * @param reserved argumento reservado.
 * @return {@code TRUE} si se completó exitosamente la llamada, caso contrario {@code FALSE}.
 */
BOOL APIENTRY DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
    /*
     * Evalúa la razón de la llamada a la dll.
     */
    switch (reason) {
        /*
         * Se cargó la dll en el proceso actual.
         */
        case DLL_PROCESS_ATTACH:
            // printf("%s\n", "DLL_PROCESS_ATTACH");
            break;

        /*
         * Se liberó la dll en el proceso actual.
         */
        case DLL_PROCESS_DETACH:
            // printf("%s\n", "DLL_PROCESS_DETACH");
            break;

        /*
         * Se cargó la dll en un nuevo hilo.
         */
        case DLL_THREAD_ATTACH:
            // printf("%s\n", "DLL_THREAD_ATTACH");
            break;

        /*
         * Se liberó la dll en el nuevo hilo.
         */
        case DLL_THREAD_DETACH:
            // printf("%s\n", "DLL_THREAD_DETACH");
            break;
    }

    return TRUE;
}
#endif

/**
 * TODO: Definición de {@code helloWorld}.
 */
LANGUAGE DLLIMPORT CALLING void helloWorld(int nro, int nargs, ...) {
    printf("%s from DLL!\n", __func__);
    printf("nro is %d\n", nro);
    printf("nargs is %d\n", nargs);
    va_list ap;
    va_start(ap, nargs);
    int params[nargs];

    for (int i = 0; i < nargs; i++)
        params[i] = va_arg(ap, int);

    va_end(ap);

    for (int i = 0; i < nargs; i++)
        printf("Arg %d = \"%d\"\n", i, params[i]);
    printf("\n");
}

/**
 * TODO: Definición de {@code printNumber}.
 */
CALLING void printNumber(int nro) {
    for (int i = 0; i < nro; i++)
        printf("%d: %s\n", i + 1, "This is a message");
}
