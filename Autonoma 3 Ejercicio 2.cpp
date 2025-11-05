/*Desarrolla un programa que convierta una cantidad en dinero a
monedas de diferentes denominaciones. El programa debe utilizar
2
funciones para calcular el número de monedas que corresponden a
cada denominación (por ejemplo, 1 dólar y 50, 25, 10, 5, 1 centavos).
Consideraciones:
• Crea una función que reciba una cantidad en dinero y devuelva el
número de monedas de cada denominación.
• El programa debe permitir al usuario ingresar una cantidad y mostrar
cómo se puede dividir en monedas
*/

#include <iostream>
using namespace std;

// Función para calcular el número de monedas de cada denominación
void calcularmonedas(int canti, int &mDe1Dolar, int &mDe50Centavos, int &mDe25Centavos, int &mDe10Centavos, int &mDe5Centavos, int &mDe1Centavo)
{
    // Calcular el número de monedas de 1 dólar
    mDe1Dolar = canti / 100;
    canti %= 100; // Actualizar la cantidad restante

    // Calcular el número de monedas de 50 centavos
    mDe50Centavos = canti / 50;
    canti %= 50; // Actualizar la cantidad restante

    // Calcular el número de monedas de 25 centavos
    mDe25Centavos = canti / 25;
    canti %= 25; // Actualizar la cantidad restante

    // Calcular el número de monedas de 10 centavos
    mDe10Centavos = canti / 10;
    canti %= 10; // Actualizar la cantidad restante

    // Calcular el número de monedas de 5 centavos
    mDe5Centavos = canti / 5;
    canti %= 5; // Actualizar la cantidad restante

    // Calcular el número de monedas de 1 centavo
    mDe1Centavo = canti; // Lo que queda son los centavos restantes
}

int main()
{
    int canti; // Cantidad en centavos ingresada por el usuario
    int mDe1Dolar = 0, mDe50Centavos = 0, mDe25Centavos = 0, mDe10Centavos = 0, mDe5Centavos = 0, mDe1Centavo = 0;

    // Solicitar al usuario que ingrese una cantidad en centavos
    cout << "Ingrese una cantidad en centavos: ";
    cin >> canti;

    // Llamar a la función para calcular el número de monedas de cada denominación
    calcularmonedas(canti, mDe1Dolar, mDe50Centavos, mDe25Centavos, mDe10Centavos, mDe5Centavos, mDe1Centavo);

    // Mostrar el resultado al usuario
    cout << "La cantidad de " << canti << " centavos se puede dividir en:" << endl;
    cout << mDe1Dolar << " monedas de 1 dólar" << endl;
    cout << mDe50Centavos << " monedas de 50 centavos" << endl;
    cout << mDe25Centavos << " monedas de 25 centavos" << endl;
    cout << mDe10Centavos << " monedas de 10 centavos" << endl;
    cout << mDe5Centavos << " monedas de 5 centavos" << endl;
    cout << mDe1Centavo << " monedas de 1 centavo" << endl;

    return 0;
}
