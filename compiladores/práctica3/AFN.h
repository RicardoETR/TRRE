#ifndef AFN_H
#define AFN_H
#include"AutomataFinito.h"
#include <bits/stdc++.h>
using namespace std;
class AFN : public AutomataFinito 
{
private:
    //Atributos para construcción de subconjuntos
    vector<vector<int>> Destados;
    vector<int> auxDestados;
    int countAuxDestados = 0;
    int countDestados = 0;
    int vueltasECT = 0;
    int vueltasmover = 0;
    int countAlfabeto = 0;
    vector<int> agregarInicial;
    //para pasarselos al nuevo AFD
    vector<int> transicionesEstadoInicialAFNAFD;
    vector<int> transicionesEstadoFinalAFNAFD;
    string transicionesAlfabetoAFNAFD;
public:
    AFN();
    ~AFN();
    void contruirSubconjuntos();
    void eCerraduraS(vector<int>);
    void eCerraduraT(vector<int>);
    void mover(vector<int>);
    void clean();
    void agregar(vector<int>);
    //getters para afn a afd
    vector<int> getTransicionesEstadoInicalAFNAFD();
    vector<int> getTransicionesEstadoFinalAFNAFD();
    string getTransicionesAlfabetoAFNAFD();
};

AFN::AFN()
{
}

AFN::~AFN()
{
}
//Construccion de Subconjuntos
void AFN::contruirSubconjuntos()
{
    bool salir = false;
    //E-cerradutra(s)
    auxDestados.push_back(atoi(estadoInicial.c_str()));
    vueltasECT = auxDestados.size();
    eCerraduraS(auxDestados);
    while (salir == false)
    {
        auxDestados = Destados[countDestados];
        if (alfabeto[countAlfabeto] != 'E')
        {
            mover(auxDestados);
        }
        countAlfabeto++;
        if (countAlfabeto == alfabeto.size())
        {
            countAlfabeto = 0;
            countDestados++;
        }
        if (countDestados == Destados.size())
        {
            salir = true;
        }
    }
}
void AFN::eCerraduraS(vector<int> _auxDestados)
{
    bool banderaAgregar = true;
    for (int i = 0; i < transicionesEstadoIncial.size(); i++)
    {

        if (transicionesEstadoIncial[i] == _auxDestados[countAuxDestados] && transicionesAlfabeto[i] == 'E')
        {
            for (int j = 0; j < auxDestados.size(); j++)
            {
                if (transicionesEstadoFinal[i] == auxDestados[j])
                    banderaAgregar = false;
            }
            if (banderaAgregar == true)
                auxDestados.push_back(transicionesEstadoFinal[i]);
            banderaAgregar = true;
            vueltasECT++;
        }
    }
    if (vueltasECT > 0)
    {
        vueltasECT--;
        countAuxDestados++;
        eCerraduraS(auxDestados);
    }
    else
    {
        sort(auxDestados.begin(), auxDestados.end());
        agregar(auxDestados);
        clean();
    }
}
void AFN::eCerraduraT(vector<int> _auxDestados)
{
    if (_auxDestados.size() == 0)
        return;
    bool banderaAgregar = true;
    for (int i = 0; i < transicionesEstadoIncial.size(); i++)
    {

        if (transicionesEstadoIncial[i] == _auxDestados[countAuxDestados] && transicionesAlfabeto[i] == 'E')
        {
            for (int j = 0; j < auxDestados.size(); j++)
            {
                if (transicionesEstadoFinal[i] == auxDestados[j])
                    banderaAgregar = false;
            }
            if (banderaAgregar == true)
                auxDestados.push_back(transicionesEstadoFinal[i]);
            banderaAgregar = true;
            vueltasECT++;
        }
    }
    if (vueltasECT > 0)
    {
        vueltasECT--;
        countAuxDestados++;
        eCerraduraT(auxDestados);
    }
    else
    {
        sort(auxDestados.begin(), auxDestados.end());
        agregar(auxDestados);
        clean();
    }
}
void AFN::mover(vector<int> _auxDestados)
{
    agregarInicial.clear();
    vector<int> auxMover = _auxDestados;
    agregarInicial = auxMover;
    auxDestados.clear();
    for (int i = 0; i < auxMover.size(); i++)
    {
        for (int j = 0; j < transicionesEstadoIncial.size(); j++)
        {
            if (auxMover[i] == transicionesEstadoIncial[j] && transicionesAlfabeto[j] == alfabeto[countAlfabeto] && alfabeto[countAlfabeto] != 'E')
            {
                auxDestados.push_back(transicionesEstadoFinal[j]);
            }
        }
    }
    vueltasECT = auxDestados.size();
    eCerraduraT(auxDestados);
}
void AFN::agregar(vector<int> _auxDestados)
{
    char auxLetra;
    bool bandera = true;
    int comparar = 0;
    if (Destados.size() == 0)
    {
        Destados.push_back(_auxDestados);
    }
    else
    {
        for (int i = 0; i < Destados.size(); i++)
        {
            if (Destados[i].size() == _auxDestados.size())
            {
                for (int j = 0; j < _auxDestados.size(); j++)
                {

                    if (Destados[i][j] == _auxDestados[j])
                        comparar++;
                }
                if (comparar == _auxDestados.size())
                    bandera = false;
                comparar = 0;
            }
        }
        if (bandera == true)
        {
            Destados.push_back(_auxDestados);
        }
        bandera = true;
        for (int i = 0; i < Destados.size(); i++)
        {
            if (Destados[i].size() == _auxDestados.size())
            {
                for (int j = 0; j < _auxDestados.size(); j++)
                {

                    if (Destados[i][j] == _auxDestados[j])
                        comparar++;
                }
                if (comparar == _auxDestados.size())
                {
                    auxLetra=alfabeto[countAlfabeto];
                    transicionesAlfabetoAFNAFD.push_back(auxLetra);
                    transicionesEstadoFinalAFNAFD.push_back(i+1);
                }     
                comparar = 0;
            }
            if (Destados[i].size() == agregarInicial.size())
            {
                for (int j = 0; j < agregarInicial.size(); j++)
                {

                    if (Destados[i][j] == agregarInicial[j])
                        comparar++;
                }
                if (comparar == agregarInicial.size())
                {
                    transicionesEstadoInicialAFNAFD.push_back(i+1);
                }     
                comparar = 0;
            }
            
        }
        
    }
}
void AFN::clean()
{
    vueltasECT = 0;
    countAuxDestados = 0;
}
//getters para afn a afd
vector<int> AFN::getTransicionesEstadoInicalAFNAFD(){
    return transicionesEstadoInicialAFNAFD;
}
vector<int> AFN::getTransicionesEstadoFinalAFNAFD(){
    return transicionesEstadoFinalAFNAFD;
}
string AFN::getTransicionesAlfabetoAFNAFD(){
    return transicionesAlfabetoAFNAFD;
}
#endif
