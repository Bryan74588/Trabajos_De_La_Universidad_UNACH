#include <iostream>
#include <limits> // Para limpiar buffer y validar entradas
#include <cmath>  // Para cálculos matemaáticos
using namespace std;

// Constante para número de días
const int dias = 7; // ejemplo: una semana

// Arreglos principales
int produccion[dias];          // unidades producidas
float horasOperacion[dias];    // horas de operación
float consumoEnergia[dias];    // consumo energético (kWh)
float temperatura[dias];       // arreglo personalizado: temperatura de máquinas

// ---------------- VALIDAR ENTRADAS ----------------
template <typename T>
T Entrada(string msj, T min, T max) {
    T v;
    while (true) {
        cout << msj;
        cin >> v;
        if (cin.fail() || v < min || v > max) {
            cout << "Entrada invalida. Intente nuevamente." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return v;
        }
    }
}

// ---------------- FUNCION DE PRODUCCIÓN ----------------
void AProduccion() {
    int total = 0, maxDia = 0, minDia = 0;
    for (int i = 0; i < dias; i++) {
        total += produccion[i];
        if (produccion[i] > produccion[maxDia]) maxDia = i;
        if (produccion[i] < produccion[minDia]) minDia = i;
    }
    float promedio = (float)total / dias;
    cout << "--- Produccion ---" << endl;
    cout << "Total producido: " << total << endl;
    cout << "Dia de mayor produccion: Dia " << maxDia+1 << " (" << produccion[maxDia] << " unidades)" << endl;
    cout << "Dia de menor produccion: Dia " << minDia+1 << " (" << produccion[minDia] << " unidades)" << endl;
    cout << "Promedio de producción: " << promedio << endl;
}

// ---------------- FUNCION DE HORAS ----------------
void AHoras() {
    float total = 0;
    int minDia = 0;
    float limiteSobrecarga = 30.0; // valor propuesto
    cout << "--- Horas de Operacion ---" << endl;
    for (int i = 0; i < dias; i++) {
        total += horasOperacion[i];
        if (horasOperacion[i] < horasOperacion[minDia]) minDia = i;
    }
    float promedio = total / dias;
    cout << "Promedio de horas trabajadas: " << promedio << endl;
    cout << "Dias con sobrecarga (> " << limiteSobrecarga << " horas): ";
    for (int i = 0; i < dias; i++) {
        if (horasOperacion[i] > limiteSobrecarga) cout << "Dia " << i+1 << " ";
    }
    cout << endl;
    cout << "Dia con menos horas trabajadas: Dia " << minDia+1 << " (" << horasOperacion[minDia] << " horas)" << endl;
}

// ---------------- FUNCION DE ENERGÍA ----------------
void AEnergia() {
    float total = 0;
    for (int i = 0; i < dias; i++) total += consumoEnergia[i];
    float promedio = total / dias;
    int diaCercano = 0;
    for (int i = 1; i < dias; i++) {
        if (fabs(consumoEnergia[i] - promedio) < fabs(consumoEnergia[diaCercano] - promedio)) {
            diaCercano = i;
        }
    }
    cout << "--- Consumo de Energia ---" << endl;
    cout << "Consumo total: " << total << " kWh\n";
    cout << "Consumo promedio: " << promedio << " kWh\n";
    cout << "Dia con consumo mas cercano al promedio: Dia " << diaCercano+1 << " (" << consumoEnergia[diaCercano] << " kWh)" << endl;
}

// ---------------- FUNCION PERSONALIZADAS ----------------
// Ejemplo: Temperatura de máquinas → detectar sobrecalentamiento (> 100 °C)
void ATemperatura() {
    cout << "--- Temperatura de Maquinas ---" << endl;
    for (int i = 0; i < dias; i++) {
        if (temperatura[i] > 80) {
            cout << "Alerta: Dia " << i+1 << " sobrecalentamiento (" << temperatura[i] << " °C)" << endl;
        }
    }
    cout << "Analisis completado." << endl;
}

// ---------------- MENU INTERACTIVO ----------------
void menu() {
    int opcion;
    do {
        cout << "------ MENU PRINCIPAL ------" << endl;
        cout << "1. Analizar Produccion" << endl;
        cout << "2. Analizar Horas de Operacion" << endl;
        cout << "3. Analizar Consumo de Energia" << endl;
        cout << "4. Analizar Temperatura de Maquinas" << endl;
        cout << "5. Salir" << endl;
        opcion = Entrada<int>("Seleccione una opcion: ", 1, 5);

        switch(opcion) {
            case 1: AProduccion(); break;
            case 2: AHoras(); break;
            case 3: AEnergia(); break;
            case 4: ATemperatura(); break;
            case 5: cout << "Saliendo del sistema...\n"; break;
        }
    } while(opcion != 5);
}

// ---------------- PROGRAMA PRINCIPAL ----------------
int main() {
    cout << "Registro de indicadores industriales" << endl;
    cout << "Ingrese datos para " << dias << " dias:" << endl;
    for (int i = 0; i < dias; i++) {
        produccion[i] = Entrada<int>("Produccion dia " + to_string(i+1) + ": ", 0, 10000);
        horasOperacion[i] = Entrada<float>("Horas de operacion dia " + to_string(i+1) + ": ", 0, 24);
        consumoEnergia[i] = Entrada<float>("Consumo de energia dia " + to_string(i+1) + " (kWh): ", 0, 10000);
        temperatura[i] = Entrada<float>("Temperatura maquina dia " + to_string(i+1) + " (C): ", 0, 200);
        
    }
    menu();
    return 0;
}







