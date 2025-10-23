#include <iostream>
#include <string>
using namespace std;

int main()
{
    const string correo = "Bryan";
    string contrasena = "1809";
    string entrada_correo, entrada_contrasena, nueva_contrasena, confirmar_contrasena;
    int intentos = 0;
    const int max_intentos = 3;
    int opc;
    float saldo = 0.0;
    char continuar;

    // Control de acceso
    while (intentos < max_intentos)
    {
        cout << "Ingrese su nombre de usuario: ";
        cin >> entrada_correo;  
        cout << "Ingrese su contrasena: ";
        cin >> entrada_contrasena;
        intentos++;

        if (entrada_correo == correo && entrada_contrasena == contrasena)
        {
            cout << "Bienvenido " << correo << endl;

            // Menú de opciones
            do
            {
                cout << "Menu de opciones:" << endl;
                cout << "1. Consultar saldo" << endl;
                cout << "2. Cambiar contrasena" << endl;
                cout << "3. Salir" << endl;
                cout << "Seleccione una opcion: ";
                cin >> opc;

                switch (opc)
                {
                case 1:
                    cout << "Ingrese su saldo inicial: ";
                    cin >> saldo;
                    cout << "Su saldo es: " << saldo << endl;
                    break;

                case 2:
                    cout << "Ingrese nueva contrasena: ";
                    cin >> nueva_contrasena;
                    cout << "Confirme la nueva contrasena: ";
                    cin >> confirmar_contrasena;

                    if (nueva_contrasena == confirmar_contrasena)
                    {
                        contrasena = nueva_contrasena;
                        cout << "Contrasena cambiada exitosamente." << endl;
                    }
                    else
                    {
                        cout << "Error: Las contrasenas no coinciden. Intente nuevamente." << endl;
                    }
                    break;

                case 3:
                    cout << "Saliendo del sistema." << endl;
                    break;

                default:
                    cout << "Opcion invalida. Intente nuevamente." << endl;
                }

                cout << "Desea realizar otra operacion? (s/n): ";
                cin >> continuar;

            } while (continuar == 's' || continuar == 'S');

            return 0; // Salir del programa después del menú
        }
        else
        {
            cout << "Error: Usuario o contrasena incorrectos. Intento " << intentos << " de " << max_intentos << "." << endl;
        }
    }

    // Si se agotan los intentos sin éxito
    cout << "Acceso bloqueado." << endl;
    return 0;
}
