/*Escribe un programa en C++ que reciba un ángulo en grados y calcule
el valor del seno y el coseno de ese ángulo utilizando la serie de Taylor.
Para ello, implementa funciones recursivas.
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

// Función recursiva para calcular el factorial de un número
long double factorial(int num)
{
    if (num <= 1)
        return 1;
    return num * factorial(num - 1);
}

// Función recursiva para calcular el seno usando la serie de Taylor
long double senTaylor(double x, int num)
{
    if (num == 0)
        return x; // Primer término de la serie

    long double termino = pow(-1, num) * pow(x, 2 * num + 1) / factorial(2 * num + 1);
    return termino + senTaylor(x, num - 1);
}

// Función recursiva para calcular el coseno usando la serie de Taylor
long double cosTaylor(double x, int num)
{
    if (num == 0)
        return 1; // Primer término

    long double termino = pow(-1, num) * pow(x, 2 * num) / factorial(2 * num);
    return termino + cosTaylor(x, num - 1);
}

int main()
{
    system("chcp 65001 > nul");
    double gra;
    cout << "Ingrese un angulo en grados: ";
    cin >> gra;

    double rad = gra * M_PI / 180.0;

    int terminos = 10;

    long double sen = senTaylor(rad, terminos - 1);
    long double cos = cosTaylor(rad, terminos - 1);

    cout << "Seno(" << gra << "°) = " << sen << endl;
    cout << "Coseno(" << gra << "°) = " << cos << endl;

    return 0;
}
