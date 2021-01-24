//Autor: Ricardo Erick Torres Rosas.
#include <bits/stdc++.h>
#include "AutomataFinito.h"
#include "AFD.h"
#include "AFN.h"
using namespace std;
int main(int argc, char *argv[])
{
    string auxInput;
    //Recibir producciones por un archivo txt
    string ubicacionEntrada;
    if (argc != 2)
    {
        cout << "Formato: nombreEjecutable nombre.af" << endl;
        exit(0);
    }
    ubicacionEntrada = argv[1];
    AFN *objAFN = new AFN();
    AFD *objAFD = new AFD();
    objAFN->archivo.cargarDesde(ubicacionEntrada);
    objAFN->llenadoDeAutomataFinito();
    objAFN->establecerTrancisiones();
    objAFN->contruirSubconjuntos();
    objAFD->setTransicionesAFNAFD(objAFN->getTransicionesEstadoInicalAFNAFD(), objAFN->getTransicionesAlfabetoAFNAFD(), objAFN->getTransicionesEstadoFinalAFNAFD());
    objAFD->emisor.guardarEn(objAFD->getTransicionesEstadoInicial(), objAFD->getTransicionesAlfabeto(), objAFD->getTransicionesEstadoFianl());
    return 0;
}