#include <iostream>
#include "funciones.h"
#include <cstdlib>
#include "rlutil.h"
using namespace std;
using namespace rlutil;


/// FUNCION PARA MOSTRAR EL MENU
void mostrarMenu(){

    cls(); // cls=Limpia toda la pantalla de la consola (similar a system("cls")).

    // COLOR PARA EL TITULO
    setColor(YELLOW); // Cambia el color del texto que se imprime después de esta función.

    // gotoxy=Mueve el cursor a la posición (x, y) en la consola para imprimir texto en un lugar específico.
    gotoxy(35, 3); cout << "  ____ _____ _   _ _____ ____      _    _        _    ";
    gotoxy(35, 4); cout << " / ___| ____| \\ | | ____|  _ \\    / \\  | |      / \\ ";
    gotoxy(35, 5); cout << "| |  _|  _| |  \\| |  _| | |_) |  / _ \\ | |     / _ \\  ";
    gotoxy(35, 6); cout << "| |_| | |___| |\\  | |___|  _ <  / ___ \\| |___ / ___ \\ ";
    gotoxy(35, 7); cout << " \\____|_____|_| \\_|_____|_| \\_\\/_/   \\_\\_____/_/   \\_\\";

    resetColor(); // Restablece el color del texto al color por defecto (blanco normalmente).
    // COLOR PARA LAS OPCIONES
    setColor(CYAN);

    // OPCIONES
    gotoxy(45, 10); cout << "1. Nueva partida (1 jugador)";
    gotoxy(45, 11); cout << "2. Nueva partida (2 jugadores)";
    gotoxy(45, 12); cout << "3. Ver puntuacion mas alta";
    gotoxy(45, 13); cout << "4. Ver creditos";
    gotoxy(45, 14); cout << "5. Salir";

    resetColor();
    setColor(WHITE);


}


/// FUNCION PARA HACER UNA PAUSA Y LIMPIAR PANTALLA
void limpiarPantalla(){
    anykey("Presiona una tecla para continuar..."); // Muestra un mensaje y espera que el usuario presione cualquier tecla antes de continuar.
    cls();
}


/// FUNCION QUE MISTRA LOS CREDITOS
void mostrarCreditos(){
    cout << "************************* CREDITOS ************************" << endl;
    cout << "----------------------------------------------------------" <<endl;
    cout << "PROGRAMACION I - UNIVERSIDAD TECNOLOGICA NACIONAL (FRGP)" << endl;
    cout << "----------------------------------------------------------"<<endl;
    cout << "GRUPO 9" << endl;
    cout << "----------------------------------------------------------"<<endl;
    cout << "- INTEGRANTES DEL GRUPO - " << endl;
    cout << "- FRANCISCO CRISTIANI - LEGAJO: 32383 " << endl;
    cout << "- FRANCISCO SACKMANN - LEGAJO: 33257 " << endl;
    cout << "- FRANCO PACHECHO - LEGAJO: 34045" << endl;
    cout << "- RODRIGO GODOY- LEGAJO: 33198 " << endl;

    limpiarPantalla();
}



