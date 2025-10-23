/*Crea un programa que simule una calculadora avanzada, con las siguientes
características:
El programa debe mostrar un menú con las siguientes opciones:
1. Sumar
2. Restar
3. Multiplicar
4. Dividir
5. Potencia (A^B)
6. Raíz cuadrada (√A)
7. Salir
• Dependiendo de la opción seleccionada, el programa debe realizar
la operación correspondiente. Para las opciones de potencia y raíz
cuadrada, el programa debe validar que el número A sea positivo.
• Si el usuario selecciona una opción inválida, debe mostrarse un
mensaje de error y el menú debe repetirse.
• El programa debe seguir pidiendo operaciones hasta que el usuario
elija Salir.
• Si el usuario intenta dividir por cero, debe mostrarse un mensaje de
error y volver a pedir los números.
• En cada operación, se debe mostrar el resultado y preguntar si desea
hacer otra operación o salir. Si elige continuar, debe repetirse el
proceso.*/

#include <iostream>
#include <cmath> // Incluimos la libreria cmath para usar funciones matematicas
using namespace std;

int main()
{
    int opc;                     // Variable para almacenar
    float num1, num2, respuesta; // Variable para los numeros y la respuesta
    char continuar;              // Variable para controlar si se continua o no
    do                           // Ciclo de repeticion para el menu
    {
        // Mostamos el menu de opciones
        cout << "Menu de opciones de la calculadora avanzada:" << endl;
        cout << " 1. Suma " << endl;
        cout << " 2. Resta " << endl;
        cout << " 3. Multiplicacion " << endl;
        cout << " 4. Division " << endl;
        cout << " 5. Potencia (A^B) " << endl;
        cout << " 6. Raiz cuadrada " << endl;
        cout << " 7. Salir " << endl;
        cin >> opc; // Para leer la opcion del usuario

        switch (opc) // Usamos la estructura switch para realizar en cada caso la operacion correspondiente
        {
        case 1: // suma
        {
            cout << "Ingres el primer numero: " << endl;
            cin >> num1;
            cout << "Ingrese el segundo numero: " << endl;
            cin >> num2;
            respuesta = num1 + num2;
            cout << "El resultado de la suma es: " << respuesta << endl;
            break;
        }

        case 2: // resta
        {
            cout << "Ingres el primer numero: " << endl;
            cin >> num1;
            cout << "Ingrese el segundo numero: " << endl;
            cin >> num2;
            respuesta = num1 - num2;
            cout << "El resultado de la resta es: " << respuesta << endl;
            break;
        }

        case 3: // multiplicacion
        {
            cout << "Ingres el primer numero: " << endl;
            cin >> num1;
            cout << "Ingrese el segundo numero: " << endl;
            cin >> num2;
            respuesta = num1 * num2;
            cout << "El resultado de la multiplicacion es: " << respuesta << endl;
            break;
        }

        case 4: // division
        {
            cout << "Ingres el primer numero: " << endl;
            cin >> num1;
            cout << "Ingrese el segundo numero: " << endl;
            cin >> num2;
            if (num2 != 0) // Validamos que el segundo numero no sea cero
            {
                respuesta = num1 / num2;
                cout << "El resultado de la division es: " << respuesta << endl;
            }
            else
            {
                cout << "Error: No se puede dividir por cero." << endl;
            }
            break;
        }

        case 5: // potencia
        {
            cout << "Ingres el numero base (A): " << endl;
            cin >> num1;
            cout << "Ingrese el exponente (B): " << endl;
            cin >> num2;
            respuesta = pow(num1, num2); // Usamos la funcion pow para calcular la potencia
            cout << "El resultado de la potencia es: " << respuesta << endl;
            break;
        }

        case 6: // raiz cuadrada
        {
            cout << "Ingrese el numero para calcular su raiz cuadrada: " << endl;
            cin >> num1;
            if (num1 < 0) // Validamos que el numero sea positivo
            {
                cout << "Error: No se puede calcular la raiz cuadrada de un numero negativo." << endl;
            }
            else
            {
                respuesta = sqrt(num1); // Usamos la funcion sqrt para calcular la raiz cuadrada
                cout << "El resultado de la raiz cuadrada es: " << respuesta << endl;
            }
            break;
        }

        case 7: // salir
        {
            cout << "Gracias por usar la calculadora avanzada. Hasta luego!" << endl;
            return 0;
        }

        default: // opcion invalida
        {
            cout << "Opcion invalida. Por favor ingrese un numero del 1 al 7." << endl;
            break;
        }
        }
        // Preguntamos al usuario si desea realizar otra operacion
        cout << "Desea realizar otra operacion? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S'); // El ciclo continua si el usuario ingresa 's' o 'S'

    return 0;
}