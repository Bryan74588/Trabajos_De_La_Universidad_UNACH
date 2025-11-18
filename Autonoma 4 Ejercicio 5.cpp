/*5. Ejercicio 5: Diseña tu propio ejercicio completo
Objetivo:
Proponer un ejercicio original que permita practicar todos los conceptos
vistos hasta ahora en C++, incluyendo:
• Funciones (pueden usar funciones normales, sobrecargadas o
plantillas).
• Estructuras condicionales
• Estructuras de repetición
• Recursión */

#include <iostream>
using namespace std;

// Función para calcular el factorial de forma recursiva
long long factorial(int num) {
    if (num <= 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

int main() {
    system("chcp 65001 > nul");
    int numero;
    cout << "Ingrese un número entero positivo para calcular su factorial: ";
    cin >> numero;

    if (numero < 0) {
        cout << "Error: El número debe ser positivo." << endl;
    } else {
        long long resu = factorial(numero);
        cout << "El factorial de " << numero << " es: " << resu << endl;
    }

    return 0;
}


