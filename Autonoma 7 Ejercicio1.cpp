#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ---------- PROTOTIPOS DE FUNCIONES ----------

// Muestra el menu principal
void Menu();

// Valida que el usuario ingrese un numero dentro de un rango
int Validacionentero(int min, int max);

// Funciones principales del sistema
void Guardarlibro(vector<vector<string>> &libros,
                  vector<vector<int>> &stock,
                  vector<vector<int>> &prestamos);

void Insertarlibro(vector<vector<string>> &libros,
                   vector<vector<int>> &stock,
                   vector<vector<int>> &prestamos);

void Actualizarprestamo(vector<vector<string>> &libros,
                        vector<vector<int>> &stock,
                        vector<vector<int>> &prestamos);

void Mostrardisponibles(const vector<vector<string>> &libros,
                        const vector<vector<int>> &stock);

void Modificarlibro(vector<vector<string>> &libros,
                    vector<vector<int>> &stock);

void Eliminarlibro(vector<vector<string>> &libros,
                   vector<vector<int>> &stock,
                   vector<vector<int>> &prestamos);

void Buscarlibro(const vector<vector<string>> &libros);

void Ordenarlibros(vector<vector<string>> &libros,
                   vector<vector<int>> &stock,
                   vector<vector<int>> &prestamos);

void Reporteinventario(const vector<vector<string>> &libros,
                       const vector<vector<int>> &stock,
                       const vector<vector<int>> &prestamos);

// Muestra la lista de libros con su ID
void Mostrarlista(const vector<vector<string>> &libros);

// ---------- FUNCION PRINCIPAL ----------
int main() {

    // Matriz de libros: nombre y categoria
    vector<vector<string>> libros;

    // Matriz de stock: disponibles y prestados
    vector<vector<int>> stock;

    // Matriz de prestamos por dia (lunes a viernes)
    vector<vector<int>> prestamos;

    int opc;

    // Menu interactivo
    do {
        Menu();
        opc = Validacionentero(0, 9);

        switch (opc) {
        case 1: Guardarlibro(libros, stock, prestamos); break;
        case 2: Insertarlibro(libros, stock, prestamos); break;
        case 3: Actualizarprestamo(libros, stock, prestamos); break;
        case 4: Mostrardisponibles(libros, stock); break;
        case 5: Modificarlibro(libros, stock); break;
        case 6: Eliminarlibro(libros, stock, prestamos); break;
        case 7: Buscarlibro(libros); break;
        case 8: Ordenarlibros(libros, stock, prestamos); break;
        case 9: Reporteinventario(libros, stock, prestamos); break;
        }
    } while (opc != 0);

    // Mensaje de despedida
    cout << endl;
    cout << "Gracias por venir a la biblioteca." << endl;
    cout << "Si quieres mas libros aqui seguimos" << endl;
    cout << "Hasta el otro año xD" << endl;

    return 0;
}

// ---------- DESARROLLO DE FUNCIONES ----------

// Muestra el menu principal
void Menu() {
    cout << endl << "--- BIBLIOTECA ESCOLAR ---" << endl;
    cout << "1. Guardar libro" << endl;
    cout << "2. Insertar libro" << endl;
    cout << "3. Registrar prestamo" << endl;
    cout << "4. Mostrar libros disponibles" << endl;
    cout << "5. Modificar libro" << endl;
    cout << "6. Eliminar libro" << endl;
    cout << "7. Buscar libro" << endl;
    cout << "8. Ordenar libros" << endl;
    cout << "9. Reporte de inventario" << endl;
    cout << "0. Salir" << endl;
    cout << "Opcion: ";
}

// Valida numeros para evitar errores
int Validacionentero(int min, int max) {
    int x;
    while (true) {
        cin >> x;
        if (cin.fail() || x < min || x > max) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Dato invalido. Intente otra vez: ";
        } else {
            cin.ignore();
            return x;
        }
    }
}

// Muestra los libros con su ID
void Mostrarlista(const vector<vector<string>> &libros) {
    cout << endl << "Lista de libros:" << endl;
    for (int i = 0; i < libros.size(); i++) {
        cout << i << " - " << libros[i][0] << endl;
    }
}

// Guarda un libro al final del vector
void Guardarlibro(vector<vector<string>> &libros,
                  vector<vector<int>> &stock,
                  vector<vector<int>> &prestamos) {

    string nombre, categoria;
    int cantidad;

    cout << "Nombre del libro: ";
    getline(cin, nombre);

    cout << "Categoria: ";
    getline(cin, categoria);

    cout << "Stock inicial: ";
    cantidad = Validacionentero(0, 1000);

    libros.push_back({nombre, categoria});
    stock.push_back({cantidad, 0});
    prestamos.push_back({0, 0, 0, 0, 0});
}

