#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// =====================================================
// DECLARACIÓN DE FUNCIONES
// =====================================================

void reto1();
void reto2();
void reto3();


// =====================================================
// FUNCIÓN PRINCIPAL
// =====================================================
int main() {

    int opcion;

    cout << "==========================================" << endl;
    cout << "         JUEGOS DE ADIVINANZA" << endl;
    cout << "==========================================" << endl;

    // =====================================================
    // BUCLE PRINCIPAL DEL MENÚ
    // Se repite hasta elegir salir.
    // =====================================================

    do {

        cout << "\n==========================================" << endl;
        cout << "             MENU PRINCIPAL" << endl;
        cout << "==========================================" << endl;

        cout << "1. Reto 1 - Modo 1 vs 1" << endl;
        cout << "2. Reto 2 - Niveles y Vidas" << endl;
        cout << "3. Reto 3 - El Adivino Digital" << endl;
        cout << "4. Salir" << endl;

        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        // =====================================================
        // Switch:
        // Ejecuta el reto seleccionado.
        // =====================================================

        switch (opcion) {

            case 1:
                reto1();
                break;

            case 2:
                reto2();
                break;

            case 3:
                reto3();
                break;

            case 4:
                cout << "\nGracias por jugar." << endl;
                break;

            default:
                cout << "\nOpcion invalida." << endl;
        }

    } while (opcion != 4);

    return 0;
}



// =====================================================
// RETO 1: MODO 1 VS 1
// Dos jugadores intentan adivinar un número.
// Gana quien lo haga en menos intentos.
// =====================================================
void reto1() {
    
    int max;
    int nivel;

    // Variables del jugador 1
    int num;
    double adivinar;
    int intentos = 0;

    // Variables del jugador 2
    int num2;
    double adivinar2;
    int intentos2 = 0;

    // Variables para guardar nombres
    string nombre1;
    string nombre2;

    // Genera números aleatorios
    srand(time(NULL));
    
    // Menú de niveles
    do {

        cout << "NIVELES:" << endl;
        cout << "1. Facil (1 al 100)" << endl;
        cout << "2. Medio (1 al 500)" << endl;
        cout << "3. Dificil (1 al 1000)" << endl;

        cout << "\nSelecciona un nivel: ";
        cin >> nivel;

        if (nivel < 1 || nivel > 3) {
            cout << "\nOpcion invalida.\n" << endl;
        }

    } while (nivel < 1 || nivel > 3);

    // Configuración del rango
    if (nivel == 1) {
        max = 100;
    }
    else if (nivel == 2) {
        max = 500;
    }
    else {
        max = 1000;
    }

    // Número aleatorio 
    num = rand() % max + 1;

    cout << "\n====================================" << endl;
    cout << "      RETO 1 - MODO 1 VS 1" << endl;
    cout << "====================================\n" << endl;

    cout << "El jugador que adivine el numero en menos intentos gana.\n" << endl;

    // Ingreso de nombres
    cout << "Jugador 1, ingresa tu nombre: ";
    cin >> nombre1;

    cout << "Jugador 2, ingresa tu nombre: ";
    cin >> nombre2;

    // =====================================================
    // TURNO DEL JUGADOR 1
    // El bucle do-while se repite hasta que el
    // jugador adivine correctamente el número.
    // =====================================================

    cout << "\nTurno de " << nombre1 << endl;

    do {
        
        cout << "Ingresa un numero: ";
        cin >> adivinar;

        // Aumenta el contador de intentos
        intentos++;

        // Condicionales para dar pistas
        if (adivinar > num) {
            cout << "Mas bajo\n" << endl;
        }
        else if (adivinar < num) {
            cout << "Mas alto\n" << endl;
        }
        else {
            cout << "\n¡ADIVINASTE!" << endl;
            cout << "Intentos realizados: " << intentos << endl;
        }

    } while (adivinar != num);


    // =====================================================
    // TURNO DEL JUGADOR 2
    // =====================================================

    // Nuevo número aleatorio
    num2 = rand() % max + 1;

    cout << "\nTurno de " << nombre2 << endl;

    do {

        cout << "Ingresa un numero: ";
        cin >> adivinar2;

        intentos2++;

        if (adivinar2 > num2) {
            cout << "Mas bajo\n" << endl;
        }
        else if (adivinar2 < num2) {
            cout << "Mas alto\n" << endl;
        }
        else {
            cout << "\n¡ADIVINASTE!" << endl;
            cout << "Intentos realizados: " << intentos2 << endl;
        }

    } while (adivinar2 != num2);


    // =====================================================
    // RESULTADOS FINALES
    // =====================================================

    cout << "\n====================================" << endl;
    cout << "           RESULTADOS" << endl;
    cout << "====================================\n" << endl;

    if (intentos < intentos2) {
        cout << "El ganador es " << nombre1 << endl;
        cout << "Gano por " << intentos2 - intentos << " intento(s)." << endl;
    }
    else if (intentos > intentos2) {
        cout << "El ganador es " << nombre2 << endl;
        cout << "Gano por " << intentos - intentos2 << " intento(s)." << endl;
    }
    else {
        cout << "¡EMPATE!" << endl;
    }
}



