// Proyecto Parcial 3: Sistema de Gestion de un Torneo de Futbol
// Programa principal (bloque de integracion, de todo el equipo).
//
// Compilar (desde la carpeta del proyecto):
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o torneo
// Ejecutar en macOS:
//   ./torneo
// Ejecutar en Windows:
//   .\torneo.exe
//
// Lean PROYECTO.md antes de escribir codigo.

#include <iostream>

#include "utilerias.h"
#include "torneo.h"

// TODO: incluyan aqui el archivo .h de cada modulo.

int main() {
    // TODO: declaren aqui los datos del torneo.
    //       No usen variables globales.

    // TODO: menu que se repite hasta elegir "Salir".
    //       Una opcion que no existe se rechaza con un mensaje.

    // El menu debe permitir ejecutar el escenario obligatorio, en este orden:
    //
    // Paso 1: elegir cada reporte sin equipos registrados (rechazos).
    // Paso 2: intentar simular sin los 6 equipos (rechazo).
    // Paso 3: registrar 6 equipos. Durante el registro, teclear un nombre
    //         repetido con otras mayusculas o minusculas, uno de menos de
    //         3 caracteres, uno de mas de 15 y uno con acento o enie
    //         (rechazos).
    // Paso 4: intentar registrar un equipo mas (rechazo por lista llena).
    // Paso 5: simular en modo de prueba.
    // Paso 6: intentar simular de nuevo (rechazo).
    // Paso 7: mostrar equipos, resultados, tabla y matriz.
    // Paso 8: mostrar al campeon y elegirlo entre los empatados.
    // Paso 9: consultar un equipo existente y uno inexistente (rechazo).
    // Paso 10: teclear una opcion de menu inexistente (rechazo) y salir.
    // Paso 11: ejecutar de nuevo el programa en modo aleatorio y mostrar
    //          resultados, tabla y campeon.

    return 0;
}
