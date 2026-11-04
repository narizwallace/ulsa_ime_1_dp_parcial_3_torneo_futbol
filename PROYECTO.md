# Proyecto Parcial 3: Sistema de Gestión de un Torneo de Fútbol

**Materia:** Diseño de Programas (C++)  
**Alcance:** Unidades I a VII  
**Repositorio base:** https://github.com/narizwallace/ulsa_ime_1_dp_parcial_3_torneo_futbol  
**Entrega:** lunes 23 de noviembre, 11:59 PM, en Classroom  
**Exposición:** martes 24 de noviembre

> Te sugerimos no usar IA para generar el código. Hacerlo por tu cuenta te prepara para explicar tu trabajo y para el examen semestral.

## 1. Objetivo

Construir en equipo un programa que administra un torneo de fútbol de 6 equipos. Cada integrante diseña, programa, documenta y expone un módulo propio, y el equipo completo responde por la solución integrada. En este parcial se evalúa especialmente el uso correcto de buenas prácticas.

## 2. El problema

### 2.1 Reglas del torneo

- Participan 6 equipos, que juegan todos contra todos a una vuelta: 15 partidos.
- Cada equipo anota un número aleatorio de goles entre 0 y 5. Puede haber empates.
- Victoria: 3 puntos. Empate: 1 punto. Derrota: 0 puntos.
- La tabla se ordena de mayor a menor por puntos. Los equipos con los mismos puntos pueden quedar en cualquier orden.
- Los reportes de equipos, ficha y matriz conservan el orden de registro, aunque la tabla esté ordenada.
- El campeón es el equipo con más puntos. Si hay empate en el primer lugar, el programa muestra a los empatados y el usuario elige al campeón. Si elige una opción que no existe, se vuelve a preguntar. La elección se pide cada vez que se consulta al campeón y no cambia la tabla de posiciones.
- El mejor ataque es el equipo con más goles a favor, y la mejor defensa, el equipo con menos goles en contra. Si hay empate, se muestran todos los empatados, en orden de registro.
- Los equipos se registran uno por vez. Si el nombre es inválido, se vuelve a pedir.
- El nombre tiene de 3 a 15 caracteres, sin acentos ni ñ, y no puede repetirse.
- Las mayúsculas y minúsculas no se distinguen en los nombres: `Pumas` y `pumas` son el mismo equipo, tanto al registrar como al buscar.
- La abreviatura tiene 3 caracteres. El equipo decide si se calcula automáticamente o se captura, y cómo resolver las repetidas.
- Los datos se guardan en registros (`struct`) y arreglos. No se usan variables globales ni arreglos paralelos.
- Toda entrada por teclado se lee con las funciones de `utilerias.h`.
- El torneo se simula una sola vez por ejecución. Al simular, la tabla se calcula automáticamente una vez.
- Ningún reporte funciona antes de simular el torneo, salvo la lista de equipos, y no se simula sin los 6 equipos: el programa avisa y regresa al menú.

### 2.2 Módulos

| # | Módulo | Qué hace | Temas que debe demostrar |
| --- | --- | --- | --- |
| 1 | Registro de equipos | Captura los equipos y muestra la lista | Registros, arreglos, validación de cadenas |
| 2 | Simulación de partidos | Genera los 15 partidos, en modo aleatorio o de prueba, y muestra los resultados | Registros, ciclos anidados |
| 3 | Tabla de posiciones | Calcula las estadísticas de cada equipo, sin imprimir un reporte | Funciones, paso por referencia |
| 4 | Clasificación y campeón | Ordena y muestra la tabla, detecta empates y resuelve al campeón | Ordenamiento, intercambio de registros |
| 5 | Consultas | Busca un equipo y muestra su ficha | Manipulación de cadenas, apuntadores |
| 6 | Matriz de enfrentamientos | Muestra la matriz, mejor ataque y mejor defensa | Matrices |

> **Importante:** todos los equipos entregan los seis módulos. En equipos de 5, todo el equipo es dueño del módulo 6, y decide cómo organizarse.

### 2.3 Integración