// =====================================================
// RETO 2: NIVELES Y VIDAS
// El jugador tiene vidas limitadas según la dificultad.
// =====================================================
void reto2() {

    int num;
    int nivel;
    int vidas;
    int adivinar;
    int limite = 100;

    srand(time(NULL));

    cout << "\n====================================" << endl;
    cout << "   RETO 2 - NIVELES Y VIDAS" << endl;
    cout << "====================================\n" << endl;
    do{
    // Menú de niveles
    cout << "NIVELES:" << endl;
    cout << "1. Muy Facil (1-10)" << endl;
    cout << "2. Facil (1-25)" << endl;
    cout << "3. Medio (1-50)" << endl;
    cout << "4. Dificil (1-75)" << endl;
    cout << "5. Muy Dificil (1-100)" << endl;

    cout << "\nSeleccione un nivel: ";
    cin >> nivel;
    if (nivel<1 || nivel>5){
        cout<<"Error. Opción no válida. Seleccione opciones del 1 al 5"<<endl;
        }
    } while (nivel<1 || nivel>5);

    // Configuración de dificultad
    if (nivel == 1) {
        limite = 10;
        vidas = 3;
    }
    else if (nivel == 2) {
        limite = 25;
        vidas = 5;
    }
    else if (nivel == 3) {
        limite = 50;
        vidas = 7;
    }
    else if (nivel == 4) {
        limite = 75;
        vidas = 10;
    }
    else {
        limite = 100;
        vidas = 12;
    }

    // Número aleatorio
    num = rand() % limite + 1;

    // =====================================================
    // Bucle while:
    // El juego continúa mientras existan vidas.
    // =====================================================

    while (vidas > 0) {

        cout << "\nVIDAS: ";

        // =====================================================
        // Bucle for:
        // Muestra vidas con asteriscos.
        // =====================================================

        for (int i = 0; i < vidas; i++) {
            cout << "* ";
        }

        cout << "\n\nIntroduce un numero: ";
        cin >> adivinar;

        // Verifica victoria
        if (adivinar == num) {
            cout << "\n¡GANASTE!" << endl;
            break;
        }

        int diferencia = adivinar - num;

        // Pistas
        if (diferencia > 0) {

            if (diferencia > 15) {
                cout << "Muchisimo mas bajo" << endl;
            }
            else {
                cout << "Mas bajo" << endl;
            }

        }
        else {

            if (-diferencia > 15) {
                cout << "Muchisimo mas alto" << endl;
            }
            else {
                cout << "Mas alto" << endl;
            }
        }

        // Reduce vidas
        vidas--;

        // Verifica derrota
        if (vidas == 0) {
            cout << "\nPERDISTE. El numero era: " << num << endl;
        }
    }
}



// =====================================================
// RETO 3: EL ADIVINO DIGITAL
// La computadora intenta adivinar el número.
// =====================================================
void reto3() {

    int inferior = 1;
    int superior = 100;
    int nivel;
    int intento;
    int respuesta;

    bool adivinado = false;

    cout << "\n====================================" << endl;
    cout << "     RETO 3 - EL ADIVINO DIGITAL" << endl;
    cout << "====================================\n" << endl;

    // =====================================================
    // Validación de dificultad
    // =====================================================

    do {

        cout << "Selecciona la dificultad:" << endl;
        cout << "1. Facil (1 al 100)" << endl;
        cout << "2. Medio (1 al 500)" << endl;
        cout << "3. Dificil (1 al 1000)" << endl;

        cout << "\nTu eleccion: ";
        cin >> nivel;

        if (nivel < 1 || nivel > 3) {
            cout << "\nOpcion invalida.\n" << endl;
        }

    } while (nivel < 1 || nivel > 3);

    // Configuración del rango
    if (nivel == 1) {
        superior = 100;
    }
    else if (nivel == 2) {
        superior = 500;
    }
    else {
        superior = 1000;
    }

    cout << "\nPiensa en un numero entre 1 y " << superior << endl;

    // =====================================================
    // Bucle principal de búsqueda
    // =====================================================

    while (!adivinado && inferior <= superior) {

        // Búsqueda binaria
        intento = inferior + (superior - inferior) / 2;

        cout << "\n¿Tu numero es " << intento << "?" << endl;

        cout << "1. Mi numero es mayor" << endl;
        cout << "2. Mi numero es menor" << endl;
        cout << "3. ¡Correcto!" << endl;

        cout << "\nRespuesta: ";
        cin >> respuesta;

        // Ajuste del rango
        if (respuesta == 1) {
            inferior = intento + 1;
        }
        else if (respuesta == 2) {
            superior = intento - 1;
        }
        else if (respuesta == 3) {
            adivinado = true;
            cout << "\n¡La computadora adivino tu numero!" << endl;
        }
        else {
            cout << "\nOpcion invalida." << endl;
        }
    }

    // Verifica errores
    if (!adivinado) {
        cout << "\nHubo un error en las pistas." << endl;
    }
}
