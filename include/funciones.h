#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>

using namespace std;

/// MENU Y PANTALLA
void mostrarMenu();
void limpiarPantalla();
void mostrarCreditos();

/// MODO UN JUGADOR
void jugarUnJugador(int &puntajeTotal, string &nombre, string &maxJugador, int &maxPuntaje);

/// MODO DOS JUGADORES
void jugarDosJugadores(string &maxJugador, int &maxPuntaje);
void jugarUnJugador2(int &puntajeTotal, string &nombre, string &maxJugador, int &maxPuntaje);
void jugarTurno(int &puntajeTotal, string nombre, bool mManual, string &maxJugador, int &maxPuntaje);

/// MECANICAS DEL JUEGO
void tirarDados(int dados[], int cantidad, bool mManual);
void mostrarDados(int dados[], int cantidad, int numLanzamiento);
void contarDados(int dados[], int conteo[]);
void combinaciones(int conteo[], int &puntajeRonda, int numLanzamiento);

/// PUNTAJE
void cargarPuntaje (string nombre, int puntajeTotal, string &maxJugador, int &maxPuntaje);
void mostrarPuntaje(string maxJugador, int maxPuntaje);

#endif
