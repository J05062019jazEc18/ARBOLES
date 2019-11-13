#include <iostream>
#include <cstdlib>
using namespace std;

struct Nodo{
     int dato;
     struct Nodo *izq, *der;
};

typedef struct Nodo *Arbl;

void insertar(Arbl &arbol, int dtos);
Arbl crearNodo(int dtos);
void enOrden(Arbl arbol);

int main()
{
    Arbl arbol = NULL;   

    int nodos;  
    int dtos; 

    cout << "   ARBOL EN ORDEN"; 
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
  	cout << "Datos EnOrden   :  ";   enOrden(arbol);

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


void enOrden(Arbl arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->dato << " ";
          enOrden(arbol->der);
     }
}


  
  
