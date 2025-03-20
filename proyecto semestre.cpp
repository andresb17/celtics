#include <iostream>
using namespace std;
int main()

{
int caja=1000000, opc;
 cout<<"\tbienvenidos a la libreria "<<endl;
 cout<<"1. registre el nombre del libro "<<endl;
 cout<<"2. eliminar libro "<<endl;
 cout<<"3. buscar libro por titulo"<<endl;
 cout<<"4. buscar libro por ISBN"<<endl;
 cout<<"5. abastecer catalogo de libros"<<endl;
 cout<<"6. vender ejemplares de libros"<<endl;
 cout<<"7. calcular la cantidad de transacciones de abastecimeinto de un libro en particular"<<endl;
 cout<<"8. buscar el libro más costoso"<<endl;
 cout<<"9. buscar el libro más econnomico"<<endl;
 cout<<"10. buscar el libro mas vendido"<<endl;
 cin>> opc;
 switch(opc){
     case 1:
     cout<<"Registro exitoso "<<endl;
     break;
     case 2:
     cout<<"Se ha eliminado "<<endl;
     break;
     case 3:
     cout<<"Ingrese el titulo"<<endl;
     break;
     case 4:
     cout<<"Ingresa el ISBN"<<endl;
     break;
     case 5:
     cout<<"abastecido"<<endl;
     break;
     case 6:
     cout<<"vendido"<<endl;
     case 7:
     cout<<"7. se realizo x transacciones de x"<<endl;
     break;
     case 8:
     cout<<"8. este son los ejmeplares mas cuantiosos "<<endl;
     break;
     case 9:
     cout<<"9. buscar el libro más econnomico"<<endl;
     break;
     case 10:
     cout<<"10. buscar el libro mas vendido"<<endl;
     break;
 }
 
 
 
 //cin>>caja;
 
    return 0;
}