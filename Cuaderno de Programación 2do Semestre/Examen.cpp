#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <unistd.h>
#include <string>
#include <conio.h>
#include <iomanip>
#include "../lib/color.h"

// https://github.com/DavidDuq/Examen2.git

using namespace std;

// AUTOR : DAVID ALEJANDRRO DUQUE INTRIAGO
// FECHA : 06/03/2023

const int ddcedula = 1753494523;
const string ddnombrecompleto = "David Alejandro Duque Intriago"; 


void ddCoordenadas( string nombreArchivo) 
{
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    cout << "[+]    Coordenadas leidas.....: " << endl;
       cout << COLOR_RED;
    cout << "     ERROR :   cap,   Geo,   Tipo Arcenal -->stoi" << endl;
        cout << COLOR_WHITE;    
    if (archivo.is_open()) 
    {
        while (getline(archivo, linea)) 
        {
            int jq =0;
            string c= "-"; 
            for(int i=0; i<= 100  ; i++)
            {   
                if(i % 4 ==0)
                jq =0;
                    cout  << "\r" << c[jq++]   
                    << "    " << i << "%";
            usleep(9000);
            }
        cout << linea << endl;
        }
        archivo.close();
    }
    else 
    {
        cout << "No se pudo abrir el archivo." <<endl;
   }
}
 


 void ddinformacion()
 {
    cout <<COLOR_BLUE << "\n[+] Informacion Arbol Binario de capacidad belica Ucranica" << endl;
        cout <<"\t Devloper-Nombre :" << ddnombrecompleto <<endl;
        cout <<"\t Devloper-Cedula :" << ddcedula         <<endl;
        cout <<"\t Capacidad Belica:10"                   <<endl;
        cout <<"\t Coordenada total:3"                    <<endl;
        cout <<"\t Coordenada-Secarga: 1, 7, 2"           <<endl;

 }

void ddDatos()
{
    cout << COLOR_LBLUE;
    cout << endl
         << "[+] Informacion Arbol Binario de capacidad belica Ucrania" << endl
         << "\tDeveloper-Nombre:"<< ddnombrecompleto << endl
         << "\tDeveloper-Cedula:" << ddcedula << endl
         << "\tCapacidad Belica: " << endl
         << "\tCoordenada-Total: " << endl
         << "\tCoordenada/SecCarga: 1 7 2 " << endl;
}

// struct ddnodo
// {
//     string ddCoordenadas;
//     ddnodo *izquierda, *derecha;
// };

// void ddinsertar(string ddCoordenadas, ddnodo *&ddArbol)
// {
//     if (ddArbol == NULL)
//     {
//         ddArbol = new ddnodo;
//         ddArbol -> ddCoordenadas = ddCoordenadas;
//         ddArbol -> izquierda = NULL;
//         ddArbol -> derecha = NULL;
//     }
//     else if (ddCoordenadas < ddArbol -> ddCoordenadas)
//     {
//         ddinsertar(ddCoordenadas, ddArbol->izquierda);
//     }
//     else
//     {
//         ddinsertar(ddCoordenadas, ddArbol->derecha);
//     }
// }

// void jqmostrarArbol(ddnodo* ddArbol, int j)
// {
//     if (ddArbol == NULL)
//         return;
//     jqmostrarArbol(ddArbol->derecha, j + 3);
//     for (int i = 0; i < j; i++)
//     {
//         cout << "   ";
//     }
//     cout << ddArbol -> ddCoordenadas << endl;
//     jqmostrarArbol(ddArbol->izquierda, j + 3);
// }


int main()
 {
    string archivo_cordenadas ="data/cordenadas.txt";
    ddCoordenadas(archivo_cordenadas);
    ddinformacion();
    ddDatos();
    // cout << endl;
    // ddnodo *ddArbol = NULL;
    // cout << "TIPO DE BOMBA: a*b+c" << endl;
    // ddInsertar
    // ddmostrarArbol(ddArbol,0);
 }
