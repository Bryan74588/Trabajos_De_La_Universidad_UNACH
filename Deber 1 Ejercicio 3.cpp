#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float grados_celsius, grados_fahrenheit, umbral_comparacion;
    string clas;
    bool mayorumbral, multiplo5;

   
      system("chcp 65001 > nul");
    cout << "Ingrese la temperatura en grados Celsius (-100 a 100): ";
    cin >> grados_celsius;

    if (grados_celsius < -100 || grados_celsius > 100)
    {
        cout << "Error: La temperatura debe estar entre -100 y 100 grados Celsius." << endl;
        return 0; 
    }

    grados_fahrenheit = grados_celsius * 9.0 / 5.0 + 32.0;

    clas = (grados_celsius < 0) ? "Muy fría" : (grados_celsius <= 15) ? "Fría"
                                           : (grados_celsius <= 30)   ? "Templada"
                                                                      : "Caliente";

    cout << "Ingrese la temperatura del  umbral para realizar la comparación: ";
    cin >> umbral_comparacion;

    mayorumbral = grados_celsius > umbral_comparacion;
    multiplo5 = static_cast<int>(grados_celsius) % 5 == 0;

    cout << "-------Resultados-------" << endl;
    cout << "Temperatura en Fahrenheit: " << grados_fahrenheit << " °F" << endl;
    cout << "Clasificación: " << clas << endl;
    cout << "¿Es mayor que el umbral? " << (mayorumbral ? "Sí" : "No") << endl;
    cout << "¿Es múltiplo de 5? " << (multiplo5 ? "Sí" : "No") << endl;

    return 0;
}
