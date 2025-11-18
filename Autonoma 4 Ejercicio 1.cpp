/*1. Escribe una función recursiva que genere todas las permutaciones
posibles de una cadena de texto.
Por ejemplo:
Entrada: "abc".
 Salida:
abc
acb
bac
bca
cab
cba
La cadena puede ser de 2 caracteres en adelante sin restricciones de
cantidad de caracteres.*/

#include <iostream>
#include <string>
using namespace std;

void permutaciones(string cadena, int izquierda, int derecha)
{
    if (izquierda == derecha)
    {
        cout << cadena << endl;
    }
    else
    {
        for (int i = izquierda; i <= derecha; i++)
        {
            swap(cadena[izquierda], cadena[i]);          // Intercambia (Haciendo la permutación)
            permutaciones(cadena, izquierda + 1, derecha); // Llama recursivamente a la subcadena restante
            swap(cadena[izquierda], cadena[i]);          // Deshace el intercambio (Backtracking)
        }
    }
}

int main()
{
    string cadena;
    cout << "Ingrese una cadena de texto: ";
    cin >> cadena;
    cout << "Las permutaciones posibles son:" << endl;
    permutaciones(cadena, 0, cadena.length() - 1);
    return 0;
}
