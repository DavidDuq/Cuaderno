## CLASE 15 : **Listas Circular**
___
___

Una lista circular es una lista lineal en la que el último nodo a punta al primero.

Las listas circulares evitan excepciones en la operaciones que se realicen sobre ellas. No existen casos especiales, cada nodo siempre tiene uno anterior y uno siguiente.

En algunas listas circulares se añade un nodo especial de cabecera, de ese modo se evita la única excepción posible, la de que la lista esté vacía.

El nodo típico es el mismo que para construir listas 
abiertas:
_____
```c++ 
struct nodo {
   int dato;
   struct nodo *siguiente;
};
```
____

Declaraciones de tipos para manejar listas circulares en C
Los tipos que definiremos normalmente para manejar listas cerradas son los mismos que para para manejar listas abiertas:

_____
```c++ 
typedef struct _nodo {
   int dato;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;
```
____

* > tipoNodo es el tipo para declarar nodos, evidentemente.

* > pNodo es el tipo para declarar punteros a un nodo.

Lista es el tipo para declarar listas, tanto abiertas como circulares. En el caso de las circulares, apuntará a un nodo cualquiera de la lista.

## Ejemplo de lista circular en C
____
Construiremos una lista cerrada para almacenar números enteros. Haremos pruebas insertando varios valores, buscándolos y eliminándolos alternativamente para comprobar el resultado.

Algoritmo de la función "Insertar"
Si lista está vacía hacemos que lista apunte a nodo.
Si lista no está vacía, hacemos que nodo->siguiente apunte a lista->siguiente.
Después que lista->siguiente apunte a nodo.

_____
```c++ 
void Insertar(Lista *lista, int v) {
   pNodo nodo;

   // Creamos un nodo para el nuvo valor a insertar
   nodo = (pNodo)malloc(sizeof(tipoNodo));
   nodo->valor = v;

   // Si la lista está vacía, la lista será el nuevo nodo
   // Si no lo está, insertamos el nuevo nodo a continuación del apuntado
   // por lista
   if(*lista == NULL) *lista = nodo;
   else nodo->siguiente = (*lista)->siguiente;
   // En cualquier caso, cerramos la lista circular
   (*lista)->siguiente = nodo;
}
Algoritmo de la función "Borrar"
¿Tiene la lista un único nodo?
SI:
Borrar el nodo lista.
Hacer lista = NULL.
NO:
Hacemos lista->siguiente = nodo->siguiente.
Borramos nodo.
void Borrar(Lista *lista, int v) {
   pNodo nodo;

   nodo = *lista;

   // Hacer que lista apunte al nodo anterior al de valor v
   do {
      if((*lista)->siguiente->valor != v) *lista = (*lista)->siguiente;
   } while((*lista)->siguiente->valor != v && *lista != nodo);
   // Si existe un nodo con el valor v:
   if((*lista)->siguiente->valor == v) {
      // Y si la lista sólo tiene un nodo
      if(*lista == (*lista)->siguiente) {
         // Borrar toda la lista
         free(*lista);
         *lista = NULL;
      }
      else {
         // Si la lista tiene más de un nodo, borrar el nodo de valor v
         nodo = (*lista)->siguiente;
         (*lista)->siguiente = nodo->siguiente;
         free(nodo);
      }
   }
}
Código del ejemplo completo
Tan sólo nos queda escribir una pequeña prueba para verificar el funcionamiento:

#include <stdio.h>

typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

// Funciones con listas:
void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);
void BorrarLista(Lista *);
void MostrarLista(Lista l);

int main() {
   Lista lista = NULL;
   pNodo p;

   Insertar(&lista, 10);
   Insertar(&lista, 40);
   Insertar(&lista, 30);
   Insertar(&lista, 20);
   Insertar(&lista, 50);

   MostrarLista(lista);

   Borrar(&lista, 30);
   Borrar(&lista, 50);

   MostrarLista(lista);

   BorrarLista(&lista);
   return 0;
}

void Insertar(Lista *lista, int v) {
   pNodo nodo;

   // Creamos un nodo para el nuvo valor a insertar
   nodo = (pNodo)malloc(sizeof(tipoNodo));
   nodo->valor = v;

   // Si la lista está vacía, la lista será el nuevo nodo
   // Si no lo está, insertamos el nuevo nodo a continuación del apuntado
   // por lista
   if(*lista == NULL) *lista = nodo;
   else nodo->siguiente = (*lista)->siguiente;
   // En cualquier caso, cerramos la lista circular
   (*lista)->siguiente = nodo;
}

void Borrar(Lista *lista, int v) {
   pNodo nodo;

   nodo = *lista;

   // Hacer que lista apunte al nodo anterior al de valor v
   do {
      if((*lista)->siguiente->valor != v) *lista = (*lista)->siguiente;
   } while((*lista)->siguiente->valor != v && *lista != nodo);
   // Si existe un nodo con el valor v:
   if((*lista)->siguiente->valor == v) {
      // Y si la lista sólo tiene un nodo
      if(*lista == (*lista)->siguiente) {
         // Borrar toda la lista
         free(*lista);
         *lista = NULL;
      }
      else {
         // Si la lista tiene más de un nodo, borrar el nodo  de valor v
         nodo = (*lista)->siguiente;
         (*lista)->siguiente = nodo->siguiente;
         free(nodo);
      }
   }
}

void BorrarLista(Lista *lista) {
   pNodo nodo;

   // Mientras la lista tenga más de un nodo
   while((*lista)->siguiente != *lista) {
      // Borrar el nodo siguiente al apuntado por lista
      nodo = (*lista)->siguiente;
      (*lista)->siguiente = nodo->siguiente;
      free(nodo);
   }
   // Y borrar el último nodo
   free(*lista);
   *lista = NULL;
}

void MostrarLista(Lista lista) {
   pNodo nodo = lista;

   do {
      printf("%d -> ", nodo->valor);
      nodo = nodo->siguiente;
   } while(nodo != lista);
   printf("\n");
}
```
____

