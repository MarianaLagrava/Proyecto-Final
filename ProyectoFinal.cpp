#include <iostream>
#include <cmath>
#include <string>
//!!!!La funcion main esta colocada hasta el final, despues de las funciones.
using namespace std;
void LeerDatos();// Declaracion de funciones
void CalcularCosto();
void DesplegarDatos();
void TotalCompra();

const int longCad = 20;// Estructura para manejar datos de la factura
struct costoPorArticulo
{
    char nombreArticul[longCad + 1];
    int cantidad;
    float precio;
    float costoPorArticulo;
};

void LeerDatos(int cantProd, costoPorArticulo Listadeproductos[])//Funcion donde se ingresan los
{                                                                //datos para emitir la factura
    for (int i = 0; i < cantProd; i++)                           // (literal b)
    {
        cout << "Ingrese el nombre del articulo (sin espacios) " << i + 1 << ":" << endl;
        cin >> Listadeproductos[i].nombreArticul,20;// se ingresa el nombre del producto
        cout << "Ingrese la cantidad de unidades por el articulo " << i + 1 << ":" << endl;
        cin >> Listadeproductos[i].cantidad;//se ingresan la cantidad de unidades por articulo
        cout << "Ingrese el precio unitario por el articulo " 
        << i + 1 << ":" << endl;
        cin >> Listadeproductos[i].precio;//se ingresa el precio unitario en dolares por 
                                          //producto
    }
}

void CalcularCosto(int cantProd, costoPorArticulo Listadeproductos[])//Funcion para calcular 
{                                                                    //el total por producto
    float totalporproducto;                                          // (Literal c)
    int i;
    for (i = 0; i < cantProd; i++)
    {
        totalporproducto = Listadeproductos[i].cantidad * Listadeproductos[i].precio;
        Listadeproductos[i].costoPorArticulo = totalporproducto;//se agrega la multiplicacion de
    }                                                           //la cantidad por precio unitario
}                                                               //en la variable del structure 

void DesplegarDatos(int cantProd, costoPorArticulo Listadeproductos[])//funcion para mostrar los
{                                                                     //datos del structure(literal d)
cout<< "----------------------------EMISION DE SU FACTURA-----------------------------"<<endl;
    for (int i = 0; i < cantProd; i++)
    {// Se muestran accediendo a cada variable del structure
        cout << "Nombre del producto ------"<<Listadeproductos[i].nombreArticul << endl;
        cout << "Cantidad -----------------"<<Listadeproductos[i].cantidad << endl;
        cout << "Precio unitario ----------"<<Listadeproductos[i].precio << "$"<< endl;
        cout << "Precio total -------------"<<Listadeproductos[i].costoPorArticulo<< "$"<< endl;
        cout << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    }
}

void TotalCompra(int cantProd, costoPorArticulo Listadeproductos[])//funcion para calcular el valor
{                                                                  //total de la compra (literal e)
    float CompraTotal;
    for(int i=0; i< cantProd; i++){
        CompraTotal+= Listadeproductos[i].costoPorArticulo;//Por medio de un bucle, se van sumando
    }                                                      // los valores almacenados en 
    cout <<"El total de su compra es: " << CompraTotal<< "$"<<endl;//costoPorArticulo de cada structure
    cout << "     Gracias por su compra.   "<<endl;
}

int main(void)//Funcion main (Literal a)
{
    int cantProd = 0;
    cout << "EMISION DE FACTURA" << endl;
    cout << "Ingrese el numero de productos" << endl;
    cin >> cantProd;// Se solicita el ingreso de cantidad de productos
    costoPorArticulo ListadeProductos[cantProd]; //se declara el array para almacenar datos tipo structure
    //Se llaman a las funciones
    LeerDatos(cantProd, ListadeProductos);
    CalcularCosto(cantProd, ListadeProductos);
    DesplegarDatos(cantProd, ListadeProductos);
    TotalCompra(cantProd, ListadeProductos);
}
