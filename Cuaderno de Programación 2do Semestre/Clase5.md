## CLASE 5 : **Corazón**
___
___

* > Se creo una función llamada corazón con void 
____
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
{
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
