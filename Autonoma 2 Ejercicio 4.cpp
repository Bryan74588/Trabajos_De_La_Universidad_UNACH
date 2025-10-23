/*Implementa un programa de control de acceso que simule un sistema de
seguridad en un edificio. El programa debe:
• Solicitar al usuario que ingrese su nombre de usuario y contraseña. Usa un
ciclo repetitivo para mantener el sistema pidiendo los datos hasta que el
usuario haya ingresado correctamente las credenciales.
• Si las credenciales son incorrectas (usuario o contraseña incorrectos), el
programa debe:
Mostrar un mensaje de error y permitir 3 intentos.
Si el usuario supera los 3 intentos sin éxito, mostrar el mensaje "Acceso
bloqueado" y finalizar el programa.
• Si el usuario ingresa correctamente las credenciales, el sistema debe:
Mostrar el mensaje de bienvenida y permitir que el usuario ingrese a un
menú de opciones:
1. Consultar saldo
2. Cambiar contraseña
3. Salir
En caso de seleccionar la opción 2 (Cambiar contraseña):
• Solicitar una nueva contraseña y confirmarla (el programa debe
asegurarse de que la contraseña confirmada coincida con la nueva).
• Si las contraseñas coinciden, cambiar la contraseña y mostrar un mensaje
de éxito. Si no coinciden, mostrar un mensaje de error y permitir reintentar
la confirmación.
• Al seleccionar 3 (Salir), el programa debe terminar.*/

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
