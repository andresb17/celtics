#include <iostream>
#include <cstring> 

struct Libro {  
    char isbn[20];    
    char titulo[100];  
    float precio;
    int cantidad;
};

Libro libros[100];    
int totalLibros = 0;
float caja = 1000000; 

void registrarLibro() {
    if (totalLibros >= 100) {
        std::cout << "¡No caben mas libros!\n";
        return;
    }

    Libro l;
    std::cout << "ISBN: ";
    std::cin >> l.isbn;
    std::cout << "Titulo: ";
    std::cin.ignore();
    std::cin.getline(l.titulo, 100);
    std::cout << "Precio: ";
    std::cin >> l.precio;
    std::cout << "Cantidad: ";
    std::cin >> l.cantidad;

    libros[totalLibros] = l;
    totalLibros++;
    std::cout << "Libro registrado!\n";
}

void venderLibro() {
    char isbn[20];
    int cantidad;
    std::cout << "ISBN del libro a vender: ";
    std::cin >> isbn;
    std::cout << "Cantidad: ";
    std::cin >> cantidad;

    for (int i = 0; i < totalLibros; i++) {
        if (strcmp(libros[i].isbn, isbn) == 0) {  
            if (libros[i].cantidad >= cantidad) {
                libros[i].cantidad -= cantidad;
                caja += libros[i].precio * cantidad;
                std::cout << "Venta realizada. Ganancia: $" 
                          << libros[i].precio * cantidad << "\n";
            } else {
                std::cout << "¡No hay suficiente stock!\n";
            }
            return;
        }
    }
    std::cout << "¡Libro no encontrado!\n";
}

int main() {
    // Menú de opciones
    int opcion;
    do {
        std::cout << "\n1. Registrar libro\n";
        std::cout << "2. Vender libro\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch(opcion) {
            case 1:
                registrarLibro();
                break;
            case 2:
                venderLibro();
                break;
            case 3:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion no valida!\n";
        }
    } while (opcion != 3);

    return 0;
}