/// FUNCION PRINCIPAL PARA MODO UN JUGADOR
void jugarUnJugador(int &puntajeTotal, string &nombre, string &maxJugador, int &maxPuntaje){ /// Se pasa las variable por referencia para modificar la variable original y tenerla en el main

    cout << "Ingrese su nombre: ";
    cin >> nombre; // LE PEDIMOS EL NOMBRE

    puntajeTotal = 0; // inicializamos el cont. en cero

    int cantDados = 5; // VARIABLE PARA CANT. DE DADOS
    int dados[5]; // VEC CON EL TAMAÑO DE la variable cantDados

    // SE DETERMINA SI SE USA MODO MANUAL
    bool mManual = false; // SE TOMA UN BOOLEANO PARA DETERMINAR SI SE USA EL MODO MANUAL

    char modomanual; // char para que el usuario responda con S/N

    while (true){
        cout << "Desea activar el modo manual? (S/N) :" << endl;
        cin >> modomanual;
        if (modomanual == 's' || modomanual == 'S'){
            cout << "Modo Manual ACTIVADO" << endl;
            mManual = true;
            break;
        }else if (modomanual == 'n' || modomanual == 'N'){
            cout << "Modo Manual DESACTIVADO" << endl;
            break;
        }else cout << "Caracter Invalido: Ingrese (S/N)..." << endl;
            limpiarPantalla();
        // SE PIDE S/N SI ES S SE VUELVE TRUE mManual SI ES N NO CAMBIA SI NO ES NINGUNA SE VUELVE AL MENU
      }
    limpiarPantalla();

    bool generalaServida = false; // inicializamos la variable en false
    int rondaJugada = 0; // inicializamos la rindajugada en 0

    // FOR PARA LA CANT. DE RONDAS
    for(int ronda = 1; ronda <=10; ronda++){
        rondaJugada = ronda;

        // INFO VISIBLE PARA EL USUARIO
        cout << "----------------------------------------------------------" <<endl;
        cout << "Turno de: " << nombre << " | Ronda : " << ronda << " | Puntaje total: " << puntajeTotal << " PTS." << endl;

        int numeroLanzamiento = 1; // VARIABLE PARA GUARDAR QUE LANZAMIENTOS ES
        bool jugadorPlantado = false; // VARIABLE INICIALIZADA EN FALSE
        char respuestaJugador, respuestaJugador2; // VAIRABLES TIPO CHAR PARA QUE RESPONDA EL JUGADOR CON S/N

        int puntajeRonda = 0; // INICIALIZAMOS EL CONT. EN CERO

        // MIENTRAS EL LANZAMIENTO SEA < 3 Y EL JUGADOR NO ESTE PLANTADO SIGUE
        while(numeroLanzamiento <= 3 && !jugadorPlantado){
        // SI ES 1 SE TIRAN DADOS Y SE MUESTRA
            if(numeroLanzamiento == 1){
        // MANDAMOS COMO PARAMETROS DADOS Y CANTDADOS PARA GENERE LOS DADOS, Y MMANUAL PARA QUE VEA SI MODO MANUAL O NO
                tirarDados(dados, cantDados, mManual);
                mostrarDados(dados, cantDados, 1);

            }else {
                cout << "CONTINUAR LANZANDO? (S/N): ";
                cin >> respuestaJugador; // PREGUNTO SI QUIERE SEGUIR TIRANDO ALGUN DADO

                if (respuestaJugador == 'N' || respuestaJugador == 'n') {
                    jugadorPlantado = true; // SI EL JUGADOR SE PLANTA SALIMOS DEL WHILE

                } else if (respuestaJugador == 'S' || respuestaJugador == 's') {
                    // SI EL JUGADOR QUIERE TIRAR TODOS
                    cout << "DESEA TIRAR TODOS? (S/N): ";
                    cin >> respuestaJugador2;

                    if (respuestaJugador2 == 'S' || respuestaJugador2 == 's') {
                        //OPCION DE TIRAR TODOS
                        tirarDados(dados, cantDados, mManual);
                        mostrarDados(dados, cantDados, numeroLanzamiento);

                    } else if (respuestaJugador2 == 'N' || respuestaJugador2 == 'n') {
                        //OPCION DE TIRAR ALGUNOS
                        int cantidadARelanzar;
                        cout << "CUANTOS DADOS VOLVES A TIRAR?: ";
                        cin >> cantidadARelanzar; // PIDO CUANTOS QUIERE TIRAR

                        for (int i=0; i < cantidadARelanzar; i++){
                            int posicionDado;
                            cout << "CUAL DADO?: ";
                            cin >> posicionDado; // PREGUNTO CUAL DE TODOS

                            int indice = posicionDado - 1; // HAGO UN -1, PQ EL VEC VA DE 0 A 4


                            if(indice < 0 || indice >= cantDados){
                                cout << "Posicion invalida. Debe ser un dado entre 1 y 5." << endl;
                                i--;
                                continue;
                            }

                            if(mManual){

                                int valorRelanzar;
                                do {
                                    cout << "Seleccionar Valor para dado " << posicionDado << ": ";
                                    cin >> valorRelanzar;
                                } while (valorRelanzar < 1 || valorRelanzar > 6);
                                dados[indice] = valorRelanzar;
                            } else {

                                dados[indice] = 1+ (rand()% 6); // SE GENERA UN DADO ALETORIO NUEVO
                            }
                        }
                        mostrarDados(dados, cantDados, numeroLanzamiento); // MUESTRO LOS NUEVOS DADOS
                    }

                } else {
                    // Si la respuesta a "CONTINUAR LANZANDO?" no es S ni N
                    cout << "Respuesta invalida. Por favor, ingrese S o N." << endl;
                    continue; // Vuelve al inicio del while sin sumar un lanzamiento
                }
            }
            if(!jugadorPlantado) {
                numeroLanzamiento++; // CONT++ PARA QUE NO SE PASE DE LOS 3 PERMITIDOS
            }
        }


        /// LOGICA DEL PUNTAJE
        int conteo[6];
        contarDados(dados, conteo); // LLAMO LA FUNCION CONTAR DADOS, PARA CONTAR LOS DADOS RECIBIDOS

        combinaciones(conteo, puntajeRonda, numeroLanzamiento - 1);

        if(puntajeRonda == 60 && (numeroLanzamiento - 1) == 1){
            generalaServida = true;
        }

        cout << "----------------------------------------------------------" <<endl;
        cout << "FIN DE LOS LANZAMIENTOS" << endl;
        cout << "PUNTAJE DE LA RONDA: " << puntajeRonda << " PTS." << endl;
        puntajeTotal += puntajeRonda;



        limpiarPantalla();

        if (generalaServida){
            cout << "Juego finalizado." << endl;
            break;
        }
    }

    /// FIN DEL JUEGO
    cout << "----------------------------------------------------------" <<endl;
    cout << "FIN DEL JUEGO"<< endl;
    cout << "RONDAS JUGADAS: " << rondaJugada << " rondas" << endl;
    cout << "Puntaje final de "<< nombre << ": " << puntajeTotal << " PTS" << endl;
    cargarPuntaje(nombre, puntajeTotal, maxJugador, maxPuntaje); // CARGO EL PUNTAJE PARA VER SI ES EL MAS ALTO Y GAURDARLO JUNTO CON EL NOMBRE

    limpiarPantalla();
}



