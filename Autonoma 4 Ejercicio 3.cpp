/*Escribe un programa en C++ que determine cuántos elementos de la
serie de Fibonacci se encuentran en el rango entre 1000 y 2000.
El programa debe usar funciones recursivas para:
• Generar los números de la serie de Fibonacci.
• Contar cuántos de esos números están dentro del rango solicitado.*/

#include <iostream>
using namespace std;

// Funcion recursiva para generar Fibonacci
int fibonacci(int num)
{
    if (num <= 0)
        return 0;
    if (num == 1)
        return 1;

    return fibonacci(num - 1) + fibonacci(num - 2);
}

// Funcion recursiva que cuenta y tambien muestra los Fibonacci en el rango
int FibonacciRango(int num, int &cont)
{
    int fibNum = fibonacci(num);

    // Si el Fibonacci pasa de 2000, terminamos
    if (fibNum > 2000)
        return cont;

    // Si esta en el rango, lo mostramos y contamos
    if (fibNum >= 1000 && fibNum <= 2000)
    {
        cout << "Numero encontrado: " << fibNum << endl;
        cont++;
    }

    return FibonacciRango(num + 1, cont);
}

int main()
{
    int cont = 0;

    FibonacciRango(0, cont);

    cout << "Cantidad total: " << cont << endl;

    return 0;
}