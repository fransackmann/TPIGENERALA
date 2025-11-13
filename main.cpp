#include <iostream>
#include "funciones.h"
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
using namespace rlutil;
using namespace std;

int main(){

    srand(time(NULL)); ///PARA QUE RAND GENERE NUMEROS ALEATORIOS TODAS LAS PARTIDAS
    int opcion;
    int puntajeTotal = 0;
    string nombre;
    string maxJugador = "";
    int maxPuntaje = 0;
    ///MOSTRAR MENU
    do{
        mostrarMenu();

        gotoxy(45,17);
        cout << "- SELECCIONE UNA OPCION: " << endl;
        cin >> opcion;

        cls();

        switch(opcion){
            case 1: {
                /// PARTIDA UN JUGADOR
                jugarUnJugador(puntajeTotal, nombre, maxJugador, maxPuntaje);
                break;
            }
            case 2:
                /// PARTIDA DOS JUGADORES
                jugarDosJugadores(maxJugador, maxPuntaje);
                break;
            case 3:
                /// VER PUNTAJE MAXIMO
                mostrarPuntaje(maxJugador, maxPuntaje);
                break;
            case 4:
                /// VER CREDITOS
                mostrarCreditos();
                break;
            case 5:
                /// SALIR
                cout << "Saliendo del juego..." << endl;
                break;
            default:
                /// OPCION NO VALIDA
                cout << "Opcion no valida, intentalo de nuevo" << endl;
                limpiarPantalla();
                break;
        }

    }while(opcion!=5);

    return 0;
}