## Ejemplo en clase.-
___
_____
```c++ 
/ Unir 2 listas circulares simples:  lista L1 con L2 y muestra la L1 que es la final

#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
       int nro;        // en este caso es un numero entero
       struct nodo *sgte;
};

typedef struct nodo *TlistaC;

TlistaC lista1, lista2,  fin1, fin2;

void mostrarListas()
{
     TlistaC aux;
     aux = lista1;
     
     if(lista1!=NULL)
     {
          cout<<"\n\n Lista 1 :\n\n";           
          do
          {
               cout<<"  "<<aux->nro;
               aux = aux->sgte;
          }while(aux!=lista1);          
     }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;
     
     aux = lista2;    
     if(lista2!=NULL)
     {
          cout<<"\n\n Lista 2 :\n\n";           
          do
          {
               cout<<"  "<<aux->nro;
               aux = aux->sgte;
          }while(aux!=lista2);          
     }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;     
}

void insertar(TlistaC &lista, TlistaC &fin, int valor)
{
     TlistaC q;
     q = new(struct nodo);
     q->nro = valor;
     
     
     if(lista==NULL)
     {
          lista = q;
          lista->sgte = lista;
          fin = q ;          
     }
     else
     {
          fin->sgte = q;
          q->sgte = lista;
          fin = q;
     }
}

void ingresarListas()
{
     int tam1, tam2, dato;
     
     cout<<"\n Tamanio de lista 1 : "; cin>> tam1;
     cout<<endl;
     
     for(int i=0; i<tam1; i++)
     {
          cout<<"\tElemento "<<i+1<<": ";   cin>> dato;
          insertar(lista1, fin1, dato);  
     }
     
     cout<<"\n Tamanio de lista 2 : "; cin>> tam2;
     cout<<endl;
     
     for(int i=0; i<tam2; i++)
     {
          cout<<"\tElemento "<<i+1<<": ";   cin>> dato;
          insertar(lista2, fin2, dato);  
     }
}

void unirListas()
{
     fin1->sgte = lista2;
     fin2->sgte = lista1;
     
     cout<<"\n\n\tListas circulares L1 y L2 unidas..."<<endl;
}

void mostrarLista1()
{
     TlistaC aux;
     aux = lista1;
     
     if(lista1!=NULL)
     {
          cout<<"\n\n Lista 1 :\n\n";           
          do
          {
               cout<<"  "<<aux->nro;
               aux = aux->sgte;
          }while(aux!=lista1);          
     }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;
}
void menu()
{
    cout<<"\n\t\tUNIR LISTAS CIRCULARES\n\n";
    cout<<" 1. INGRESAR LISTAS                  "<<endl;
    cout<<" 2. MOSTRAR LISTAS                   "<<endl;
    cout<<" 3. UNIR LISTAS                      "<<endl;
    cout<<" 4. MOSTRAR LISTA 1                  "<<endl;
    cout<<" 5. SALIR                            "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

/*                        Funcion Principal
---------------------------------------------------------------------*/
int main()
{
    TlistaC lista = NULL;
    int op;     // opcion del menu
    
    TlistaC lista1 = lista2 = NULL;
    do
    {
        menu();  cin>> op;
        switch(op)
        {
            case 1:
                 ingresarListas( );
            break;
            
            case 2:
                 mostrarListas();
            break;
            
            case 3:
                 unirListas();
            break;
            
            case 4:
                 mostrarLista1();
            break;
                 
        }
        cout<<endl<<endl;
    }while(op!=5);
   return 0;
}
```
___