El programa principal muestra un menú que se repite hasta elegir "Salir", con una opción por cada acción y reporte. No hay una opción para calcular la tabla, porque se calcula al simular. Si el usuario teclea una opción que no existe, avisa y vuelve a mostrar el menú.

Ejemplo del menú:

```
1. Registrar equipo
2. Mostrar equipos
3. Simular torneo
4. Mostrar resultados
5. Mostrar tabla de posiciones
6. Mostrar campeon
7. Consultar equipo
8. Mostrar matriz de enfrentamientos
9. Salir
Opcion:
```

### 2.4 Modo de prueba

`include/escenario_prueba.h` trae 15 marcadores fijos. El programa ofrece simular en modo aleatorio o de prueba. Los marcadores se asignan por orden de registro: el equipo 1 usa los resultados de Aguilas en los ejemplos, el equipo 2 los de Halcones, y así sucesivamente.

### 2.5 Escenario obligatorio

En la exposición, el equipo ejecuta estos pasos en orden:

1. Elegir cada reporte sin equipos registrados (rechazos).
2. Intentar simular sin los 6 equipos (rechazo).
3. Registrar 6 equipos. Durante el registro, teclear un nombre repetido con otras mayúsculas o minúsculas, uno de menos de 3 caracteres, uno de más de 15 y uno con acento o ñ (rechazos).
4. Intentar registrar un equipo más (rechazo por lista llena).
5. Simular en modo de prueba.
6. Intentar simular de nuevo (rechazo).
7. Mostrar equipos, resultados, tabla y matriz.
8. Mostrar al campeón y elegirlo entre los empatados.
9. Consultar un equipo existente y uno inexistente (rechazo).
10. Teclear una opción de menú inexistente (rechazo) y salir.
11. Ejecutar de nuevo el programa en modo aleatorio y mostrar resultados, tabla y campeón.

### 2.6 Formato de los reportes

Los reportes deben cumplir **fielmente** estos ejemplos: títulos, columnas, orden, textos y alineación. Los nombres de los equipos pueden cambiar, pero el formato no. El formato obligatorio aplica solo a estos reportes: el menú, las preguntas y los mensajes de rechazo son libres, siempre que sean claros. Los textos que imprime el programa van sin acentos ni "ñ", para evitar problemas de codificación en la terminal.

Ancho de cada columna:

| Columna | Caracteres | Alineación |
| --- | --- | --- |
| `#` | 4 | Izquierda |
| `POS` | 5 | Izquierda |
| `EQUIPO`, `LOCAL`, `RIVAL` y nombre en la matriz | 17 | Izquierda |
| `MARCADOR` | 10 | Izquierda |
| `PJ`, `PG`, `PE`, `PP`, `GF` y `GC` | 4 | Derecha |
| `PTS` | 5 | Derecha |
| Cada columna de la matriz | 6 | Derecha |

**Equipos registrados:**

```
--- EQUIPOS REGISTRADOS ---
#   EQUIPO
1   Aguilas
2   Halcones
3   Jaguares
4   Leones
5   Pumas
6   Tigres
```

**Resultados de los partidos:**

```
--- RESULTADOS DE LOS PARTIDOS ---
#   LOCAL            MARCADOR  VISITANTE
1   Aguilas          3 - 3     Halcones
2   Aguilas          3 - 1     Jaguares
3   Aguilas          4 - 0     Leones
4   Aguilas          2 - 0     Pumas
5   Aguilas          1 - 4     Tigres
6   Halcones         0 - 1     Jaguares
7   Halcones         0 - 5     Leones
8   Halcones         2 - 3     Pumas
9   Halcones         5 - 2     Tigres
10  Jaguares         0 - 1     Leones
11  Jaguares         5 - 1     Pumas
12  Jaguares         3 - 2     Tigres
13  Leones           5 - 3     Pumas
14  Leones           3 - 3     Tigres
15  Pumas            0 - 1     Tigres
```

**Tabla de posiciones:**

