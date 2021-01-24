#ifndef EMISORDATOS_H
#define EMISORDATOS_H
#include <bits/stdc++.h>
#include "AutomataFinito.h"
using namespace std;
class EmisorDatos
{
private:

public:
    EmisorDatos(/* args */);
    ~EmisorDatos();
    void guardarEn(vector<int> estadosIniciales, string alfabeto, vector<int> estadosFinales);
};

EmisorDatos::EmisorDatos(/* args */)
{
}

EmisorDatos::~EmisorDatos()
{
}
void EmisorDatos::guardarEn(vector<int> estadosIniciales, string alfabeto, vector<int> estadosFinales)
{
    ofstream archivo;
    archivo.open("salida.af", ios::out);
    if (archivo.fail())
    {
        cout << "El archivo no se pudo crear..." << endl;
        exit(1);
    }
    else
    {
        system("CLS");
        cout << "\n\n\n\n\n\n\n\n\t\t\t-------------------------------------------\n";
        cout << "\t\t\t|Los datos se han guardado en salida.af :)|\n";
        cout << "\t\t\t-------------------------------------------\n\n\n\n\n\n\n\n";
        archivo << "\n\t\tPractica 3: AFN a AFD, construccion de subconjuntos" << endl;
        for (int i = 0; i < estadosIniciales.size(); i++)
        {
            archivo<<estadosIniciales[i]<<","<<alfabeto[i]<<"->"<<estadosFinales[i]<<endl;
        }
         
    }
    archivo.close();
}

#endif