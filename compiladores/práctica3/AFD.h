#ifndef AFD_H
#define AFD_H
#include "AutomataFinito.h"
#include <bits/stdc++.h>
using namespace std;
class AFD : public AutomataFinito
{
private:
    vector<int> transicionesEstadoInicialAFNAFD;
    vector<int> transicionesEstadoFinalAFNAFD;
    string transicionesAlfabetoAFNAFD;

public:
    AFD();
    ~AFD();
    //getters y setters
    vector<int> getTransicionesEstadoInicial();
    vector<int> getTransicionesEstadoFianl();
    string getTransicionesAlfabeto();
    void setTransicionesAFNAFD(vector<int>, string, vector<int>);
};

AFD::AFD()
{
}

AFD::~AFD()
{
}
//getters y setters
vector<int> AFD::getTransicionesEstadoInicial()
{
    return transicionesEstadoInicialAFNAFD;
}
vector<int> AFD::getTransicionesEstadoFianl()
{
    return transicionesEstadoFinalAFNAFD;
}
string AFD::getTransicionesAlfabeto()
{
    return transicionesAlfabetoAFNAFD;
}
void AFD::setTransicionesAFNAFD(vector<int> transicionesEstadoInicialAFNAFD, string transicionesAlfabetoAFNAFD, vector<int> transicionesEstadoFinalAFNAFD){
    this->transicionesEstadoInicialAFNAFD=transicionesEstadoInicialAFNAFD;
    this->transicionesEstadoFinalAFNAFD=transicionesEstadoFinalAFNAFD;
    this->transicionesAlfabetoAFNAFD=transicionesAlfabetoAFNAFD;
}
#endif