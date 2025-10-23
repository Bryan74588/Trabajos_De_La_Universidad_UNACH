/*Crea un programa que permita simular diferentes métodos de pago en un
sistema de compras. El menú debe ofrecer las siguientes opciones:
2
• Pagar con tarjeta de crédito.
• Pagar con tarjeta de débito.
• Pagar en efectivo.
• Salir.
Según la opción seleccionada, el programa debe pedir al usuario el
monto total de la compra y realizar el cálculo del pago:
• Para tarjeta de crédito: Se aplica una comisión del 5%.
• Para tarjeta de débito: No se aplica comisión.
• Para pago en efectivo: Se aplica un descuento del 2%.
El ciclo debe continuar hasta que el usuario decida salir.
Consideraciones:
• Al final de cada operación, el programa debe mostrar el monto
total después de aplicar el descuento o la comisión, según
corresponda.
• Al elegir salir, el programa debe finalizar la ejecución.

Debe obligatoriamente comentar/documentar las líneas de código en
las que se soluciona el ejercicio (no todas las líneas, las esenciales)
*/

#include <iostream>
using namespace std;

int main()
{
    int opc;
    float monto_de_compra, total_de_la_compra;
    char continuar;

    // Utilizamos el ciclo do while para que el menu se siga repitiendo hasata que el usuario decida salir

    
        do
        {

            // Mostramos un menu de opciones para que escoja el metodo de pago
            cout << "Bienvendido al sistema de pago:" << endl;
            cout << "Con que desea pagar su compra?" << endl;
            cout << " 1. Tarjeta de credito " << endl;
            cout << " 2. Tarjeta de debito " << endl;
            cout << " 3. Pago en efectivo " << endl;
            cout << " 4. Salir " << endl;
            cin >> opc;
            // utilizamos la estructura switch para manejar las difetentes opciones del menu
            switch (opc)
            {

            case 1:
            {
                cout << "Ingrese el monto total de su compra: " << endl;
                cin >> monto_de_compra;
                total_de_la_compra = monto_de_compra + (monto_de_compra * 0.05);
                cout << "El total de su compra con la tarjeta de credito es : " << total_de_la_compra << endl;
                break;
            }
            case 2:
            {
                cout << "Ingrese el monto total de su compra: " << endl;
                cin >> monto_de_compra;
                total_de_la_compra = monto_de_compra;
                cout << "El total de su compra con la tarjeta de debito es : " << total_de_la_compra << endl;
                break;
            }
            case 3:
            {
                cout << "Ingrese el monto total de su compra: " << endl;
                cin >> monto_de_compra;
                total_de_la_compra = monto_de_compra - (monto_de_compra * 0.02);
                cout << "El total de su compra pagando en efectivo es : " << total_de_la_compra << endl;
                break;
            }
            case 4:
            {
                if (opc == 4)
                {
                    cout << "Gracias por usar el sistema de pago. Hasta luego!" << endl;
                    return 0;
                }
            }
            default:
            {
                cout << "Opcion no valida. Por favor, seleccione una opcion del 1 al 4." << endl;
                break;
            }
            }
            
            // Preguntamos al usuario si desea realizar otra operacion
            cout << "Desea realizar otra operacion? (s/n): ";
            cin >> continuar;

        } while (continuar == 's' || continuar == 'S');

    return 0;
}