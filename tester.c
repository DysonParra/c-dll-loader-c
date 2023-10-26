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
 * @version 1.0     Implementation done.
 * @version 2.0     Documentation added.
 */
#include "tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef void (*funcNoArgs)();
typedef int (*funcWithArgs)(int value);
typedef void (*funcVarArg)(int value, int nargs, ...);

/**
 * Entrada principal del sistema.
 *
 * @param argc cantidad de argumentos pasados en la linea de comandos.
 * @param argv argumentos de la linea de comandos.
 * @return {0} si el programa se ejecutó correctamente.
 */
int main(int argc, char** argv) {
    //printNumber(2);
    //printf("Factorial is %d\n", factorial(4));
    // helloWorld(5, 3, 7, 9, 1);

    char libName[30] = "std_cdecl_lib.dll";
    HMODULE dllHandle = LoadLibrary(libName); // cargar biblioteca.

    /* Si no fue posible cargar la dll. */
    if (!dllHandle)
        printf("Error %s\n", libName);
    else {
        /* Si la dll se cargó exitosamente. */

        //funcNoArgs   noArg;
        funcWithArgs withArg;
        funcVarArg   varArg;

        //noArg   =  (funcNoArgs)    GetProcAddress(dllHandle, "helloWorld");
        withArg =  (funcWithArgs)  GetProcAddress(dllHandle, "factorial");
        varArg  =  (funcVarArg)    GetProcAddress(dllHandle, "helloWorld");

        if (!varArg)
            printf("Error getting direction of helloWorld()\n");
        else
            varArg(5, 3, 7, 9, 1);

        if (!withArg)
            printf("Error getting direction of factorial()\n");
        else
            printf("'%d'\n", withArg(5));

        /* Descarga la biblioteca y la elimina de la memoria. */
        FreeLibrary(dllHandle);
    }

    return 0;
}
