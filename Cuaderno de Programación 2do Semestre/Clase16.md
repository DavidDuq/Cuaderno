## CLASE 16 : **Colas**
___
___

Las colas se caracterizan por ser estructuras *first-in-first-out (FIFO)*. Esto significa que funcionan como una cola de personas en una panadería: la primera persona en llegar a la panadería será la primera en ser atendida y así sucesivamente hasta vaciar la cola.

Para usar colas en  *C++*, habrá que importar el módulo <queue> a nuestro programa. Para crear una cola, como cualquier otro objeto en C++, será necesario darle nombre. Siempre que creemos una cola estaremos creando una cola vacía. Podemos hacerlo de la siguiente manera:
___
```c++
queue<int> cola;
```
___

En este ejemplo, la cola únicamente podrá guardar valores de tipo int. Las colas podrán guardar objetos de una única clase, ya sea una creada por el usuario o una estándar, como en este ejemplo.

Las colas tienen una serie de operaciones que se pueden realizar con ellas:

Insertar elementos: para insertar un elemento al final de la cola, podemos usar la función push().

Eliminar elementos: para quitar el elemento del principio de la cola, podemos usar la función pop().

Ver cuál es el primer elemento de la cola: para ver cuál es este elemento, podemos usar la función front(). 

Esto es muy útil, ya que pop() únicamente quitará el primer elemento de la cola, pero no nos dirá cuál es. Esta es una diferencia fundamental entre C++ y otros lenguajes, así que los que vengáis de otros lenguajes tenéis que acordaros de esto, que tiende a ser un bug muy común.

Ver cuál es el último elemento de la cola: hay un equivalente de la función front() para el final de la cola, la función back().

Ver cuántos elementos tiene la cola: para saber esto, podemos utilizar la función size(). Además, podremos saber si la cola está vacía con la función empty().

Todas estas operaciones tienen complejidad O(1), es decir, que el ordenador tardará lo mismo en realizarlas con independencia de cómo de larga sea la cola en el momento de la operación.

## Ejemplo.-

```c++ 

#include <iostream>
using namespace std;
 
struct nodo              //  [ # ]>-->
{
    int nro;
    struct nodo *sgte;
};
 
struct cola             //  <--< >-->   
{
    nodo *delante;
    nodo *atras  ;
};
 
 
void encolar( struct cola &q, int valor )
{
     struct nodo *aux = new(struct nodo);
     
     aux->nro = valor;
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   // encola el primero elemento
     else
         (q.atras)->sgte = aux;
     q.atras = aux;        // puntero que siempre apunta al ultimo elemento
}
 
int desencolar( struct cola &q )
{
     int num ;
     struct nodo *aux ;
     
     aux = q.delante;      // aux apunta al inicio de la cola
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);          // libera memoria a donde apuntaba aux
     
     return num;
}
 
void muestraCola( struct cola q )
{
     struct nodo *aux;
     aux = q.delante;
         
     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }    
}
 
void vaciaCola( struct cola &q)
{
     struct nodo *aux;
     
     while( q.delante != NULL)
     {
            aux = q.delante;
            q.delante = aux->sgte;
            delete(aux);
     }
     q.delante = NULL;
     q.atras   = NULL;
}
 
int menu()
{
    int op=0;
    system("cls");
    cout<< endl <<"[...] COLAS          "
        << endl <<"  0.  SALIR          "
        << endl <<"  1.  ENCOLAR        "
        << endl <<"  2.  DESENCOLAR     "
        << endl <<"  3.  MOSTRAR COLA   "
        << endl <<"  4.  VACIAR COLA    "
        << endl <<"  5.  SALIR          "
        << endl <<"\n INGRESE OPCION:   ";
    cin>> op;
    return op;
}
 
int main()
{
    struct cola q;
    q.delante = NULL;
    q.atras   = NULL;
   
    int dato;  // numero a encolar
    int x ;    // numero que devuelve la funcon pop
   
    system("color 0b");
    do
    {
        switch( menu() )
        {
            case 0: exit(0); 
            case 1:
                    cout<< "\n NUMERO A ENCOLAR: "; cin>> dato;
                    encolar( q, dato );
                    cout<<"\n\n\t\tNumero " << dato << " encolado...\n\n";
                    break;
            case 2:
                    x = desencolar( q );
                    cout<<"\n\n\t\tNumero "<< x <<" desencolado...\n\n";
                    break;
            case 3:
                    cout << "\n\n MOSTRANDO COLA\n\n";
                    if(q.delante!=NULL) muestraCola( q );
                    else   cout<<"\n\n\tCola vacia...!"<<endl;
                    break;
            case 4:
                    vaciaCola( q );
                    cout<<"\n\n\t\tHecho...\n\n";
                    break;
         }
        cout<<endl<<endl;
        system("pause");  
    }while(true);
    return 0;
}

```
____
