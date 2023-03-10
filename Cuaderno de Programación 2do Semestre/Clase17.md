## CLASE 16 : **Pilas**
___
___

Las pilas se caracterizan por ser estructuras *last-in-first-out (LIFO)*. Esto significa que funcionan como un montón de cartas donde no solo levantarás siempre la carta que está arriba del todo del montón, pero también colocarás siempre las cartas arriba del todo del montón.

Para usar pilas en C++, habrá que importar el módulo <stack> a nuestro programa. Para crear una pila, como cualquier otro objeto en C++, será necesario darle nombre. Siempre que creemos una pila estaremos creando una pila vacía. Podemos hacerlo de la siguiente manera:
___
```c++
stack<int> pila;
```
____
En este ejemplo, la pila únicamente podrá guardar valores de tipo int. Las pilas podrán guardar objetos de una única clase, ya sea una creada por el usuario o una estándar, como en este ejemplo.

Las pilas tienen una serie de operaciones que se pueden realizar con ellas:

Insertar elementos: para insertar un elemento en la parte de arriba de la pila, podemos usar la función push().

Eliminar elementos: para quitar el elemento de arriba del todo de la pila, podemos usar la función pop().

Ver cuál es el elemento de arriba del todo de la pila: para ver cuál es este elemento, podemos usar la función top(). 

Esto es muy útil, ya que pop() únicamente quitará el primer elemento de la pila, pero no nos dirá cuál es. Esta es una diferencia fundamental entre C++ y otros lenguajes, así que los que vengáis de otros lenguajes tenéis que acordaros de esto, que tiende a ser un bug muy común.

Ver cuántos elementos tiene la pila: para saber esto, podemos utilizar la función size(). Además, podremos saber si la pila está vacía con la función empty().

Todas estas operaciones tienen complejidad O(1), es decir, que el ordenador tardará lo mismo en realizarlas con independencia de cómo de larga sea la pila en el momento de la operación.

## Ejemplo.-
____
```c++ 

#include <iostream>
using namespace std;
 
struct nodo{
    int nro;
    struct nodo *sgte;
};
 
typedef nodo *ptrPila;   // creando nodo tipo puntero( tipo de valor )
//struct nodo1 ptrPila1;   

void push( ptrPila &p, int valor )      // Apilar
{
     ptrPila aux = new(struct nodo);  // apuntamos al nuevo nodo creado
     aux->nro = valor;
     
     aux->sgte = p ;
     p = aux ;
     cout <<" << apilado >> " <<endl;
}
 
void pop( ptrPila &p )   // Desapilar
{
     ptrPila aux;
     
     aux = p ;
     //num = aux->nro;   // asignamos el primer vamor de la pila
     cout <<" << desapilado >> " << aux->nro <<endl;
     
     p = aux->sgte ;
     delete(aux);
}
 
void mostrar_pila( ptrPila p )
{
     ptrPila aux;
     aux = p;     // apunta al inicio de la lista
     
     while( aux !=NULL )
     {
        cout<<"\t"<< aux->nro <<endl;
        aux = aux->sgte;
     }    
}
 
void destruir_pila( ptrPila &p)
{
     ptrPila aux;
     
     while( p != NULL)
     {
           aux = p;
           p = aux->sgte;
           cout<<"despachando: "<< aux->nro <<"\t";
           delete(aux);
     }
     cout<<"\n\n\t\t Pila despachada...\n\n";
}
 
int menu()
{
    int op;
    cout<<endl;
    cout<<" 1. APILAR                                "<<endl;
    cout<<" 2. DESAPILAR                             "<<endl;
    cout<<" 3. ELIMINAR PILA                         "<<endl;
    cout<<" 4. SALIR                                 "<<endl;
    cout<<"\n INGRESE OPCION: ";
    cin>> op;
    if (op==4)  exit(0);
    return op;
}
 
int main()
{
    ptrPila p = NULL;  // creando pila
    int valor;
    int op;
   
    do
    {
        cout<<"\n\n    FUNCIONALIDAD PILA : \n";
        if(p==NULL)
            cout<<"\t << vacia >> ";
        else
            mostrar_pila( p );
        switch(menu())
        {
            case 1: cout<< "\n NUMERO A APILAR: "; cin>> valor;
                    push( p, valor );
                    break;
            case 2: pop( p );
                    break;
            case 3: destruir_pila( p );
                    break;
         }
    }while(op!=5);
    return 0;
}


//  push            1   5
//  pop             2   6
//  mostrar_pila    3   7
//  destruir_pila   4   8
```
____