/// FUNCION PRINCIPAL DEL MODO DOS JUGADORES
void jugarDosJugadores(string &maxJugador, int &maxPuntaje) {
    int puntajeJ1 = 0, puntajeJ2 = 0; // INICIALIZO LAS VARIABLES DE PUNTAJE EN CERO Y DE NOMBRE
    string nombreJ1, nombreJ2;
    // PIDO LOS DOS NOMBRES
    cout << "Ingrese nombre del Jugador 1: ";
    cin >> nombreJ1;
    cout << "Ingrese nombre del Jugador 2: ";
    cin >> nombreJ2;

    // FUNCION COPIADA DEL MODO UN JUGADOR
    bool mManual = false;  // siempre automático en modo 2 jugadores

    for (int ronda = 1; ronda <= 10; ronda++) {
        cout << "Ronda " << ronda << " - Turno de " << nombreJ1 << endl;
        jugarTurno(puntajeJ1, nombreJ1, mManual, maxJugador, maxPuntaje);

        cout << "Ronda " << ronda << " - Turno de " << nombreJ2 << endl;
        jugarTurno(puntajeJ2, nombreJ2, mManual, maxJugador, maxPuntaje);
    }
    // COMPARACION PARA VER QUIEN GANO
    cout << "----------------------------------------------------------\n";
    cout << "RESULTADOS FINALES:\n";
    cout << nombreJ1 << ": " << puntajeJ1 << " PTS\n";
    cout << nombreJ2 << ": " << puntajeJ2 << " PTS\n";

    if (puntajeJ1 > puntajeJ2)
        cout << "GANADOR: " << nombreJ1;
    else if (puntajeJ2 > puntajeJ1)
        cout << "GANADOR: " << nombreJ2;
    else {
        cout << "EMPATE!! SE DEFINE POR SUERTE";

        bool empate = true;

        while(empate) {
            int dado1 = 1 + rand() % 6;
            int dado2 = 1 + rand() % 6;

            cout << nombreJ1 << " tira un " << dado1 << endl;
            cout << nombreJ2 << " tira un " << dado2 << endl;

            if (dado1 > dado2) {
                cout << "¡GANA " << nombreJ1 << "! QUE SUERTE" << endl;

                empate = false;
            }
            else if (dado2 > dado1) {
                cout << "¡GANA " << nombreJ2 << "! QUE SUERTE" << endl;

                empate = false;
            }
            else {
                cout << "¡EMPATE OTRA VEZ, TIRAN DE NUEVO!" << endl;
            }
        }
    }
    cout << "----------------------------------------------------------\n";
    limpiarPantalla();
}



