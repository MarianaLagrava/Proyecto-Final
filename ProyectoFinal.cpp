#include <iostream>
#include <cmath>
#include <string>


using namespace std;
void LeerDatos();
void CalcularCosto();
void DesplegarDatos();
void TotalCompra();

const int longCad = 20;
struct costoPorArticulo
{
    char nombreArticul[longCad + 1];
    int cantidad;
    float precio;
    float costoPorArticulo;
};

void LeerDatos(int cantProd, costoPorArticulo Listadeproductos[])
{
    for (int i = 0; i < cantProd; i++)
    {
        cout << "Ingrese el nombre del articulo " << i + 1 << ":" << endl;
        cin >> Listadeproductos[i].nombreArticul;
        cout << "Ingrese la cantidad de unidades por el articulo " << i + 1 << ":" << endl;
        cin >> Listadeproductos[i].cantidad;
        cout << "Ingrese el precio unitario por el articulo (USD) " << i + 1 << ":" << endl;
        cin >> Listadeproductos[i].precio;
    }
}

void CalcularCosto(int cantProd, costoPorArticulo Listadeproductos[])
{
    float total;
    int i;
    for (i = 0; i < cantProd; i++)
    {
        total = Listadeproductos[i].cantidad * Listadeproductos[i].precio;
        Listadeproductos[i].costoPorArticulo = total;
    }
}

void DesplegarDatos(int cantProd, costoPorArticulo Listadeproductos[])
{

    for (int i = 0; i < cantProd; i++)
    {
        cout << "Nombre del producto ------"<< Listadeproductos[i].nombreArticul << endl;
        cout << "Cantidad -----------------"<<Listadeproductos[i].cantidad << endl;
        cout << "Precio unitario ----------"<< Listadeproductos[i].precio << "$"<< endl;
        cout << "Precio total -------------" <<Listadeproductos[i].costoPorArticulo<< "$"<< endl;
        cout << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    }
}

void TotalCompra(int cantProd, costoPorArticulo Listadeproductos[])
{
    float CompraTotal;
    for(int i=0; i< cantProd; i++){
        CompraTotal+= Listadeproductos[i].costoPorArticulo;
    }
    cout <<"El total de su compra es: " << CompraTotal<< "$";
}

int main(void)
{
    int cantProd = 0;
    cout << "EMISION DE FACTURA" << endl;
    cout << "Ingrese el numero de productos" << endl;
    cin >> cantProd;
    costoPorArticulo ListadeProductos[cantProd];
    LeerDatos(cantProd, ListadeProductos);
    CalcularCosto(cantProd, ListadeProductos);
    DesplegarDatos(cantProd, ListadeProductos);
    TotalCompra(cantProd, ListadeProductos);
}