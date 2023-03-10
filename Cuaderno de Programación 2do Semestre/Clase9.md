## CLASE 9 : **Autómata finito deteminista**
___
___

Un autómata es un modelo matemático para una máquina de estado finito (FSM sus siglas en inglés). Una FSM es una máquina que, dada una entrada de símbolos, "salta" a través de una serie de estados de acuerdo a una función de transición (que puede ser expresada como una tabla). En la variedad común "Mealy" de FSMs, esta función de transición dice al autómata a qué estado cambiar dados unos determinados estado y símbolo.

Dependiendo del estado en el que el autómata finaliza se dice que este ha aceptado o rechazado la entrada. Si éste termina en el estado "acepta", el autómata acepta la palabra. Si lo hace en el estado "rechaza", el autómata rechazó la palabra, el conjunto de todas las palabras aceptadas por el autómata constituyen el lenguaje aceptado por el mismo.

* Este autómata nos basamos en la imagen siguiente, la cual muestra el diagrama del autómata con la secuencia de estados, este es un autómata finito determinista, ya no tiene transiciones vacías.

**El programa esta hecho en base al ejemplo tal cual.**

![Suma](aut%C3%B3mata%20.png "Suma de punteros")


* > ## Ejemplo presentado en clases :

____
```c++ 

#include <iostream>
using namespace std;

int const TKErr=-1;         // Token de Error
int const TKFin=-2;         // Token de Fin
string const ALFA = "abc \\t";

int **newMatriz(int f, int c)
{    
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

int getIndexAlfabeto(char c)
{
    int index = ALFA.find(c);
    if(index < ALFA.length())
        return index;
    return TKErr;    
}

int main( void) 
{
    int **mt=NULL;         // mt =  matriz de transicion
    int Q=3, L=4;
    mt = newMatriz(Q,L);
    
/*  Automata finito determinista

    [q0]      --- b  --->   [q2] (c)
     |-- a -->  [q1] -- b -->|
                 (a)

     _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ 
     Q     |  { a           b           c           ' '     \t  }
     _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ 
     0     |    1           2           r           er
     1     |    1           2           r           er
     2     |    er          er          q2          ok1
     _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ 

*/
    //matriz de transicion [Q][L]
    mt[0][0]=1;         mt[0][1]=2;         mt[0][2]= TKErr;     mt[0][3]= TKErr;
    mt[1][0]=1;         mt[1][1]=2;         mt[1][2]= TKErr;     mt[1][3]= TKErr;
    mt[2][0]=TKErr;     mt[2][1]=TKErr;     mt[2][2]= 2;         mt[2][3]= -1000; 

    string palabra = "aaabcc ";
    int q=0, l=0;
    for (auto &&c : palabra )
    {
        l = getIndexAlfabeto(c);
        q = mt[q][l];
        cout<< c << " " << q <<","<< l <<endl;
        if(q == TKErr || q > Q)
            cout<<" -> Error";
        if(q == -1000)
            cout<<" -> OK";
       // 
    }
     
    
    // for (int i = 0; i <Q; i++)
    //     for (int j = 0; j < L; j++)
    //         mt[i][j] =  'a'; //rand() % 10;  // genera randomicos hasta 10
    
    showMatriz(mt,Q,L);
}
``` 
___