/// FUNCION DE MODO UN JUGADOR PARA DOS JUGADORES
void jugarUnJugador2(int &puntajeTotal, string &nombre, string &maxJugador, int &maxPuntaje){

    puntajeTotal = 0;

    int cantDados = 5; // VARIABLE PARA CANT. DE DADOS
    int dados[5]; // VEC CON EL TAMAÑO DE LOS DADOS QUE NECESITAMOS
    bool mManual = false; // mManual es siempre false en modo 2 jugadores

    bool generalaServida = false;

    //FOR PARA LA CANT. DE RONDAS
    for(int ronda = 1; ronda <=10; ronda++){

        // INFO VISIBLE PARA EL USUARIO
        cout << "----------------------------------------------------------" <<endl;
        cout << "Turno de: " << nombre << " | Ronda : " << ronda << " | Puntaje total: " << puntajeTotal << " PTS." << endl;

        int numeroLanzamiento = 1; // VARIABLE PARA GUARDAR QUE LANZAMIENTOS ES
        bool jugadorPlantado = false;
        char respuestaJugador, respuestaJugador2 = 'n';

        int puntajeRonda = 0;

        // MIENTRAS EL LANZAMIENTO SEA < 3 Y EL JUGADOR NO ESTE PLANTADO SIGUE
        while(numeroLanzamiento <= 3 && !jugadorPlantado){
        // SI ES 1 SE TIRAM DADOS Y SE MUESTRAM
            if(numeroLanzamiento == 1){
                tirarDados(dados, cantDados, mManual);
                mostrarDados(dados, cantDados, 1);

            } else {
                cout << "CONTINUAR LANZANDO? (S/N)";
                cin >> respuestaJugador; // PREGUNTO SI QUIERE SEGUIR TIRANDO ALGUN DADO

                if (respuestaJugador == 'N' || respuestaJugador == 'n') {
                    jugadorPlantado = true; // EL JUG SE PLANTA

                } else if (respuestaJugador == 'S' || respuestaJugador == 's') {
                    cout << "DESEA TIRAR TODOS? ";
                    cin >> respuestaJugador2;

                    if (respuestaJugador2 == 'S' || respuestaJugador2 == 's' ) {
                        tirarDados(dados, cantDados, mManual);
                        mostrarDados(dados, cantDados, numeroLanzamiento);

                    } else if (respuestaJugador2 == 'N' || respuestaJugador2 == 'n') {
                        int cantidadARelanzar;
                        cout << "CUANTOS DADOS VOLVES A TIRAR?: ";
                        cin >> cantidadARelanzar; // PIDO CUANTOS QUIERE TIRAR

                        for (int i=0; i < cantidadARelanzar; i++){
                            int posicionDado;
                            cout << "CUAL DADO?: ";
                            cin >> posicionDado; // PREGUNTO CUAL DE TODOS

                            int indice = posicionDado - 1; // HAGO UN -1, PQ EL VEC VA DE 0 A 4

                            if(indice < 0 || indice >= cantDados){
                                cout << "Posicion invalida. Debe ser un dado entre 1 y 5." << endl;
                                i--; // SE REPITE LA VUELTA
                                continue;
                            }

                            dados[indice] = 1+ (rand()% 6); // SE GENERA UN DADO ALETORIO NUEVO
                        }
                        mostrarDados(dados, cantDados, numeroLanzamiento); // MUESTRO LOS NUEVOS DADOS
                    }
                } else {
                    // SI LA RESPUESTA NO ES S NI N
                    cout << "Respuesta invalida. Por favor, ingrese S o N." << endl;
                    continue; // VUELVE AL INICIO SIN SUMAR LANZAMIENTO
                }
            }
            if(!jugadorPlantado) {
                numeroLanzamiento++; // CONT++ PARA QUE NO SE PASE DE LOS 3 PERMITIDOS
            }
        }

        /// LOGICA DEL PUNTAJE
        int conteo[6];
        contarDados(dados, conteo); // LLAMO LA FUNCION CONTAR DADOS, PARA CONTAR LOS DADOS RECIBIDOS
        combinaciones(conteo, puntajeRonda, numeroLanzamiento - 1);

        if(puntajeRonda == 50 && (numeroLanzamiento - 1) == 1){
            generalaServida = true;
        }

        cout << "----------------------------------------------------------" <<endl;
        cout << "FIN DE LOS LANZAMIENTOS" << endl;
        cout << "PUNTAJE DE LA RONDA: " << puntajeRonda << " PTS." << endl;
        puntajeTotal += puntajeRonda; // GUARDO EL PUNTAJE TOTAL EN UNA VARIBLE, ASI LO DEVUELVO COMO REFERENCIA

        limpiarPantalla();

        if(generalaServida){
            break;
        }
    }

    /// FIN DEL JUEGO
    cout << "----------------------------------------------------------" <<endl;
    cout << "FIN DEL JUEGO"<< endl;
    cout << "Puntaje final de "<< nombre << ": " << puntajeTotal << " PTS" << endl;
    cargarPuntaje(nombre, puntajeTotal, maxJugador, maxPuntaje); // CARGO EL PUNTAJE PARA VER SI ES EL MAS ALTO Y GAURDARLO JUNTO CON EL NOMBRE

    limpiarPantalla();
}


