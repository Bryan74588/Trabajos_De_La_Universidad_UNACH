/*. Desarrolla un programa que resuelva ecuaciones cuadráticas de la
forma ax² + bx + c = 0.
Implementa una función que calcule el discriminante (D = b² - 4ac) y
otra función que, según su valor, determine si la ecuación tiene:
• Dos soluciones reales y distintas
• Una solución real doble
• Dos soluciones complejas
Las soluciones deben mostrarse con dos cifras decimales si existen.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// Función para calcular el discriminante
float calcularDiscriminante(float a, float b, float c)
{
    return b * b - 4 * a * c; // Fórmula del discriminante D = b² - 4ac
}
// Función para calcular y mostrar las soluciones según el valor del discriminante
void calcularSoluciones(float a, float b, float c)
{
    float D = calcularDiscriminante(a, b, c); // Llamada a la función para obtener el discriminante

    cout << fixed << setprecision(2); // Configurar la salida para mostrar dos cifras decimales

    if (D > 0)
    {
        // Dos soluciones reales y distintas
        float x1 = (-b + sqrt(D)) / (2 * a);
        float x2 = (-b - sqrt(D)) / (2 * a);
        cout << "La ecuacion tiene dos soluciones reales y distintas:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (D == 0)
    {
        // Una solución real doble
        float x = -b / (2 * a);
        cout << "La ecuacion tiene una solucion real doble:" << endl;
        cout << "x = " << x << endl;
    }
    else
    {
        // Dos soluciones complejas
        float partereal = -b / (2 * a);
        float parteimaginaria = sqrt(-D) / (2 * a);
        cout << "La ecuacion tiene dos soluciones complejas:" << endl;
        cout << "x1 = " << partereal << " + " << parteimaginaria << "i" << endl;
        cout << "x2 = " << partereal << " - " << parteimaginaria << "i" << endl;
    }
}

int main()
{
    float a, b, c; // Coeficientes de la ecuación cuadrática

    // Solicitar al usuario que ingrese los coeficientes a, b y c
    cout << "Ingrese el numero a: ";
    cin >> a;
    cout << "Ingrese el numero b: ";
    cin >> b;
    cout << "Ingrese el numero c: ";
    cin >> c;

    // Llamar a la función para calcular y mostrar las soluciones
    calcularSoluciones(a, b, c);

    return 0;
}