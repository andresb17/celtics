#include <iostream>
#include <string>
using namespace std;

int main() 
{
    
    const int NUM_GENEROS = 5;
    const int NUM_SUCURSALES = 3;
    
    string generos[NUM_GENEROS] = {"Ficción", "Ciencia", "Romance", "Terror", "Biografías"};
    string sucursales[NUM_SUCURSALES] = {"Sucursal A", "Sucursal B", "Sucursal C"};
    
    
    int libros_rentados[NUM_SUCURSALES][NUM_GENEROS] = {0};
    
    libros_rentados[0][0] = 10; 
    libros_rentados[0][1] = 5;  
    libros_rentados[1][2] = 8;  
    libros_rentados[2][3] = 3;  
    libros_rentados[2][4] = 7;  
    
    
    cout << "REPORTE DE LIBROS RENTADOS\n";
    

    cout << "Sucursal\t";
    for (int g = 0; g < NUM_GENEROS; g++) {
        cout << generos[g] << "\t";
    }
    cout << "Total\n";
    

    for (int s = 0; s < NUM_SUCURSALES; s++) {
        cout << sucursales[s] << "\t";
        int total_sucursal = 0;
        
        for (int g = 0; g < NUM_GENEROS; g++) {
            cout << libros_rentados[s][g] << "\t";
            total_sucursal += libros_rentados[s][g];
        }
        
        cout << total_sucursal << "\n";
    }
    
    cout << "\nTotal por género:\t";
    for (int g = 0; g < NUM_GENEROS; g++) {
        int total_genero = 0;
        for (int s = 0; s < NUM_SUCURSALES; s++) {
            total_genero += libros_rentados[s][g];
        }
        cout << total_genero << "\t";
    }
    
    return 0;
}