void jugarTurno(int &puntajeTotal, string nombre, bool mManual, string &maxJugador, int &maxPuntaje) {

    const int cantDados = 5;
    int dados[cantDados];
    int numeroLanzamiento = 1;
    bool jugadorPlantado = false;
    char respuestaJugador, respuestaJugador2;
    int puntajeRonda = 0;

    cout << "----------------------------------------------------------" << endl;
    cout << "Turno de: " << nombre << " | Puntaje total: " << puntajeTotal << " PTS." << endl;

    while (numeroLanzamiento <= 3 && !jugadorPlantado) {
        if (numeroLanzamiento == 1) {
            tirarDados(dados, cantDados, mManual);
            mostrarDados(dados, cantDados, numeroLanzamiento);
        } else {
            cout << "CONTINUAR LANZANDO? (S/N): ";
            cin >> respuestaJugador;

            if (respuestaJugador == 'N' || respuestaJugador == 'n') {
                jugadorPlantado = true;
            } else if (respuestaJugador == 'S' || respuestaJugador == 's') {
                cout << "DESEA TIRAR TODOS? (S/N): ";
                cin >> respuestaJugador2;

                if (respuestaJugador2 == 'S' || respuestaJugador2 == 's') {
                    tirarDados(dados, cantDados, mManual);
                    mostrarDados(dados, cantDados, numeroLanzamiento);
                } else {
                    int cantidadARelanzar;
                    cout << "CUANTOS DADOS VOLVES A TIRAR?: ";
                    cin >> cantidadARelanzar;

                    for (int i = 0; i < cantidadARelanzar; i++) {
                        int posicionDado;
                        cout << "CUAL DADO?: ";
                        cin >> posicionDado;

                        int indice = posicionDado - 1;
                        if (indice < 0 || indice >= cantDados) {
                            cout << "Posicion invalida." << endl;
                            i--;
                            continue;
                        }

                        if (mManual) {
                            int valor;
                            do {
                                cout << "Seleccionar Valor para dado " << posicionDado << ": ";
                                cin >> valor;
                            } while (valor < 1 || valor > 6);
                            dados[indice] = valor;
                        } else {
                            dados[indice] = 1 + (rand() % 6);
                        }
                    }

                    mostrarDados(dados, cantDados, numeroLanzamiento);
                }
            } else {
                cout << "Respuesta invalida. Por favor, ingrese S o N." << endl;
                continue;
            }
        }

        if (!jugadorPlantado) numeroLanzamiento++;
    }

    int conteo[6];
    contarDados(dados, conteo);
    combinaciones(conteo, puntajeRonda, numeroLanzamiento - 1);

    cout << "----------------------------------------------------------" << endl;
    cout << "FIN DEL TURNO" << endl;
    cout << "PUNTAJE DEL TURNO: " << puntajeRonda << " PTS." << endl;

    puntajeTotal += puntajeRonda;

    cargarPuntaje(nombre, puntajeTotal, maxJugador, maxPuntaje);
    limpiarPantalla();
}



