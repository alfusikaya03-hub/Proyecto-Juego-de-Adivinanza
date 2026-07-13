//Integrantes: Kaya Alfusi, Mónica Caiza, Tifanny Pillajo

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

//CONSTANTES GLOBALES
const int MAX_JUGADORES=2;
const int MAX_HISTORIAL=1000;
const string NOMBRE_ARCHIVO= "historial_partidas.txt";

//PROTOTIPOS
void mostrarMenu ();
void limpiarEntrada ();
int seleccionarRango ();
void ejecutarTurno (string nombre, int numeroSecreto, int &intentosTotales, int hitorial [], int rangoMax);
void mostrarHistorial(int historial[], int totalIntentos);
void guardarHistorialEnTXT(string nombre, int rangoMax, int numeroSecreto, int historial[], int totalIntentos);
void mostrarHistorialCompletoTXT(); 


//RETOS PRINCIPALES
void reto1();
void reto2();
void reto3();

// FUNCION PRINCIPAL 
int main() {
    int opcion;
    //Inicializa la semilla del generador de números aleatorios usando el tiempo actual
    srand (time (NULL));
    
    do {
        mostrarMenu(); 
        cout<< "Seleccione una opcion"<< endl;

        // Evita bloqueo si el usuario ingresa una letra en el menú
        if (!(cin >> opcion)) {
            limpiarEntrada ();
            opcion=0;
        }

        switch (opcion) {
            case 1: reto1 (); break;
            case 2: reto2 (); break;
            case 3: reto3 (); break;
            case 4: mostrarHistorialCompletoTXT (); break;
            case 5: cout << "Gracias por jugar"<< endl; break;
            default: cout << "Opción no válida. Intente de nuevo"<< endl; 
        }
           
    } while (opcion != 5);

    return 0;
}

void mostrarMenu () {
   cout << "\n==========================================" << endl;
   cout << "             MENU PRINCIPAL                 " << endl;
   cout << "==========================================" << endl;
   cout << "1. Reto 1 - Modo 1 vs 1" << endl;
   cout << "2. Reto 2 - Niveles y Vidas" << endl;
   cout << "3. Reto 3 - El Adivino Digital" << endl;
   cout << "4. Mostrar historial " << endl;
   cout << "5. Salir"<< endl;
}

// Vacía el buffer de entrada tras un error de tipeo
void limpiarEntrada () {
    cin.clear ();
    while (cin.get() != '\n' );
}

int seleccionarRango () {
    int nivel;
    do {
        cout << "NIVELES:" << endl;
        cout << "1. Facil (1 al 100)" << endl;
        cout << "2. Medio (1 al 500)" << endl;
        cout << "3. Dificil (1 al 1000)" << endl;
        cout << "\nSelecciona un nivel: ";
        cin >> nivel;

        if (! (cin >> nivel))  {
            limpiarEntrada ();
            nivel=0;
        }

        if (nivel < 1 || nivel > 3) {
            cout << "\nOpción inválida.\n" << endl;
        }

    } while (nivel < 1 || nivel > 3);

    if(nivel == 1) return 100;
    if(nivel == 2) return 500;
    return 1000;
}

void ejecutarTurno (string nombre, int numeroSecreto, int &intentosTotales, int historial [], int rangoMax) {
    int adivinar;
    intentosTotales=0;

    cout << "Turno de " << nombre<< "Rango del 1 al "<< rangoMax << endl;
    cout << "---------------------------------------------------------" << endl;

    do {
        cout << "Ingresa un numero" << endl;
        if (!(cin>> adivinar)) {
            limpiarEntrada ();
            cout << "Por favor, ingresa un número válido"<< endl;
            continue;
        }
        if (intentosTotales < MAX_HISTORIAL) {
                historial[intentosTotales] = adivinar;
        } 
        intentosTotales++;

        if (adivinar > numeroSecreto) {
            cout << "Más bajo" << endl;  
        }
        else if (adivinar < numeroSecreto ) {
            cout<< "Más alto" << endl;
        }
        else {
            cout << "Muy bien hecho" << nombre << "Adivinaste el número"<< endl;
            cout << "Intentos realizados: " << intentosTotales << endl;
        }
    } while (adivinar != numeroSecreto);

     // Muestra el historial en la consola actual
    mostrarHistorial(historial, intentosTotales);
    
    //Guarda automáticamente los datos y la secuencia en el archivo físico .txt
    guardarHistorialEnTXT (nombre, rangoMax, numeroSecreto, historial, intentosTotales);
}

