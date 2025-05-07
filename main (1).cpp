#include <iostream>

int main()
{
#include <iostream>

struct GestionDeLibros {
    char isbn[20];    // ISBN como cadena de caracteres
    char titulo[100];  // Título del libro
    float precio;
    int cantidad;
};

Libro libros[100];    // Máximo 100 libros
int totalLibros = 0;
float caja = 1000000; // Inversión inicial

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
        bool coincide = true;
        for (int j = 0; isbn[j] != '\0'; j++) {
            if (libros[i].isbn[j] != isbn[j]) {
                coincide = false;
                break;
            }
        }
        
        if (coincide) {
            if (libros[i].cantidad >= cantidad) {
                libros[i].cantidad -= cantidad;
                caja += libros[i].precio * cantidad;
                std::cout << "Venta realizada. Ganancia: $" 
                          << libros[i].precio * cantidad << "\n";
            } else {
                std::cout << "¡No hay suficiente stock!\n";
            }
           

    return 0;
}