/*. Escribe un programa que reciba un número entero positivo entre 1 y
999, y lo convierta en texto.
Por ejemplo:
• 15 → quince
• 230 → doscientos treinta
• 999 → novecientos noventa y nueve
No utilices arreglos ni cadenas; resuélvelo con funciones, condicionales
anidados y casos especiales por separado.
*/

#include <iostream>
using namespace std;
// Función para convertir un número en texto
void numtexto(int num)
{
    // Arrays para las unidades, decenas y centenas en texto
    string unidades[] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
    string decenas[] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
    string centenas[] = {"", "cien", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};
    string espe[] = {"once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve"};

        // Descomposición del número en centenas, decenas y unidades
    int centena = num / 100;
    int decena = (num % 100) / 10;
    int unidad = num % 10;

        // Construcción del texto resultante
    string resultado = "";


    // Manejo de casos especiales para números entre 11 y 19
    if (num >= 11 && num <= 19)
    {
        cout << espe[num - 11] << endl;
        return;
    }

    if (centena > 0)
    {
        resultado += centenas[centena] + " ";
    }
    if (decena > 0)
    {
        resultado += decenas[decena] + " ";
    }
    if (unidad > 0)
    {
        resultado += unidades[unidad] + " ";
    }

    cout << resultado << endl; // Mostrar el número en texto
}

int main()
{
    int num; // Variable para almacenar el número ingresado por el usuario

    // Solicitar al usuario que ingrese un número entre 1 y 999
    cout << "Ingrese un numero entero positivo entre 1 y 999: ";
    cin >> num;

    // Validar que el número esté en el rango correcto
    if (num < 1 || num > 999)
    {
        cout << "Numero fuera de rango. Por favor ingrese un numero entre 1 y 999." << endl;
        return 0; // Salir con código de error
    }

    // Llamar a la función para convertir el número a texto
    numtexto(num);

    return 0; // Salir exitosamente
}