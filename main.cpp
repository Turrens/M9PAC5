#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <atomic>

using namespace std;

// Variables compartidas
atomic<bool> sistema_activo(true);
mutex mtx;

// Funci�n del sistema de ox�geno
void sistemaOxigen() {
    while (sistema_activo) {
        cout << "Verificant nivell d'oxigen..." << endl;
        // Aqu� verificar�amos el nivel y ajustar�amos si es necesario
        this_thread::sleep_for(chrono::seconds(1));
    }
}

// Funci�n del sistema de comunicaci�
void sistemaComunicacio() {
    while (sistema_activo) {
        cout << "Comunicacio amb la nau mare activa..." << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
}

// Funci�n de navegaci�n autom�tica
void navegacioAutomatica() {
    while (sistema_activo) {
        cout << "Calculant rutes i evitant obstacles..." << endl;
        this_thread::sleep_for(chrono::seconds(3));
    }
}

// Funci�n de monitoratge de signes vitals
void monitoratgeSignesVitals() {
    while (sistema_activo) {
        cout << "Monitoritzant constants vitals dels astronautes..." << endl;
        this_thread::sleep_for(chrono::seconds(5));
    }
}

// Funci�n de reparaci� de sistemes
void reparacioSistemes() {
    while (sistema_activo) {
        cout << "Realitzant manteniment dels sistemes..." << endl;
        this_thread::sleep_for(chrono::seconds(7));
    }
}

int main() {
    // Crear hilos para cada tarea
    thread oxigenThread(sistemaOxigen);
    thread comunicacioThread(sistemaComunicacio);
    thread navegacioThread(navegacioAutomatica);
    thread signesVitalsThread(monitoratgeSignesVitals);
    thread reparacioThread(reparacioSistemes);

    // Simular operaci�n por un tiempo definido (por ejemplo, 30 segundos)
    this_thread::sleep_for(chrono::seconds(30));

    // Desactivar el sistema
    sistema_activo = false;

    // Unir los hilos
    oxigenThread.join();
    comunicacioThread.join();
    navegacioThread.join();
    signesVitalsThread.join();
    reparacioThread.join();

    cout << "Sistema de la nau espacial desactivat." << endl;

    return 0;
}
