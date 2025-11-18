/*Escribe un programa en C++ que reciba un número entero positivo n y
muestre el número primo más grande que sea menor que n, usando
funciones recursivas.*/

#include <iostream>
using namespace std;

// Función recursiva para verificar si un número es primo
bool Nprimo(int num, int div)
{
    // Caso base: si el divisor llega a 1, es primo
    if (div == 1)
        return true;

    // Si es divisible, no es primo
    if (num % div == 0)
        return false;

    // Llamada recursiva reduciendo el divisor
    return Nprimo(num, div - 1);
}

// Función recursiva para encontrar el mayor número primo menor que n
int MaPrimoMeprimo(int nu)
{
    nu--; // Buscar el número inmediatamente menor

    // Si baja de 2, ya no hay primos posibles
    if (nu < 2)
        return -1;

    // Verificar si es primo
    if (Nprimo(nu, nu / 2))
        return nu;

    // Recursión: seguir buscando hacia abajo
    return MaPrimoMeprimo(nu);
}

int main()
{
    int nu, primo;
    cout << "Ingrese un numero entero positivo: ";
    cin >> nu;

    primo = MaPrimoMeprimo(nu);

    if (primo != -1)
        cout << "El numero primo mas grande menor que " << nu << " es: " << primo << endl;
    else
        cout << "No hay numeros primos menores que " << nu << endl;

    return 0;
}