/// FUNCION PARA TIRAR DADOS
void tirarDados(int dados[], int cantidad, bool mManual){ // mandamos como parametros dados, cantidad y mManual para que procese todo
    if (!mManual){ // SI ES TRUE, SE GENERAN LOS DADOS AUTOMATICAMENTE
        for (int i=0; i< cantidad; i++){
            dados[i] = (rand()% 6) + 1; // FOR PARA GENERAR DADOS ALEATORIOS,
        }
    } else { // SI ES FALSE SE GENERAN MANUALMENTE
        for (int i=0; i< cantidad; i++){ // FOR QUE TERMINA HASTA QUE LLEGUE CANT=5
        int valorDado;
        do{ // PIDO EL VALOR DE LOS DADOS HASTA QUE SEAN 5 Y TERMINE
            cout << "Seleccionar Valor para dado " << (i+1) << ": ";
            cin >> valorDado;
        }while (valorDado < 1 || valorDado > 6);
        dados[i] = valorDado; // ASIGNO EL VALOR DEL DADO A CADA BLOQUE DE MEMORIA DEL VEC
    }
    }

}


/// FUNCION PARA MOSTRAR DADOS EN PANTALLA
void mostrarDados(int dados[], int cantidad, int numLanzamiento){ // mandamos como parametro dados, cantidad y numLanzamiento para que procese todo
    cout << "Lanzamiento " << numLanzamiento << endl; // mostramos el num. de lanzamiento
    cout << "Tus dados: "; // mostramos dados con el ope. de abajo

    for(int i = 0; i<cantidad; i++){
        cout << dados[i] << " "; // FOR PARA RECORRER EL VEC Y MOSTRAR LOS DADOS
    }
    cout << endl;

}


