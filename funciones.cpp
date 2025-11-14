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
    // couts para mostrar los creditoos
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

    limpiarPantalla(); // limpiamos pantalla
}



/// FUNCION PRINCIPAL PARA MODO UN JUGADOR
void jugarUnJugador(int &puntajeTotal, string &nombre, string &maxJugador, int &maxPuntaje){ /// Se pasa las variable por referencia para modificar la variable original

    cout << "Ingrese su nombre: ";
    cin >> nombre; // LE PEDIMOS EL NOMBRE

    puntajeTotal = 0; // inicializamos el cont. en cero

    int cantDados = 5; // VARIABLE PARA CANT. DE DADOS
    int dados[5]; // VEC CON EL TAMAÑO DE la variable cantDados

    bool mManual = false; // SE TOMA UN BOOLEANO PARA DETERMINAR SI SE USA EL MODO MANUAL

    char modomanual; // char para que el usuario responda con S/N

    // while que sigue hasta que haya s/n ingresado por el usuario
    while (true){

        cout << "Desea activar el modo manual? (S/N) :" << endl;
        cin >> modomanual; // preguntamos al usuario

        if (modomanual == 's' || modomanual == 'S'){ // si es true se activa el modo manual
            cout << "Modo Manual ACTIVADO" << endl;
            mManual = true;
            break; // cierre del ciclo while
        }

        else if (modomanual == 'n' || modomanual == 'N'){ // si es false no se activa
            cout << "Modo Manual DESACTIVADO" << endl;
            break; // cierre del ciclo while
        }

        else {
            cout << "Caracter Invalido: Ingrese (S/N)..." << endl; // si no se ingresa S o N, te sigue preguntado
            limpiarPantalla(); // limpiamos pantalla
        }
    }

    limpiarPantalla(); // limpiamos pantalla

    bool generalaServida = false; // inicializamos la variable en false
    int rondaJugada = 0; // inicializamos la rindajugada en 0

    // FOR PARA LA CANT. DE RONDAS
    for(int ronda = 1; ronda <=10; ronda++){

        rondaJugada = ronda;

        // INFO VISIBLE PARA EL USUARIO
        cout << "----------------------------------------------------------" <<endl;
        cout << "Turno de: " << nombre << " | Ronda : " << ronda << " | Puntaje total: " << puntajeTotal << " PTS." << endl;

        int numeroLanzamiento = 1; // VARIABLE PARA GUARDAR EL NUMERO DE LANZAMIENTO
        bool jugadorPlantado = false; // VARIABLE INICIALIZADA EN FALSE, PARA VER SI SE PLANTA O NO EL JUGADOR
        char respuestaJugador, respuestaJugador2; // VAIRABLES TIPO CHAR PARA QUE RESPONDA EL JUGADOR CON S/N

        int puntajeRonda = 0; // INICIALIZAMOS EL CONT. EN CERO

        // MIENTRAS EL LANZAMIENTO SEA < 3 Y EL JUGADOR NO ESTE PLANTADO SIGUE
        while(numeroLanzamiento <= 3 && !jugadorPlantado){
        // SI ES 1 SE TIRAN DADOS Y SE MUESTRA
            if(numeroLanzamiento == 1){
        // MANDAMOS COMO PARAMETROS DADOS Y CANTDADOS PARA GENERE LOS DADOS, Y MMANUAL PARA QUE VEA SI MODO MANUAL O NO
                tirarDados(dados, cantDados, mManual);
                mostrarDados(dados, cantDados, 1);

            }

            else {
                cout << "CONTINUAR LANZANDO? (S/N): ";
                cin >> respuestaJugador; // PREGUNTO SI QUIERE SEGUIR TIRANDO ALGUN DADO

                if (respuestaJugador == 'N' || respuestaJugador == 'n') { // IF PARA SABER SI NO SE QUISO PLANTAR
                    jugadorPlantado = true; // SI EL JUGADOR SE PLANTA SALIMOS DEL WHILE

                } else if (respuestaJugador == 'S' || respuestaJugador == 's') { // IF PARA SABER SI SE QUISO PLANTAR

                    cout << "DESEA TIRAR TODOS? (S/N): ";
                    cin >> respuestaJugador2; // LE PREGUNTAMOS SI QUIERE TIRAR TODOS

                    if (respuestaJugador2 == 'S' || respuestaJugador2 == 's') { // SI ES TRUE TIRAMOS TODOS LOS DADOS DE VUELTA

                        tirarDados(dados, cantDados, mManual);
                        mostrarDados(dados, cantDados, numeroLanzamiento);

                    } else if (respuestaJugador2 == 'N' || respuestaJugador2 == 'n') { // SI ES FALSE PREGUNTAMOS LA CANTIDAD

                        int cantidadARelanzar;

                        cout << "CUANTOS DADOS VOLVES A TIRAR?: ";
                        cin >> cantidadARelanzar; // PIDO CUANTOS QUIERE TIRAR

                        for (int i=0; i < cantidadARelanzar; i++){ // FOR PARA PREGUNTAR CUAL DADO?, LA CANT. QUE HAYA PEDIDO

                            int posicionDado;

                            cout << "CUAL DADO?: ";
                            cin >> posicionDado; // PREGUNTO CUAL DE TODOS

                            int indice = posicionDado - 1; // HAGO UN -1, PQ EL VEC VA DE 0 A 4


                            if(indice < 0 || indice >= cantDados){ // if para controlar que sea una posicion valida
                                cout << "Posicion invalida. Debe ser un dado entre 1 y 5." << endl;
                                i--;
                                continue; // para que vuelva a atras y pregunte
                            }

                            if(mManual){ // si el modo manual es true sigue esto

                                int valorRelanzar; // inicializamos variable

                                do {

                                    cout << "Seleccionar Valor para dado " << posicionDado << ": ";
                                    cin >> valorRelanzar; // preguntamos el num del dado

                                } while (valorRelanzar < 1 || valorRelanzar > 6); // suge mientras sea un num del 1 al 6

                                dados[indice] = valorRelanzar; // guardamos el valor de cada dado en el vec

                            } else { // si es false el mode manual

                                dados[indice] = 1+ (rand()% 6); // SE GENERA UN DADO ALETORIO NUEVO

                            }
                        }

                        mostrarDados(dados, cantDados, numeroLanzamiento); // MUESTRO LOS NUEVOS DADOS

                    }

                }
                else {

                    // Si la respuesta a "CONTINUAR LANZANDO?" no es S ni N
                    cout << "Respuesta invalida. Por favor, ingrese S o N." << endl;
                    continue; // Vuelve al inicio del while sin sumar un lanzamiento

                }
            }

            if(!jugadorPlantado) {

                numeroLanzamiento++; // CONT++ PARA QUE NO SE PASE DE LOS 3 PERMITIDOS

            }
        }


        // LOGICA DEL PUNTAJE

        int conteo[6]; // vec de 6 para contar las 6 caras del dado

        contarDados(dados, conteo); // LLAMO LA FUNCION CONTAR DADOS, PARA CONTAR LOS DADOS RECIBIDOS

        //NUMERO DE LANZAMIENTO -1 PQ SI NO CUENTA 4 LANZAMIENTOS
        combinaciones(conteo, puntajeRonda, numeroLanzamiento - 1); // LLAMO LA FUNCION COMBINACIONES PARA QUE CON LOS DADOS CONTADOS VEA LA MEJOR COMBINACION POSIBLE

        if(puntajeRonda == 60 && (numeroLanzamiento - 1) == 1){ // IF PARA SABER SI ES GENERALA SERVIDA Y VER SI GANO
            generalaServida = true;
        }

        // LO QUE VE EL USUARIO CUANDO TEMINA LA RONDA
        cout << "----------------------------------------------------------" <<endl;
        cout << "FIN DE LOS LANZAMIENTOS" << endl;
        cout << "PUNTAJE DE LA RONDA: " << puntajeRonda << " PTS." << endl;

        puntajeTotal += puntajeRonda; // ACUMULAMOS EN LA VARIABLE EL PUNTAJE DE LA RONDA

        limpiarPantalla();

        if (generalaServida){ // SI ES TRUE TERMINA EL JUEGO
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

    int puntajeJ1 = 0, puntajeJ2 = 0; // INICIALIZO LAS VARIABLES DE PUNTAJE EN CERO
    string nombreJ1, nombreJ2; // Y DE NOMBRE

    // PIDO LOS DOS NOMBRES
    cout << "Ingrese nombre del Jugador 1: ";
    cin >> nombreJ1;
    cout << "Ingrese nombre del Jugador 2: ";
    cin >> nombreJ2;

    // FUNCION COPIADA DEL MODO UN JUGADOR

    for (int ronda = 1; ronda <= 10; ronda++) {

        // LLAMO A LA FUNCION JUGAR TURNO PARA JUGAR UN TURNO C/U
        cout << "Ronda " << ronda << " - Turno de " << nombreJ1 << endl;
        jugarTurno(puntajeJ1, nombreJ1, maxJugador, maxPuntaje);

        cout << "Ronda " << ronda << " - Turno de " << nombreJ2 << endl;
        jugarTurno(puntajeJ2, nombreJ2, maxJugador, maxPuntaje);

    }

    // COMPARACION PARA VER QUIEN GANO
    cout << "----------------------------------------------------------\n";
    cout << "RESULTADOS FINALES:\n";
    cout << nombreJ1 << ": " << puntajeJ1 << " PTS\n";
    cout << nombreJ2 << ": " << puntajeJ2 << " PTS\n";

    if (puntajeJ1 > puntajeJ2) // SI ES TRUE GANA EL J1
        cout << "GANADOR: " << nombreJ1;
    else if (puntajeJ2 > puntajeJ1) // SI ES TRUE GANA EL J2
        cout << "GANADOR: " << nombreJ2;
    else {
        cout << "EMPATE!! SE DEFINE POR SUERTE";

        bool empate = true; // EMPATE TRUE PARA QUE PASE EL WHILE Y SIGA CON EL DESEMPATE

        // WHILE QUE SIGUE HASTA QUE EMPATE SEA FALSE
        while(empate) {

            // GENERAMOS DOS DADOS ALEATORIOS HASTA QUE UNO SEA MAYOR QUE EL OTRO
            int dado1 = 1 + rand() % 6;
            int dado2 = 1 + rand() % 6;

            // MOSTRAMOS DICHOS DADOS
            cout << nombreJ1 << " tira un " << dado1 << endl;
            cout << nombreJ2 << " tira un " << dado2 << endl;

            if (dado1 > dado2) { // SI ES TRUE GANA EL J1
                cout << "¡GANA " << nombreJ1 << "! QUE SUERTE" << endl;

                empate = false; // CERRAMOS WHILE
            }
            else if (dado2 > dado1) { // SI ES TRUE GANA EL J2
                cout << "¡GANA " << nombreJ2 << "! QUE SUERTE" << endl;

                empate = false; // CERAMOOS WHILE
            }
            else {
                cout << "¡EMPATE OTRA VEZ, TIRAN DE NUEVO!" << endl; // SI EMPATAN DE NUEVO, SIGUE HASTA QUE HAYA UN GANADOR
            }
        }
    }
    cout << "----------------------------------------------------------\n";
    limpiarPantalla(); // LIMPIAMOS PANTALLA
}



/// FUNCION PARA JUGAR TURNO POR TURNO EN EL MODO DOS JUGADORES
void jugarTurno(int &puntajeTotal, string nombre, string &maxJugador, int &maxPuntaje) { // MANDO POR REFERENCIA LO QUE ESTOY USANDO CONTINUAMENTE Y POR PARAMETRO LO QUE PROCESO

    const int cantDados = 5; // CONSTANTE PARA EL TAM DEL VEC
    int dados[cantDados]; // VEC CON EL TAM DE CANTDADOS
    int numeroLanzamiento = 1; // INICIALIZAMOS EN 1 PARA QUE SE MUESTRE QUE ES LA 1RA VEZ Q SE LANZA
    bool jugadorPlantado = false; // FALSE HASTA QUE SE PLANTE
    char respuestaJugador, respuestaJugador2; // TIPO CHAR PARA RESPONDER CON S/N
    int puntajeRonda = 0; // PUNTAJE EN CERO PARA IR SUMANDO


    // LO QUE VE EL USUARIO
    cout << "----------------------------------------------------------" << endl;
    cout << "Turno de: " << nombre << " | Puntaje total: " << puntajeTotal << " PTS." << endl;


    // WHILE QUE SIGUE HASTA QUE IGUAL NUM.LAN 3 O SE PLANTE
    while (numeroLanzamiento <= 3 && !jugadorPlantado) {

        if (numeroLanzamiento == 1) { // SI ES TRUE

            // TIRAMOS Y MOSTRAMOS DADOS
            tirarDados(dados, cantDados, false); //mandamos false para mManual que no se usa aca
            mostrarDados(dados, cantDados, numeroLanzamiento);

        } else {

            cout << "CONTINUAR LANZANDO? (S/N): ";
            cin >> respuestaJugador; // PREGUNTAMOS SI QUIERE SIGUIR LANZANDO

            if (respuestaJugador == 'N' || respuestaJugador == 'n') { //SI ES TRUE

                jugadorPlantado = true; // TERMINAMOS LA RONDA

            } else if (respuestaJugador == 'S' || respuestaJugador == 's') { // SI ES TRUE

                cout << "DESEA TIRAR TODOS? (S/N): ";
                cin >> respuestaJugador2; // PREGUNTAMOS SI QUIERE TIRAR TODOS

                if (respuestaJugador2 == 'S' || respuestaJugador2 == 's') { // SI ES TRUE

                    //VOLVEMOS A TIRAR Y MOSTRAR DADOS
                    tirarDados(dados, cantDados, false); //mandamos false para mManual que no se usa aca
                    mostrarDados(dados, cantDados, numeroLanzamiento);

                } else { // SI ES FALSE

                    int cantidadARelanzar;
                    cout << "CUANTOS DADOS VOLVES A TIRAR?: ";
                    cin >> cantidadARelanzar; // PREGUNTAMOS CUANTOS QUIERE TIRAR

                    for (int i = 0; i < cantidadARelanzar; i++) { // FOR PARA QUE SE SIGA HASTA QUE SEPA TODAS LAS POSICIONES
                        int posicionDado;
                        cout << "CUAL DADO?: ";
                        cin >> posicionDado; // PREGUNTAMOS LA POSICION

                        int indice = posicionDado - 1; // GUARDAMOS TAL POSICION -1 (PQ LOS VECS VAN DE 0 A N)
                        if (indice < 0 || indice >= cantDados) { // IF PARA COMPROBAR QUE NO SE PASE DE 0 A 5
                            cout << "Posicion invalida." << endl;
                            i--;
                            continue; // CONTINUAR HASTA QUE INGRESE UN POSICION VALIDA
                        }

                        dados[indice] = 1 + (rand() % 6);

                    }

                    mostrarDados(dados, cantDados, numeroLanzamiento);
                }
            } else {
                cout << "Respuesta invalida. Por favor, ingrese S o N." << endl;
                continue; // CONTINUAR HASTA QUE INGRESE UN OPCION VALIDA EN LA PARTE DE CONTINUAR LANZANDO
            }
        }

        if (!jugadorPlantado) numeroLanzamiento++; // SI ES TRUE ++, HASTA QUE LLEGUE A 3 O SE PLANTE EL JUGADOR
    }

    int conteo[6]; // CONTADOR TAM 6 POR LAS 6 CARAS DEL DADO A CONTAR
    contarDados(dados, conteo); // LLAMAMOS LA FUNCION PARA CONTAR
    combinaciones(conteo, puntajeRonda, numeroLanzamiento - 1); // CON LOS DADOS CONTADOS LLAMAMOS LA FUNCION COMBINACIONES Y Q VEA LA MEJOR

    // LO QUE VE EL USUARIO
    cout << "----------------------------------------------------------" << endl;
    cout << "FIN DEL TURNO" << endl;
    cout << "PUNTAJE DEL TURNO: " << puntajeRonda << " PTS." << endl;

    puntajeTotal += puntajeRonda; // ACUM EL PUNTAJE DE LA RONDA EN EL TOTAL

    cargarPuntaje(nombre, puntajeTotal, maxJugador, maxPuntaje); // LO CARGAMOS, PARA EVALUAR EL MAX Y DPS EN EL MENU MOSTRARLO
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
        //-1 (para valores 0 al 5 y ++ para las veces que aparece el num
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
void cargarPuntaje(string nombre, int puntajeTotal, string &maxJugador, int &maxPuntaje){ // mandamos por referencia las variables para modificarlas originales
    if (puntajeTotal > maxPuntaje){ // if para saber si supera al maxpuntaje, asi actualizamos los datos
        maxJugador = nombre;
        maxPuntaje = puntajeTotal;
    }
}



/// FUNCION QUE MUESTRA LOS PUNTAJES
void mostrarPuntaje(string maxJugador, int maxPuntaje) { // mandamos por valor las variables para modificar solamente el jugador y el puntaje maximo
    cout << "************************* Puntaje ************************" << endl;
    cout << "----------------------------------------------------------" <<endl;
    cout << "----------------------------------------------------------" <<endl;
    if (maxJugador == "") { // si true cout avisando q no hay puntajes actualmente
        cout << "No hay puntajes actualmente." << endl << endl;
        limpiarPantalla();
        return; // return para volver al menu principal
    }
    // mostramos al jugador y su puntaje
    cout << endl << "Mejor jugador: " << maxJugador<< " con " << maxPuntaje << " Puntos." << endl << endl;
    cout << endl;
    limpiarPantalla(); //limpiamos pantalla
}