```
--- TABLA DE POSICIONES ---
POS  EQUIPO             PJ  PG  PE  PP  GF  GC  PTS
1    Aguilas             5   3   1   1  13   8   10
2    Leones              5   3   1   1  14  10   10
3    Jaguares            5   3   0   2  10   7    9
4    Tigres              5   2   1   2  12  12    7
5    Halcones            5   1   1   3  10  14    4
6    Pumas               5   1   0   4   7  15    3
```

PJ: jugados. PG: ganados. PE: empatados. PP: perdidos. GF: goles a favor. GC: goles en contra. PTS: puntos.

**Campeón, con empate en el primer lugar:**

```
--- CAMPEON DEL TORNEO ---
Hay un empate en el primer lugar con 10 puntos.
1. Aguilas
2. Leones
Elige al campeon: 2

Campeon: Leones
Puntos: 10
```

**Campeón, sin empate.** Este ejemplo es ilustrativo: el modo de prueba siempre produce un empate en el primer lugar.

```
--- CAMPEON DEL TORNEO ---
Campeon: Aguilas
Puntos: 10
```

**Ficha de equipo.** El marcador se muestra desde la perspectiva del equipo consultado:

```
--- FICHA DE EQUIPO ---
Equipo: Leones
Jugados: 5
Ganados: 3
Empatados: 1
Perdidos: 1
Goles a favor: 14
Goles en contra: 10
Puntos: 10

RIVAL            MARCADOR  RESULTADO
Aguilas          0 - 4     Perdido
Halcones         5 - 0     Ganado
Jaguares         1 - 0     Ganado
Pumas            5 - 3     Ganado
Tigres           3 - 3     Empatado
```

**Equipo no encontrado:**

```
--- FICHA DE EQUIPO ---
Equipo no encontrado: Toros
```

**Matriz de enfrentamientos.** Cada celda muestra primero los goles del equipo de la fila:

```
--- MATRIZ DE ENFRENTAMIENTOS ---
                    AGU   HAL   JAG   LEO   PUM   TIG
Aguilas             ---   3-3   3-1   4-0   2-0   1-4
Halcones            3-3   ---   0-1   0-5   2-3   5-2
Jaguares            1-3   1-0   ---   0-1   5-1   3-2
Leones              0-4   5-0   1-0   ---   5-3   3-3
Pumas               0-2   3-2   1-5   3-5   ---   0-1
Tigres              4-1   2-5   2-3   3-3   1-0   ---

Mejor ataque: Leones (14 goles a favor)
Mejor defensa: Jaguares (7 goles en contra)
```

**Mejor ataque, con empate.** Se escribe "goles" siempre, aunque la cantidad sea 1:

```
Mejor ataque: Leones, Tigres (14 goles a favor)
```

> **Nota de C++:** `setw(n)` de `<iomanip>` reserva `n` espacios para el siguiente dato, `left` lo alinea a la izquierda y `right` a la derecha. Por ejemplo, una fila de la tabla de posiciones inicia así:

```cpp
cout << left << setw(5) << posicion << setw(17) << nombre
     << right << setw(4) << jugados << setw(5) << puntos << endl;
```

> **Nota de C++:** `left` y `right` siguen activos hasta que los cambies, así que afectan lo que imprimas después. `setw`, en cambio, solo aplica al siguiente dato.

> **Nota de C++:** no incluyas el salto de línea en el texto con ancho: `setw(5) << "PTS\n"` cuenta `\n` como un carácter y descuadra la columna. Escribe `setw(5) << "PTS" << "\n"`.

> **Nota de C++:** para que `setw` trate un marcador como un solo dato, primero arma el texto con `to_string`:

```cpp
string marcador = to_string(golesLocal) + " - " + to_string(golesVisitante);
cout << left << setw(10) << marcador;
```

## 3. Módulos y responsables

### 3.1 Bloques

| Bloque | Responsable | Contenido |
| --- | --- | --- |
| 0 | Equipo | Registros y funciones comunes en `include/torneo.h` |
| 1 a 5 | Un integrante por módulo | Módulos 1 a 5 |
| 6 | Un integrante en equipos de 6; todo el equipo en equipos de 5 | Módulo 6 |
| 7 | Equipo | Menú e integración en `src/main.cpp` |

### 3.2 Contrato mínimo del módulo

