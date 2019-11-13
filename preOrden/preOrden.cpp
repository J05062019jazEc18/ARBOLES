#include <iostream>
#include <cstdlib>
using namespace std;

struct Nodo{
     int dato;
     struct Nodo *izq, *der;
};

typedef struct Nodo *Arbl;
Arbl crearNodo(int dtos);
void insertar(Arbl &arbol, int dtos);
void preOrden(Arbl arbol);


int main()
{
    Arbl arbol = NULL;   

    int nodos;  
    int dtos; 

    cout << "   ARBOL EN PREORDEN";
	cout <<endl;
    cout << " Ingrese en numero de datos del arbol:  ";
    cin >> nodos;
    cout << endl;

    for(int i=0; i<nodos; i++)
    {
        cout << " Ingrese el Dato  " << i+1 << ": ";
        cin >> dtos;
        insertar( arbol, dtos);
    }
	cout<<endl;
    cout << " Datos en PreOrden  :  ";  preOrden(arbol);

    cout << endl;

 
    return 0;
}

Arbl crearNodo(int dtos)
{
     Arbl nuevoNodo = new(struct Nodo);
     nuevoNodo->dato = dtos;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}

void insertar(Arbl &arbol, int dtos)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(dtos);
     }
     else if(dtos < arbol->dato)
          insertar(arbol->izq, dtos);
     else if(dtos > arbol->dato)
          insertar(arbol->der, dtos);
}

void preOrden(Arbl arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->dato <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

