## CLASE 2 : **ARCHIVOS**
-------
 ____

 * > Definición de Archivos y para que sirven

Los archivos o ficheros son la forma en la que C++ permite el acceso al disco. Todos los procesos tienen abiertos, por defecto, los archivos 
* 0(entrada) 
* 1(salida)  
* 2(salida de errores) 

 De manera que en C++ se corresponden con los objetos cin, cout y cerr. Para trabajar con ficheros en C++ debe incluirse la cabecera fstream . Dependiendo de lo que deseemos hacer con el fichero, usaremos objetos de las clases: ifstream ( input file stream), clase orientada para la lectura. ofstream (output file stream).

 * > ## Ejemplo realizado en clase

```c++
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

void Loading()
{ 
    int ind =0;
    string c= "\\|/-|"; 
    for(int i=0; i<= 100; i++)
    {   
        //updateBar(i);
        if(i % 4 ==0)
            ind =0;
        cout    << "\r" << c[ind++]   
                << " " << i << "%";
        usleep(90000);
    }
}

void LeerArchivo(string pathFile)  //-->  datafiles/ListaAlumnos.txt
{
    string s;
    fstream f;
    f.open(pathFile, ios_base::in);
    if ( !f.is_open() ) 
        cout << "Error de abrir el archivo." << endl;
    else
        do 
        {
            getline( f, s );
            cout << s << endl;
        }while( !f.eof() );
    f.close();
}
void CrearArchivo(string pathFile)  //-->  datafiles/ListaAlumnos.txt
{
    string s;
    fstream f;

    cout << "Escibiendo en un archivo" << endl;
    f.open(pathFile, ios_base::app);

    if (f.is_open())
    {
        // f << "pepe lucho" << endl;
        // f << "ana" << endl;
        do
        {
            cout<< "(N = salir ) Ingresa un nombre: ";
            cin>>s;
            if (s!="N")
                f << s << endl;
        } while (s!="N");
    }
    f.close();
}

int main()
{
    Loading();
    CrearArchivo("datafiles/ListaAlumnos.txt");
    LeerArchivo("datafiles/ListaAlumnos.txt");
    return 0;
}