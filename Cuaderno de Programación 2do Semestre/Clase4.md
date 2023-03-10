## CLASE 4 : **Memoria Punteros**
___
___

Un puntero es una variable que almacena la dirección de memoria de un objeto. Los punteros se usan ampliamente en C y C++ para tres propósitos principales: para asignar nuevos objetos en el montón, para pasar funciones a otras funciones.

El espacio de memoria reservado para almacenar un puntero es el mismo independientemente del tipo de dato al que apunte: el espacio que ocupa una dirección de memoria. A un puntero se le puede asignar una dirección de memoria concreta, la dirección de una variable o el contenido de otro puntero.

En C++ admite la asignación dinámica y la desasignación de objetos mediante los operadores new y delete . Estos operadores asignan memoria para los objetos de un grupo denominado almacén libre (también conocido como montón).

* > ## Ejemplo en Clases

____
```c++ 

#include <iostream>

    using namespace std;

    int **crearMatrizMalloc(int f, int c)
    {  
        int **m=NULL;
        m = (int **) malloc(f*sizeof(int *));
        for (int i = 0; i < f; i++)
            m[i] = (int *) malloc(c*sizeof(int));
        
        return m;
    }
    int **crearMatrizCalloc(int f, int c)
    {
        int **m=NULL;
        m = (int **) calloc(f, sizeof(int *));
        for (int i = 0; i < f; i++)
            m[i] = (int *) calloc(c, sizeof(int));
        
        return m;
    }
    int **crearMatrizNew(int f, int c)
    {   //int i = new int(10);    //heap   --> delete
        //int i = 10;             //stack
        int **m=NULL;
        m = new int*[f];
        for (int i = 0; i < f; i++)
            m[i] = new int[c];

        return m;
    }
    void showMatriz(int **pd, int f,int c)
    {
        for (int i = 0; i < f; i++)
        {
                for (int j = 0; j < c; j++)
                    cout<< pd[i][j] <<"\t";   
                cout<< endl;
        }
    }

    int main()
    {
        int f = 0, c = 0;
        int **pd=NULL;

        cout<<"Ingresa fila y columnas de la matriz : ";
        cin>> f >> c;
    
        pd = crearMatrizNew(f,c);

        for (int i = 0; i < f; i++)
            for (int j = 0; j < c; j++)
                pd[i][j] = rand() % 10;  // genera randomicos hasta 10
        
        showMatriz(pd,f,c);
        return 0;
    }