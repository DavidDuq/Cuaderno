## CLASE 3 : **Matriz Punteros**
___
___

* > ¿Qué es una matriz?

Una matriz es un vector de vectores o un también llamado array bidimensional. La manera de declarar una matriz es C++ es similar a un vector: 
____

```c++ 
int matrix [rows][cols];
```
_____
Las matrices también pueden ser de distintos tipos de datos como char, float, double, etc. Las matrices en C++ se almacenan al igual que los vectores en posiciones consecutivas de memoria.

Usualmente uno se hace la idea que una matriz es como un tablero, pero internamente el manejo es como su definición lo indica, un vector de vectores, es decir, los vectores están uno detrás del otro juntos.

## **Punteros**
_____

El valor de todas las variales que manejamos en nuestros programas se almacenan en memoria y tienen una dirección. Un puntero es una variable especial que apunta a la dirección de memoria de una variable.

 > Un puntero se debe declarar de acuerdo al tipo de dato al que apunta. Ejem:
____
```c++ 
int *var; // puntero que puede apuntar a cualquier varuable de tipo entero.

char *u;// puntero de tipo char

Persona *per; // puntero de tipo persona
```
----

## **Matrices y Punteros** 
___

Supongamos que declaro una matriz **(int m[5][5])** Como dijimos anteriormente, el nombre o identificador de un vector es un puntero al primer elemento del vector.

En el caso de matrices el nombre de la matriz, en este ejemplo v, es un puntero que apunta al primer elemento del primer vector de la matriz.

Entonces m es un doble puntero.m es igual a **&m[0]** que es igual a la direccion de **&m[0]****[0]**.

Si declaramos un puntero int *pm y luego igualamos pm = m, p ahora puede desplazarse por los valores de m. *p;  // contenido de m[0], el cual apunta al primer elemento de ese vector, es decir, m[0][0]

* > ## Ejemplo realizado en clases:

```c++ 
#include <iostream>
using namespace std;

void showVector(int v[], int c){ //para vectores
    for (int i = 0; i < c; i++)
        cout<<v[i]<<"\t"; 
    cout<<endl;
} 
void showPtrVector(int *pv, int c){ //para vectores usando puntero
    for (int i = 0; i < c; i++)
        cout<<pv[i]<<"\t"; 
    cout<<endl;
}
void showMatriz(int m[][3], int f, int c){ //para matriz
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
            cout<< m[i][j] <<"\t"; 
        cout<< endl;
    }
} 
void showMatrizComoVector(int mv[], int f, int c){ //para matriz
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
            cout<< mv[i*c+j] <<"\t";    // m[i][j]
        cout<< endl;
    }
} 
void showPtrMatriz(int *p, int f,int c)
{
   for (int i = 0; i < f; i++)
   {
        for (int j = 0; j < c; j++)
            cout<< *(p+i * c+j) <<"\t";   // m[i][j]
        cout<< endl;
   }
}
void showVectorPtrMatriz(int *vp[], int f,int c)
{
   for (int i = 0; i < f; i++)
   {
        for (int j = 0; j < c; j++)
            cout<< vp[i][j] <<"\t";   // m[i][j]
        cout<< endl;
   }
}
void showPtrDobleMatriz(int **pd, int f,int c)
{
   for (int i = 0; i < f; i++)
   {
        for (int j = 0; j < c; j++)
            cout<< pd[i][j] <<"\t";   
        cout<< endl;
   }
}

/// Mas opciones para matrices
void getMatriz(int **matriz)
{
    int fil = 3; //(sizeof(matriz)/sizeof(matriz[0]));
    int col = 2; //(sizeof(matriz[0])/sizeof(matriz[0][0]));
    
    cout<<"----"<<endl;
    cout<<(sizeof(**matriz))<<endl;
    cout<<(sizeof(&matriz)/sizeof(&matriz[0]))<<endl;
    cout<<(sizeof(*matriz[0])/sizeof(matriz[0][0]))<<endl;
    cout<<"----"<<endl;

    for (int i=0; i<fil; i++)
    {
        for(int j=0;j<col; j++)
            cout<<matriz[i][j]<<" ";
        cout <<endl;
    }
}
void setMatriz(int **&matriz, int fil, int col)
{
    for (int i=0; i<fil; i++)
        for(int j=0;j<col; j++)
                matriz[i][j]=0;
}
void showArrayVector(){
    int ai[]={1,3,5,7,9};
    int *pi;
    pi = ai;
    *(pi+0) = 10;   // cambiar valor
    showPtrVector(pi,5);
}

int main(void)
{   //Todo lo que debes saber de las matrices y punteros
    cout<<endl<<endl<<"Iniciando con vectores y punteros"<<endl;
    showArrayVector();

    const int f=4, c=3;
    int m[f][c] = { {1,2,3},    {4,5,6},   {7,8,9},    {10,11,12}};

    cout<<endl<<endl<<"0. showVector(int a[], int c)"<<endl;
    showVector(m[0] , c) ;      // m[1] : 0 es fila que deseas mostrar
    showVector(m[1] , c) ;      // m[1] : 1 es fila que deseas mostrar

    cout<<endl<<endl<<"1. showMatriz: (int m[][3], int f, int c)"<<endl;
    showMatriz(m ,f, c) ;
    
    cout<<endl<<endl<<"2. showMatrizComoVector: (int mv[], int f, int c)"<<endl;
    showMatrizComoVector(&m[0][0] ,f, c);
    
    cout<<endl<<endl<<"3. showPtrMatriz: (int *p, int f,int c)"<<endl;
    showPtrMatriz(&m[0][0] ,f, c);

    /// array de punteros a las ref de nemoria de las filas de la matriz m 
    int *p[f]; 
    for (int i = 0; i < f; i++)
        p[i] = &m[i][0];

    cout<<endl<<endl<<"4. showVectorPtrMatriz: (int *vp[], int f,int c)"<<endl;
    showVectorPtrMatriz(p,f,c);

    //puntero doble
    int **pd = p;
    cout<<endl<<endl<<"5. showPtrDobleMatriz: (int **pd, int f,int c)"<<endl;
    showPtrDobleMatriz(pd,f,c);

    cout<<endl<<endl<<"6. matriz -> showPtrVector: (int *pv, int c)"<<endl;
    for (int i = 0; i < f; i++) {
        showPtrVector(*pd++, c);

        //int *e = *ptr++;
        //cout << *(e + 0) << endl;     //cout << e[0] << endl;
        //cout << *(e + 1) << endl;     //cout << e[1] << endl;
        //cout << *(e + 2) << endl;     //cout << e[2] << endl;
    }
    
    cout<<endl<<endl<<"7. matriz -> showVector(int a[], int c)"<<endl;
    for (int i = 0; i < f; i++)
        showVector(m[i] , c) ; 

    /* OJO-NOTA:
    int (*arreglo) [n]; //Un puntero a un vector de n enteros.
    int *arreglo[n];    //Un vector de n punteros a enteros
    */

    return 0;
}