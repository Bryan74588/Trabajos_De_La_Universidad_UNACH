/*1. Crea un programa que permita a los usuarios ingresar notas para varios
estudiantes y calcular el promedio de las notas ingresadas. El programa
debe permitir al usuario ingresar varias notas hasta que decida terminar.
Implementa la sobrecarga de funciones para calcular el promedio de las
notas, aceptando tanto enteros como flotantes.
Consideraciones:
• Define funciones sobrecargadas para calcular el promedio de las
notas.
• El programa debe permitir al usuario ingresar notas de tipo int y float.
• Utiliza un bucle do-while para permitir al usuario ingresar notas de
manera repetitiva.
• Al final, muestra el promedio de las notas ingresadas.
*/

#include <iostream>
using namespace std;

// Función sobrecargada para calcular el promedio de notas enteras
float calcularPromediodenotasenteras(int suma, int cantidad)
{
    return static_cast<float>(suma) / cantidad; // Convertir a float para obtener un promedio preciso
}

// Función sobrecargada para calcular el promedio de notas flotantes
float calcularPromediodereales(float suma, int cantidad)
{
    return suma / cantidad; // Promedio de notas flotantes
}

int main()
{
    int opc;             // Variable para almacenar el tipo de nota a ingresar
    char continuar;         // Variable para controlar la continuación del ingreso de notas
    int nentero;            // Variable para almacenar la nota entera
    int sumentero = 0;        // Suma de notas enteras
    int cantientero = 0;    // Cantidad de notas enteras ingresadas
    float proentero;      // Promedio de notas enteras
    float nreal;        // Variable para almacenar la nota flotante
    float sumreal = 0.0f; // Suma de notas flotantes
    int cantireal = 0;  // Cantidad de notas flotantes ingresadas
    float proreal;    // Promedio de notas flotantes

    do
    {
        cout << "Seleccione el tipo de nota a ingresar:" << endl;
        cout << "1. Nota entera " << endl;
        cout << "2. Nota flotante " << endl;
        cin >> opc;

        if (opc == 1)
        {
            do
            {
                cout << "Ingrese una nota entera: ";
                cin >> nentero;
                sumentero += nentero; // Acumular la suma de notas enteras
                cantientero++;      // Incrementar la cantidad de notas ingresadas

                cout << "¿Desea ingresar otra nota entera? (s/n): ";
                cin >> continuar;
            } while (continuar == 's' || continuar == 'S');

            // Calcular y mostrar el promedio de notas enteras
            proentero = calcularPromediodenotasenteras(sumentero, cantientero);
            cout << "El promedio de las notas enteras es: " << proentero << endl;
        }
        else if (opc == 2)
        {
            do
            {
                cout << "Ingrese una nota flotante: ";
                cin >> nreal;
                sumreal += nreal; // Acumular la suma de notas flotantes
                cantireal++;        // Incrementar la cantidad de notas ingresadas

                cout << "¿Desea ingresar otra nota flotante? (s/n): ";
                cin >> continuar;
            } while (continuar == 's' || continuar == 'S');

            // Calcular y mostrar el promedio de notas flotantes
            proreal = calcularPromediodereales(sumreal, cantireal);
            cout << "El promedio de las notas flotantes es: " << proreal << endl;
        }
        else
        {
            cout << "Opción no válida. Por favor, seleccione 1 o 2." << endl;
        }
        cout << "¿Desea seleccionar otro tipo de nota? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');
    return 0;
}