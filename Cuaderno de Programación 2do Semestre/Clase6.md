## CLASE 6 : **Estructura**
___
___

Las estructuras de datos en C++ se pueden entender como un tipo de dato compuesto (no complejo). Las estructuras de datos permiten almacenar de manera ordenada una serie de valores dados en una misma variable. Las estructuras de datos más comunes son los arrays, que pueden ser unidimensionales (de una dimensión) también conocidos como vectores, o multidimensionales (de varias dimensiones) también conocidos como matrices, aunque hay otras un poco más diferentes como son struct, las enumeraciones y los punteros.

* En otras palabras, Un tipo de estructura es un tipo compuesto definido por el usuario. Se compone de campos o de miembros que pueden tener diferentes tipos. En C++, una estructura es igual que una clase salvo que sus miembros son public de forma predeterminada.


* > ## Ejemplo en clases :

____
```c++ 
#include <iostream>
using namespace std;
struct Mascota
{
    string tipo;
    string nombre;
};

struct Alumno
{
    int  id;
    int  edad;
    char nombre[20];
    Mascota mascotita;
};

// struct perro
// {
//     int  id;
//     int  edad;
//     char nombre[20];
// }p1 ={};  lstPerros[3];

// estructuras con estructuras
// struct alumno dueno;
    int main()
    {   Alumno a0;
        Alumno a1 = {1,100,"pepe",{"perro","firulais"}};
        Alumno a2 = {2,20,"luis"};
        Alumno lst[]={a1, a2, {3,100,"luisa",{"gato","firulais"} }};
        a0.edad =10;
        a1.edad =10;
        a1.mascotita.nombre ="firulaiza";
        cout<<endl<<"[+]"
            <<endl<<" - "<<"id:"    <<a1.id
            <<endl<<" - "<<"edad:"  <<a1.edad
            <<endl<<" - "<<"nombre:"<<a1.nombre
            <<endl<<" - "<<"Macota.tipo:"<<a1.mascotita.tipo
            <<endl<<" - "<<"Macota.nombre:"<<a1.mascotita.nombre
            <<endl;
    // for (int i = 0; i < 3; i++)
    //     cout<<endl<<"[+]"
    //         <<endl<<" - "<<"id:"    <<lst[i].id
    //         <<endl<<" - "<<"edad:"  <<lst[i].edad
    //         <<endl<<" - "<<"nombre:"<<lst[i].nombre
    //         <<endl;
    for (auto &&a : lst)
        cout<<endl<<"[+]"
            <<endl<<" - "<<"id:"    <<a.id
            <<endl<<" - "<<"edad:"  <<a.edad
            <<endl<<" - "<<"nombre:"<<a.nombre
            <<endl<<" - "<<"Macota.tipo:"<<a.mascotita.tipo
            <<endl<<" - "<<"Macota.nombre:"<<a.mascotita.nombre
            <<endl;


    Alumno *persona = new Alumno[5];
 
    for (int i=0; i<5; i++)
    {
        cout << "Dime el nombre de la persona " << i << endl;
        cin >> persona[i].nombre;
    }
    cout << "La persona 3 es " << persona[2].nombre << endl;
 
    return 0;
}



