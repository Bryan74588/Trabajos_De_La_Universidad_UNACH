#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;

// funciones de lectura con validacion 
int leerEntero(string msg, int min) {
    int x;
    do {
        cout << msg;
        cin >> x;
        if (cin.fail() || x < min) {
            cin.clear();
            cin.ignore(1000);
            cout << "Valor invalido. Intente nuevamente." << endl;
        }
    } while (x < min);
    return x;
}

double leerDecimales(string msg, double min) {
    double x;
    do {
        cout << msg;
        cin >> x;
        if (cin.fail() || x < min) {
            cin.clear();
            cin.ignore(1000);
            cout << "Valor invalido. Intente nuevamente." << endl;
        }
    } while (x < min);
    return x;
}

// Ingreso de datos 
void Ingdatos(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias) {
    int n = leerEntero("Cuantos dias desea registrar? ", 1);

    for (int i = 0; i < n; i++) {
        cout << "Dia " << i << endl;
        pasos.push_back(leerEntero("Pasos del dia: ", 0));
        minutos.push_back(leerEntero("Minutos de actividad: ", 0));
        calorias.push_back(leerDecimales("Calorias quemadas: ", 0));
    }
}

// Mostrar los datos
void Mostrar(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias) {
    cout << "Dia\tPasos\tMinutos\tCalorias" << endl;
    for (int i = 0; i < pasos.size(); i++) {
        cout << i << "\t" << pasos[i] << "\t" << minutos[i] << "\t" << calorias[i] << endl;
    }
}

// Funcion para insertar datos
void InsetrarDatos(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias) {
    int pos = leerEntero("Posicion a insertar: ", 0);

    pasos.insert(pasos.begin() + pos, leerEntero("Pasos: ", 0));
    minutos.insert(minutos.begin() + pos, leerEntero("Minutos: ", 0));
    calorias.insert(calorias.begin() + pos, leerDecimales("Calorias: ", 0));
}

// Funcion par modificar los datos
void ModificarDatos(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias) {
    int pos = leerEntero("Dia a modificar: ", 0);

    pasos[pos] = leerEntero("Nuevo pasos: ", 0);
    minutos[pos] = leerEntero("Nuevo minutos: ", 0);
    calorias[pos] = leerDecimales("Nueva calorias: ", 0);
}

// Funcion para buscar datos
void BuscarDatos(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias) {
    int valor = leerEntero("Ingrese pasos a buscar: ", 0);

    for (int i = 0; i < pasos.size(); i++) {
        if (pasos[i] == valor) {
            cout << "Dia " << i << ": " << pasos[i] << " pasos, "
                 << minutos[i] << " minutos, "
                 << calorias[i] << " calorias" << endl;
        }
    }
}

// Funcion para ordenar los datos
void Ordenardatos(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias, bool asc) {
    for (int i = 0; i < pasos.size() - 1; i++) {
        for (int j = i + 1; j < pasos.size(); j++) {
            if ((asc && pasos[i] > pasos[j]) || (!asc && pasos[i] < pasos[j])) {
                swap(pasos[i], pasos[j]);
                swap(minutos[i], minutos[j]);
                swap(calorias[i], calorias[j]);
            }
        }
    }
}

// Funcion para eliminar datos
void EliminarDatos(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias) {
    int pos = leerEntero("Posicion a eliminar: ", 0);

    pasos.erase(pasos.begin() + pos);
    minutos.erase(minutos.begin() + pos);
    calorias.erase(calorias.begin() + pos);
}

// Funcion para la estadistica
double media(vector<double> v) {
    double s = 0;
    for (double x : v) s += x;
    return s / v.size();
}

double mediana(vector<double> v) {
    sort(v.begin(), v.end());
    int n = v.size();
    if (n % 2 == 0)
        return (v[n/2 - 1] + v[n/2]) / 2;
    else
        return v[n/2];
}

double moda(vector<double> v) {
    map<double, int> f;
    for (double x : v) f[x]++;
    int max = 0;
    double moda = v[0];
    for (auto p : f) {
        if (p.second > max) {
            max = p.second;
            moda = p.first;
        }
    }
    return moda;
}

// Funcion para mostrar los resultados estadisticos
void Mostrarestadistica(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias) {
    vector<double> p(pasos.begin(), pasos.end());
    vector<double> m(minutos.begin(), minutos.end());

    cout << "PASOS - Media: " << media(p) << " Mediana: " << mediana(p) << " Moda: " << moda(p) << endl;
    cout << "MINUTOS - Media: " << media(m) << " Mediana: " << mediana(m) << " Moda: " << moda(m) << endl;
    cout << "CALORIAS - Media: " << media(calorias) << " Mediana: " << mediana(calorias) << " Moda: " << moda(calorias) << endl;

    cout << "Analisis adicional:" << endl;
    cout << "Promedio de pasos por minuto: " << media(p) / media(m) << endl;
    cout << "Promedio de calorias por minuto: " << media(calorias) / media(m) << endl;
}

// Funcion principal con el menu
int main() {
    vector<int> pasos, minutos;
    vector<double> calorias;

    int op;
    do {
        cout << "===== MENU =====" << endl;
        cout << " 1.Ingresar datos" << endl;
        cout << " 2.Mostrar datos" << endl;
        cout << " 3.Insertar datos" << endl;
        cout << " 4.Modificar datos" << endl;
        cout << " 5.Buscar datos" << endl;
        cout << " 6.Ordenar ascendente" << endl;
        cout << " 7.Ordenar descendente" << endl;
        cout << " 8.Eliminar datos" << endl;
        cout << " 9.Estadisticas de los datos" << endl;
        cout << " 0.Salir" << endl;     

        op = leerEntero("Opcion: ", 0);

        switch (op) {
            case 1: Ingdatos(pasos, minutos, calorias); break;
            case 2: Mostrar(pasos, minutos, calorias); break;
            case 3: InsetrarDatos(pasos, minutos, calorias); break;
            case 4: ModificarDatos(pasos, minutos, calorias); break;
            case 5: BuscarDatos(pasos, minutos, calorias); break;
            case 6: Ordenardatos(pasos, minutos, calorias, true); break;
            case 7: Ordenardatos(pasos, minutos, calorias, false); break;
            case 8: EliminarDatos(pasos, minutos, calorias); break;
            case 9: Mostrarestadistica(pasos, minutos, calorias); break;
        }

    } while (op != 0);

    return 0;
}
