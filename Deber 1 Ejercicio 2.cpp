#include <iostream>
#include <string>
#include <iomanip>  
using namespace std;

int main() {
    float pre, imp, des = 0.0, pre_final, precio_descuento;
    string cat;

     system("chcp 65001 > nul");
    cout << "Ingrese el precio del producto: ";
    cin >> pre;
    cout << "Ingrese la categoría del producto (Electronica, Ropa, Alimentos): ";
    cin >> cat;

    des = (pre > 1000) ? pre * 0.10 : 0.0;
    precio_descuento = pre - des;

    imp = (cat == "Electronica") ? precio_descuento * 0.20 :
               (cat == "Ropa") ? precio_descuento * 0.10 :
               (cat == "Alimentos") ? precio_descuento * 0.05 : 0.0;

    pre_final = precio_descuento + imp;

    cout << "-------Recibo-------" << endl;
    cout << "Precio original: $" << pre << endl;
    cout << "Descuento aplicado: $" << des << endl;
    cout << "Impuesto aplicado: $" << imp << endl;
    cout << "Precio final: $" << pre_final << endl;

    return 0;
}