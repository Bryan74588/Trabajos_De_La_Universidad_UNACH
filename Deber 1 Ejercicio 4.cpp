#include <iostream>
using namespace std;

int main()
{
     system("chcp 65001 > nul");
    const int num = 56; 
    int inten, cont_inten = 0;
    bool adiv = false;

    while (cont_inten < 5 && !adiv)
    {
        cout << "Ingrese un numero cualquiera: ";
        cin >> inten;
        cont_inten++;

        if (inten == num)
        {
            cout << "¡Perfecto! Lo lograste en:  " << cont_inten << " intentos." << endl;
            adiv = true;
        }
        else
        {
            cout << (inten > num ? "El numero que pusiste es demasiado alto: " : "El numero que pusiste es demasiado bajo: ") << endl;
        }
    }

    if (!adiv)
    {
        cout << "Lo siento, se te terminaron los intentos." << "El número era " << num << "." << endl;
    }

    return 0;
}