void mostrarHistorial (int historial[], int totalIntentos) {
    cout << "Tu secuencia de intentos fue: [";
    for (int i=0; i < totalIntentos; i++) {
        cout<< historial [i];
        if (i < totalIntentos -1) {
            cout << ", ";
        }
    }
    cout << " ]"<< endl;
}

// Escribe los resultados al final del archivo sin borrar los anteriores
void guardarHistorialEnTXT (string nombre, int rangoMax, int numeroSecreto, int historial [], int totalIntentos) {
    ofstream archivo (NOMBRE_ARCHIVO, ios::app);

    if (! archivo.is_open () ) {
        cout << "No se pudo escribir el archivo en el historial" << endl;
        return;
    }

    archivo<< "Jugador: " << nombre << endl;
    archivo << "Rango: 1 a " << rangoMax << endl;
    archivo << "Numero secreto: "<< numeroSecreto<< endl;
    archivo << "Intentos totales: " << totalIntentos << endl;
    archivo << "Secuencia: [ ";
    for (int i=0; i < totalIntentos; i++ ) {
        archivo << historial [i];
        if (i < totalIntentos -1) archivo << ", ";
    }
    archivo << " ]"<< endl;
    archivo << "------------------------------------------" << endl;

    archivo.close ();
}

// Lee e imprime el contenido completo del archivo TXT en la consola
void mostrarHistorialCompletoTXT() {
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;

    cout << "\n---------------------------------------" << endl;
    cout << "     HISTORIAL DE PARTIDAS GUARDADAS" << endl;
    cout << "---------------------------------------" << endl;

    if (!archivo.is_open()) {
        cout << "No hay un historial registrado aun o el archivo no existe." << endl;
        return;
    }
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

// =====================================================
// RETO 1: MODO 1 VS 1
// Competencia entre dos jugadores.
// =====================================================

void reto1() {
    cout << "\n---------------------------------------" << endl;
    cout << "      RETO 1 - MODO 1 VS 1" << endl;
    cout << "---------------------------------------\n" << endl;

    int maxRango = seleccionarRango();
    string nombres[MAX_JUGADORES];
    int intentos[MAX_JUGADORES] = {0};
    int historialIntenciones[MAX_HISTORIAL]; 

    for (int i = 0; i < MAX_JUGADORES; i++) {
        cout << "Jugador " << i + 1 << ", ingresa tu nombre: ";
        cin >> nombres[i];
    }

    for (int i = 0; i < MAX_JUGADORES; i++) {
        int numeroSecreto = rand() % maxRango + 1;
        ejecutarTurno(nombres[i], numeroSecreto, intentos[i], historialIntenciones, maxRango);
    }

    cout << "\n---------------------------------------" << endl;
    cout << "           RESULTADOS" << endl;
    cout << "---------------------------------------\n" << endl;

    if (intentos[0] < intentos[1]) {
        cout << "El ganador es " << nombres[0] << endl;
        cout << "Gano por " << intentos[1] - intentos[0] << " intento(s)." << endl;
    } else if (intentos[0] > intentos[1]) {
        cout << "El ganador es " << nombres[1] << endl;
        cout << "Gano por " << intentos[0] - intentos[1] << " intento(s)." << endl;
    } else {
        cout << "¡EMPATE!" << endl;
    }
}



// =====================================================
// RETO 2: NIVELES Y VIDAS
// Adivinar el número con un control de vidas y dificultad
// =====================================================
void reto2() {

    int num;
    int nivel;
    int vidas;
    int adivinar;
    int limite;
    int historialReto2[MAX_HISTORIAL];
    int conteoIntentos = 0 ;

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
    if (!(cin>>nivel)){
        limpiarEntrada();
        nivel=0;
    }
    if (nivel<1 || nivel>5){
        cout<<"Error. Opción no válida. Seleccione opciones del 1 al 5"<<endl;
        }
    } while (nivel<1 || nivel>5);

    int limites[]={10,25,50,75,100};
    int vidasPorNivel []={3,5,7,10,12};

    limite=limites[nivel - 1];
    vidas = vidasPorNivel[nivel - 1];
    int vidasIniciales = vidas;

    num= rand () % limite + 1;

    while (vidas > 0) {
        cout << "\nVIDAS: ";
        for (int i = 0; i < vidas; i++) {
            cout << "* ";
        }

        cout << "\nIntroduce un numero: ";
        if (!(cin >> adivinar)) {
            limpiarEntrada();
            cout << "Ingreso invalido. Pierdes una vida." << endl;
            vidas--;
            continue;
        }

        if (conteoIntentos < MAX_HISTORIAL) {
            historialReto2[conteoIntentos] = adivinar;
        }
        conteoIntentos++;

        if (adivinar == num) {
            cout << "\n¡GANASTE!" << endl;
            mostrarHistorial(historialReto2, conteoIntentos);
            
            guardarHistorialEnTXT("Jugador Reto 2", limite, num, historialReto2, conteoIntentos);
            break;
        }

        int diferencia = adivinar - num;
        if (diferencia > 0) {
            if (diferencia > 15) cout << "Muchisimo mas bajo" << endl;
            else cout << "Mas bajo" << endl;
        } else {
            if (-diferencia > 15) cout << "Muchisimo mas alto" << endl;
            else cout << "Mas alto" << endl;
        }

        vidas--;

        if (vidas == 0) {
            cout << "\nPERDISTE. El numero era: " << num << endl;
            mostrarHistorial(historialReto2, conteoIntentos);
            guardarHistorialEnTXT("Jugador Reto 2 (Derrota)", limite, num, historialReto2, conteoIntentos);
        }
    }
}


