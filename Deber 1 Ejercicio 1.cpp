#include <iostream>
#include <string>
using namespace std;

int main()
{
    int expe;
    string nivel_educativo;
    string resultado;


    system("chcp 65001 > nul");
    cout << "Ingrese sus años de experiencia: " << endl;
    cin >> expe;
    cout << "Ingrese su nivel educativo (Primaria, Secundaria, Universitaria): " << endl;
    cin >> nivel_educativo;

    resultado = (expe >= 5 && nivel_educativo == "Universitaria") ? "Aprobado" :
                (expe >= 3 &&  nivel_educativo == "Secundaria") ? "Aprobado" :
                "No Aprobado";

    cout << "Resultado de la oferta de empleo: " << resultado << endl;

    return 0;
}