Tu módulo debe cumplir todo lo siguiente. Cómo lo cumples es decisión tuya, y debes poder justificarla.

1. Vive en un archivo `.h` propio dentro de `include`, que solo tú modificas.
2. Tu archivo inicia con `#pragma once`.
3. Tiene al menos dos funciones propias, cada una con una sola tarea.
4. Recibe sus datos por parámetros, con el tipo de paso correcto.
5. Usa los registros del equipo.
6. Usa al menos un ciclo.
7. Usa constantes con nombre, en lugar de escribir valores como 6 o 15.
8. Reutiliza las funciones de `utilerias.h` y `torneo.h`, sin duplicar lógica.
9. Maneja al menos un caso de rechazo, con un mensaje claro. El módulo 3 queda exento, porque no interactúa con el usuario.
10. Demuestra los temas asignados en la sección 2.2.
11. Tiene su receta en pseudocódigo, escrita por ti antes de programar.

### 3.3 Bloques de equipo

- **Base común (bloque 0):** el equipo diseña sus registros y escribe las funciones comunes en `include/torneo.h`.
- **Integración (bloque 7):** el equipo escribe el menú en `src/main.cpp` y conecta todos los módulos.

- **Módulo 6 en equipos de 5:** su código vive en `include/matriz.h` y su documentación en `docs/modulo_6/modulo.md`. Ambos son archivos de equipo y no requieren propuesta de mejora adicional. Se evalúa como parte de la integración.

Los archivos de equipo deben tener aportaciones de todos los integrantes.

## 4. Entregables

| Entregable | Responsable | Ubicación |
| --- | --- | --- |
| Registros y funciones comunes | Equipo | `include/torneo.h` |
| Menú e integración | Equipo | `src/main.cpp` |
| README del equipo | Equipo | `README.md` |
| Código del módulo | Cada integrante | Archivo `.h` propio en `include` |
| Documentación, receta y reflexión | Cada integrante | `docs/<matrícula>/modulo.md` |
| Documentación del módulo 6 (equipos de 5) | Equipo | `docs/modulo_6/modulo.md` |
| Propuesta de mejora | Cada integrante | `docs/mejoras/<matrícula>/mejora.md` |

### 4.1 Documentación individual

Copia `docs/PLANTILLA_MODULO.md` a `docs/<matrícula>/modulo.md` y llena: autor, propósito, decisiones de diseño, receta, tabla de pruebas con casos límite, bitácora de dudas y errores, y reflexión. No modifiques la plantilla original.

### 4.2 Propuesta de mejora

Cada integrante propone una mejora o una corrección a la solución del equipo. Es solo diseño: no se programa.

- Copia `docs/mejoras/PLANTILLA_MEJORA.md` a `docs/mejoras/<matrícula>/mejora.md`. No modifiques la plantilla original.
- Inicia con la etiqueta "Propuesta de mejora elaborada por: " y tu nombre.
- Contenido mínimo: el impacto, los cambios necesarios en el diseño con su justificación, y una receta con los pasos nuevos y modificados.
- Puede tocar cualquier parte de la solución y se resuelve con los temas del parcial.
- Dentro de un equipo no puede haber dos propuestas iguales.

### 4.3 Cálculo a mano

El equipo ejecuta una corrida en modo aleatorio y copia los 15 resultados en el README. Con esos resultados, antes de consultar los demás reportes, calcula a mano la tabla, el campeón, el mejor ataque y la mejor defensa. Después ejecuta los reportes de esa misma corrida y compara: lo que imprime el programa debe coincidir.

Ejemplo del procedimiento, con datos de la sección 2.6:

| Módulo | Valores elegidos | Resultado esperado |
| --- | --- | --- |
| Tabla de posiciones | Leones: 3 ganados, 1 empatado, 1 perdido | 3 x 3 + 1 x 1 = 10 puntos |
| Matriz de enfrentamientos | Goles a favor de Leones: 0 + 5 + 1 + 5 + 3 | 14 goles, mejor ataque |

## 5. Repositorio base

Enlace: https://github.com/narizwallace/ulsa_ime_1_dp_parcial_3_torneo_futbol