// =====================================================
// RETO 3: EL ADIVINO DIGITAL
// La computadora adivina el numero.
// =====================================================
void reto3() {

    int inferior = 1;
    int superior;
    int intento;
    int respuesta;
    bool adivinado = false;
    int historialPC[MAX_HISTORIAL];
    int conteoPC = 0;


    cout << "\n====================================" << endl;
    cout << "     RETO 3 - EL ADIVINO DIGITAL" << endl;
    cout << "====================================\n" << endl;

    // =====================================================
    // Validación de dificultad
    // =====================================================

    int maxRango = seleccionarRango ();
    superior = maxRango;

    cout << "\nPiensa en un numero entre 1 y " << superior <<endl;

    //Control estricto de limites para evitar bucles infinitos por pistas falsas

    while (!adivinado && inferior <= superior) {
        intento = inferior + (superior - inferior)/ 2;

        if (conteoPC  < MAX_HISTORIAL){
            historialPC[conteoPC] = intento;
        }
        conteoPC++;
        
        cout << "\n¿Tu numero es " << intento << "?" << endl;
        cout << "1. Mi numero es mayor" << endl;
        cout << "2. Mi numero es menor" << endl;
        cout << "3. ¡Correcto!" << endl;

        cout << "\nRespuesta: ";
        if (!(cin >> respuesta)){
            limpiarEntrada();
            respuesta = 0;
        }

        if (respuesta == 1){
            inferior = intento + 1;
        }else if (respuesta == 2) {
            superior = intento - 1;
        }else if (respuesta == 3) {
            adivinado = true;
            guardarHistorialEnTXT("Computadora (Adivino)", maxRango, intento, historialPC, conteoPC);
        }else {
            cout << "\nOpcion no válida." << endl;
        }


    }
    // Verifica errores
    if (!adivinado) {
        cout << "\nHubo una incongruencia en las pistas." << endl;
        guardarHistorialEnTXT("Computadora (Fallo por Incongruencia)", maxRango, -1, historialPC, conteoPC);
    }
}