// Inserta un libro en una posicion especifica
void Insertarlibro(vector<vector<string>> &libros,
                   vector<vector<int>> &stock,
                   vector<vector<int>> &prestamos) {

    int pos;
    cout << "Posicion donde insertar: ";
    pos = Validacionentero(0, libros.size());

    string nombre, categoria;
    int cantidad;

    cout << "Nombre: ";
    getline(cin, nombre);

    cout << "Categoria: ";
    getline(cin, categoria);

    cout << "Stock: ";
    cantidad = Validacionentero(0, 1000);

    libros.insert(libros.begin() + pos, {nombre, categoria});
    stock.insert(stock.begin() + pos, {cantidad, 0});
    prestamos.insert(prestamos.begin() + pos, {0, 0, 0, 0, 0});
}

// Registra un prestamo y actualiza el stock
void Actualizarprestamo(vector<vector<string>> &libros,
                        vector<vector<int>> &stock,
                        vector<vector<int>> &prestamos) {

    if (libros.empty()) {
        cout << "No hay libros registrados." << endl;
        return;
    }

    Mostrarlista(libros);

    int id, dia;
    cout << "ID del libro: ";
    id = Validacionentero(0, libros.size() - 1);

    if (stock[id][0] > 0) {
        cout << "Dia (0=Lun a 4=Vie): ";
        dia = Validacionentero(0, 4);

        stock[id][0]--;       // reduce stock disponible
        stock[id][1]++;       // aumenta prestados
        prestamos[id][dia]++; // registra el dia
    } else {
        cout << "No hay stock disponible." << endl;
    }
}

// Muestra solo libros con stock disponible
void Mostrardisponibles(const vector<vector<string>> &libros,
                        const vector<vector<int>> &stock) {

    cout << endl << "Libros disponibles:" << endl;
    for (int i = 0; i < libros.size(); i++) {
        if (stock[i][0] > 0) {
            cout << i << " - " << libros[i][0]
                 << " (Stock: " << stock[i][0] << ")" << endl;
        }
    }
}

// Modifica los datos de un libro
void Modificarlibro(vector<vector<string>> &libros,
                    vector<vector<int>> &stock) {

    if (libros.empty()) {
        cout << "No hay libros registrados." << endl;
        return;
    }

    Mostrarlista(libros);

    int id;
    cout << "ID del libro: ";
    id = Validacionentero(0, libros.size() - 1);

    cout << "Nuevo nombre: ";
    getline(cin, libros[id][0]);

    cout << "Nueva categoria: ";
    getline(cin, libros[id][1]);

    cout << "Nuevo stock: ";
    stock[id][0] = Validacionentero(0, 1000);
}

// Elimina un libro del sistema
void Eliminarlibro(vector<vector<string>> &libros,
                   vector<vector<int>> &stock,
                   vector<vector<int>> &prestamos) {

    if (libros.empty()) {
        cout << "No hay libros registrados." << endl;
        return;
    }

    Mostrarlista(libros);

    int id;
    cout << "ID a eliminar: ";
    id = Validacionentero(0, libros.size() - 1);

    libros.erase(libros.begin() + id);
    stock.erase(stock.begin() + id);
    prestamos.erase(prestamos.begin() + id);
}

// Busca libros por nombre o categoria
void Buscarlibro(const vector<vector<string>> &libros) {

    if (libros.empty()) {
        cout << "No hay libros registrados." << endl;
        return;
    }

    string clave;
    cout << "Buscar por nombre o categoria: ";
    getline(cin, clave);

    for (int i = 0; i < libros.size(); i++) {
        if (libros[i][0].find(clave) != string::npos ||
            libros[i][1].find(clave) != string::npos) {
            cout << i << " - " << libros[i][0]
                 << " (" << libros[i][1] << ")" << endl;
        }
    }
}

// Ordena los libros alfabeticamente
void Ordenarlibros(vector<vector<string>> &libros,
                   vector<vector<int>> &stock,
                   vector<vector<int>> &prestamos) {

    for (int i = 0; i < libros.size() - 1; i++) {
        for (int j = i + 1; j < libros.size(); j++) {
            if (libros[i][0] > libros[j][0]) {
                swap(libros[i], libros[j]);
                swap(stock[i], stock[j]);
                swap(prestamos[i], prestamos[j]);
            }
        }
    }
}

// Genera el reporte de inventario
void Reporteinventario(const vector<vector<string>> &libros,
                       const vector<vector<int>> &stock,
                       const vector<vector<int>> &prestamos) {

    cout << endl << "--- REPORTE DE INVENTARIO ---" << endl;

    for (int i = 0; i < libros.size(); i++) {
        int total = 0;

        // suma de prestamos de la semana
        for (int d = 0; d < 5; d++) {
            total += prestamos[i][d];
        }

        if (stock[i][0] == 0) {
            cout << "AGOTADO: ";
        }

        cout << libros[i][0]
             << " | Prestamos semanales: " << total << endl;
    }
}