/// FUNCION PARA CONTAR DADOS
void contarDados(int dados[], int conteo[]){ // mandamos como parametros dados y conteo para que procese todo
    for ( int i = 0; i < 6; i++){ // for para recorrer los bloqs. de memoria del vec
        conteo [i]=0; // inicializo el vec en cero en cada bloq. de memoria
    }

    for(int i = 0; i<5; i++){
        int valorDado = dados[i]; // guardo los valores del vec dados en valor dado
                                  //para recorrer num por num
        conteo[valorDado -1]++;   //y contar cuantos se repiten
    }
}



/// FUNCION PARA CALCULAR LAS COMBINACIONES Y DETERMINAR EL PUNTAJE
void combinaciones(int conteo[], int &puntajeRonda, int numLanzamiento){
    // ponemos todas las posibilidades en false
    bool hayGenerala = false;
    bool hayPoker = false;
    bool hayDos = false;
    bool hayTres = false;
    bool hayEscalera1 = (conteo[0] == 1 && conteo[1] == 1 && conteo[2] == 1 && conteo[3] == 1 && conteo[4] == 1);
    bool hayEscalera2 = (conteo[1] == 1 && conteo[2] == 1 && conteo[3] == 1 && conteo[4] == 1 && conteo[5] == 1);
    // BOOL PARA DETERMINAR QUE COMBINACION DA TRUE
    // da true o false segun el conteo que se haga
    for(int i = 0; i<6; i++){
        if (conteo[i]== 5) hayGenerala = true;
        if (conteo[i]== 4) hayPoker = true;
        if (conteo[i]== 2) hayDos = true;
        if (conteo[i]== 3) hayTres = true;
       }
    // SI DA TRUE ALGUNA COMBINACION SE AÑADE AL PUNTAJE

    if(hayGenerala && numLanzamiento == 1){ // GENERALA SERVIDA
        cout << "¡¡GENERALA SERVIDA!! +60 PUNTOS" << endl;
        puntajeRonda += 60;
    } else if(hayGenerala){
        puntajeRonda += 50;
    } else if(hayPoker){
        puntajeRonda += 40;
    } else if (hayDos && hayTres){
        puntajeRonda += 30;
    } else if (hayEscalera1 || hayEscalera2){
        puntajeRonda += 25;
    } else { // SI NO HAY COMBINACION POSIBLE, SE UTILIZA LOS JUEGOS DE DADOS

    int puntajeMaxJuegoMenor = 0; // si todo da false inicializamos en cero la variable

    for(int i = 0; i<6; i++){ // for para recorrer conteo
        int puntajeActual = conteo[i] * (i+1); // cuenta para cuando no hay combinaciones
        if(puntajeActual > puntajeMaxJuegoMenor){ // if para ver la combi mas alta
            puntajeMaxJuegoMenor = puntajeActual;
        }
    }
    puntajeRonda += puntajeMaxJuegoMenor; // sumamos lo que da al puntaje de la ronda
    }
}



/// FUNCION PARA SABER EL PUNTAJE MAS ALTO DE TODAS LAS PARTIDAS JUGADAS
void cargarPuntaje(string nombre, int puntajeTotal, string &maxJugador, int &maxPuntaje){
    if (puntajeTotal > maxPuntaje){
        maxJugador = nombre;
        maxPuntaje = puntajeTotal;
    }
}



/// FUNCION QUE MUESTRA LOS PUNTAJES
void mostrarPuntaje(string maxJugador, int maxPuntaje) {
    cout << "************************* Puntaje ************************" << endl;
    cout << "----------------------------------------------------------" <<endl;
    cout << "----------------------------------------------------------" <<endl;
    if (maxJugador == "") {
        cout << "No hay puntajes actualmente." << endl << endl;
        limpiarPantalla();
        return;
    }
    cout << endl << "Mejor jugador: " << maxJugador<< " con " << maxPuntaje << " Puntos." << endl << endl;
    cout << endl;
    limpiarPantalla();
}
