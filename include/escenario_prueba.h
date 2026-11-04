#pragma once

// =====================================================
// NO MODIFICAR ESTE ARCHIVO
// Marcadores fijos del modo de prueba.
//
// Hay una fila por partido, en el orden del reporte de resultados:
// el equipo 1 contra los equipos 2 a 6, despues el equipo 2 contra
// los equipos 3 a 6, y asi sucesivamente.
//
// Columna 0: goles del equipo local.
// Columna 1: goles del equipo visitante.
// =====================================================

#include "torneo.h"

const int COLUMNAS_MARCADOR = 2;

const int GOLES_PRUEBA[TOTAL_PARTIDOS][COLUMNAS_MARCADOR] = {
    {3, 3}, // Partido 1:  equipo 1 contra equipo 2
    {3, 1}, // Partido 2:  equipo 1 contra equipo 3
    {4, 0}, // Partido 3:  equipo 1 contra equipo 4
    {2, 0}, // Partido 4:  equipo 1 contra equipo 5
    {1, 4}, // Partido 5:  equipo 1 contra equipo 6
    {0, 1}, // Partido 6:  equipo 2 contra equipo 3
    {0, 5}, // Partido 7:  equipo 2 contra equipo 4
    {2, 3}, // Partido 8:  equipo 2 contra equipo 5
    {5, 2}, // Partido 9:  equipo 2 contra equipo 6
    {0, 1}, // Partido 10: equipo 3 contra equipo 4
    {5, 1}, // Partido 11: equipo 3 contra equipo 5
    {3, 2}, // Partido 12: equipo 3 contra equipo 6
    {5, 3}, // Partido 13: equipo 4 contra equipo 5
    {3, 3}, // Partido 14: equipo 4 contra equipo 6
    {0, 1}  // Partido 15: equipo 5 contra equipo 6
};
