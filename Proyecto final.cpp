#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Transaccion {
    string tipo;
    string fecha;
    int cantidad;
};

struct Libro {
    string ISBN;
    string titulo;
    double precioCompra;
    double precioVenta;
    int cantidad;
    vector<Transaccion> transacciones;
};

vector<Libro> catalogo;
double caja = 1000000.0; // Inversión inicial

void registrarLibro() {
    Libro nuevo;
    cout << "ISBN: "; cin >> nuevo.ISBN;
    cout << "Titulo: "; cin.ignore(); getline(cin, nuevo.titulo);
    cout << "Precio compra: "; cin >> nuevo.precioCompra;
    cout << "Precio venta: "; cin >> nuevo.precioVenta;
    cout << "Cantidad: "; cin >> nuevo.cantidad;
    catalogo.push_back(nuevo);
    cout << "Libro registrado!\n";
}

void abastecerLibro() {
    string isbn;
    int cantidad;
    cout << "ISBN del libro: "; cin >> isbn;
    cout << "Cantidad a abastecer: "; cin >> cantidad;
    
    for (auto &libro : catalogo) {
        if (libro.ISBN == isbn) {
            libro.cantidad += cantidad;
            Transaccion t = {"abastecimiento", "hoy", cantidad};
            libro.transacciones.push_back(t);
            caja -= cantidad * libro.precioCompra;
            cout << "Abastecido!\n";
            return;
        }
    }
    cout << "Libro no encontrado!\n";
}

void venderLibro() {
    string isbn;
    int cantidad;
    cout << "ISBN del libro: "; cin >> isbn;
    cout << "Cantidad a vender: "; cin >> cantidad;
    
    for (auto &libro : catalogo) {
        if (libro.ISBN == isbn) {
            if (libro.cantidad >= cantidad) {
                libro.cantidad -= cantidad;
                Transaccion t = {"venta", "hoy", cantidad};
                libro.transacciones.push_back(t);
                caja += cantidad * libro.precioVenta;
                cout << "Vendido! Ganancia: $" << cantidad * libro.precioVenta << endl;
            } else {
                cout << "No hay suficientes ejemplares!\n";
            }
            return;
        }
    }
    cout << "Libro no encontrado!\n";
}

void mostrarMenu() {
    cout << "\n=== MENU LIBRERIA ===" << endl;
    cout << "1. Registrar libro" << endl;
    cout << "2. Abastecer libro" << endl;
    cout << "3. Vender libro" << endl;
    cout << "4. Mostrar caja" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion) {
            case 1: registrarLibro(); break;
            case 2: abastecerLibro(); break;
            case 3: venderLibro(); break;
            case 4: cout << "Dinero en caja: $" << caja << endl; break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida!\n";
        }
    } while (opcion != 5);
    
    return 0;
}