Un solo integrante del equipo hace fork del repositorio base. Es un punto de partida: los archivos de los módulos los crea cada responsable.

| Archivo | Contenido |
| --- | --- |
| `PROYECTO.md` | Esta guía |
| `README.md` | Plantilla del equipo |
| `include/torneo.h` | Constantes compartidas |
| `include/utilerias.h` | Funciones de lectura y `numeroAleatorio`, ya implementadas |
| `include/escenario_prueba.h` | Marcadores del modo de prueba |
| `src/main.cpp` | Esqueleto que compila, con los pasos del escenario como comentarios |
| `docs/PLANTILLA_MODULO.md` | Plantilla de la documentación individual |
| `docs/mejoras/PLANTILLA_MEJORA.md` | Plantilla de la propuesta de mejora |
| `.gitignore` | Ignora el ejecutable y archivos del sistema |
| `.vscode/` | Configuración del editor |

Todos los archivos `.h` van en la carpeta `include` y contienen sus funciones completas, igual que `utilerias.h`. La carpeta `src` contiene solo `main.cpp`. Para incluir un archivo se escribe solo su nombre:

```cpp
#include "torneo.h"
```

Para compilar, desde la carpeta del proyecto:

```
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o torneo
```

Para ejecutar en macOS:

```
./torneo
```

Para ejecutar en Windows:

```
.\torneo.exe
```

## 6. Colaboración en GitHub

- Quien hizo el fork invita a los demás como colaboradores, y todos trabajan en ese repositorio.
- Cada quien hace commits desde su propia cuenta, con nombre y correo configurados.
- Los archivos de un módulo individual solo los modifica su responsable. En equipos de 5, el módulo 6 lo modifica todo el equipo.
- Se esperan al menos 8 commits por integrante. Lo más importante es que sean significativos: cada uno debe representar una contribución real al proyecto y tener un mensaje claro.
- La autoría se revisa con git-fame.

> **Importante:** un módulo sin commits de su responsable no recibe la calificación individual.

## 7. Entrega

- Fecha límite: lunes 23 de noviembre, 11:59 PM.
- Cada integrante entrega en Classroom, de forma individual, el enlace al repositorio del equipo.
- No se aceptan entregas a destiempo.

> **Importante:** si el repositorio tiene commits posteriores a la fecha límite, solamente se evaluará lo entregado dentro del tiempo permitido.

> **Importante:** quien no entregue su enlace a tiempo pierde 10 puntos de su evaluación individual.

## 8. Exposición

- Cada integrante presenta su módulo funcionando dentro del escenario. En equipos de 5, el equipo decide quién presenta el módulo 6.
- Cada integrante responde una pregunta sobre el módulo de un compañero.
- Cada integrante cierra con su propuesta de mejora.
- El equipo ejecuta el escenario completo y explica su cálculo a mano de la corrida aleatoria del README.

## 9. Evaluación

| Individual (60) | Puntos | Equipo (40) | Puntos |
| --- | --- | --- | --- |
| Código del módulo y buenas prácticas | 30 | Integración: escenario completo y formato de reportes | 25 |
| Documentación, receta y pruebas | 10 | README y receta del menú | 10 |
| Propuesta de mejora | 10 | Cálculo a mano que coincide con la salida | 5 |
| Exposición | 10 | | |

## 10. Criterios de aceptación

- [ ] El programa compila sin errores ni advertencias con el comando de la sección 5.
- [ ] El escenario obligatorio se ejecuta completo, con todos sus rechazos.
- [ ] Todos los reportes cumplen fielmente el formato.
- [ ] La corrida aleatoria del README coincide con su cálculo a mano.
- [ ] Cada módulo cumple los 11 puntos del contrato.
- [ ] No hay variables globales.
- [ ] Cada integrante tiene al menos 8 commits significativos.
- [ ] Están la documentación, la receta, las pruebas, la reflexión y la propuesta de mejora de cada integrante.
- [ ] En equipos de 5, está la documentación del módulo 6 en `docs/modulo_6/modulo.md`.
- [ ] El README está completo.
- [ ] Cada integrante entregó el enlace en Classroom.
