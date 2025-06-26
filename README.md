# Juego-3-en-raya
Proyecto asignatura Introducción a la Programación de desarrollo del famoso juego del 3 en raya en el que dos jugadores pueden enfrentarse con un tablero de tamaño definido por el usuario.

## Descripción

Este proyecto implementa el juego del 3 en raya para dos jugadores en la terminal. Permite elegir el tamaño del tablero (mínimo 3x3), ingresar los nombres de los jugadores y alternar turnos colocando fichas hasta que uno gane o haya empate.

## Cómo compilar

Puedes compilar el proyecto usando CMake y un compilador compatible.

### Usando CMake y GCC/MinGW

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

O directamente con GCC:

```sh
gcc -std=c99 -o 3enraya main.c
```

## Cómo jugar

1. Ejecuta el programa:
   ```sh
   ./3enraya
   ```
2. Ingresa los nombres de los jugadores.
3. Elige quién empieza (X u O).
4. Selecciona el tamaño del tablero (mínimo 3).
5. Introduce las coordenadas para colocar tu ficha en cada turno.
6. El juego termina cuando alguien gana o hay empate. Puedes elegir jugar otra partida.

## Archivos principales

- [`main.c`](main.c): Código fuente principal del juego.

## Requisitos

- Compilador C compatible con C99 (GCC, MinGW, MSVC, etc.)
- CMake (opcional, para compilación multiplataforma)

## Créditos

Desarrollado por AGR..

---
¡Disfruta jugando al 3 en raya!
