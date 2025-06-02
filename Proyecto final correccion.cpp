#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // Para system("cls")
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

void mostrarPortada() {
    system("cls"); // Limpiar pantalla (Windows)
    //system("clear"); // Para Linux/Mac
    
    cout << "====================================" << endl;
    cout << "      PROYECTO #2 - LIBRERIA       " << endl;
    cout << "                                    " << endl;
    cout << "         AUTORES DEL PROGRAMA:     " << endl;
    cout << "                                    " << endl;
    cout << "         * Kevin Perea             " << endl;
    cout << "         * Andres Portillo         " << endl;
    cout << "                                    " << endl;
    cout << "====================================" << endl;
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void registrarLibro() {
    Libro nuevo;
    cout << "\nREGISTRAR NUEVO LIBRO\n";
    cout << "ISBN: "; cin >> nuevo.ISBN;
    cout << "Titulo: "; cin.ignore(); getline(cin, nuevo.titulo);
    cout << "Precio compra: "; cin >> nuevo.precioCompra;
    cout << "Precio venta: "; cin >> nuevo.precioVenta;
    cout << "Cantidad inicial: "; cin >> nuevo.cantidad;
    catalogo.push_back(nuevo);
    cout << "Libro registrado exitosamente!\n";
}

void abastecerLibro() {
    string isbn;
    int cantidad;
    cout << "\nABASTECER LIBRO\n";
    cout << "ISBN del libro: "; cin >> isbn;
    cout << "Cantidad a abastecer: "; cin >> cantidad;
    
    for (auto &libro : catalogo) {
        if (libro.ISBN == isbn) {
            libro.cantidad += cantidad;
            Transaccion t = {"abastecimiento", "hoy", cantidad};
            libro.transacciones.push_back(t);
            caja -= cantidad * libro.precioCompra;
            cout << "Abastecimiento exitoso! Nuevo stock: " << libro.cantidad << endl;
            return;
        }
    }
    cout << "Error: Libro no encontrado!\n";
}

void venderLibro() {
    string isbn;
    int cantidad;
    cout << "\nVENDER LIBRO\n";
    cout << "ISBN del libro: "; cin >> isbn;
    cout << "Cantidad a vender: "; cin >> cantidad;
    
    for (auto &libro : catalogo) {
        if (libro.ISBN == isbn) {
            if (libro.cantidad >= cantidad) {
                libro.cantidad -= cantidad;
                Transaccion t = {"venta", "hoy", cantidad};
                libro.transacciones.push_back(t);
                caja += cantidad * libro.precioVenta;
                cout << "Venta exitosa! Ganancia: $" << cantidad * libro.precioVenta << endl;
                cout << "Nuevo stock: " << libro.cantidad << endl;
            } else {
                cout << "Error: No hay suficientes ejemplares (Stock actual: " << libro.cantidad << ")\n";
            }
            return;
        }
    }
    cout << "Error: Libro no encontrado!\n";
}

void mostrarMenu() {
    cout << "\n=== MENU PRINCIPAL ===" << endl;
    cout << "1. Registrar nuevo libro" << endl;
    cout << "2. Abastecer libro" << endl;
    cout << "3. Vender libro" << endl;
    cout << "4. Mostrar dinero en caja" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    mostrarPortada();
    
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion) {
            case 1: registrarLibro(); break;
            case 2: abastecerLibro(); break;
            case 3: venderLibro(); break;
            case 4: 
                cout << "\nDinero en caja: $" << caja << endl;
                cout << "Total libros en catalogo: " << catalogo.size() << endl;
                break;
            case 5: cout << "\nSaliendo del sistema...\n"; break;
            default: cout << "\nOpcion invalida! Intente nuevamente.\n";
        }
    } while (opcion != 5);
    
    return 0;
}