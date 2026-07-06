#ifndef PLOTGRAFOS_HPP
#define PLOTGRAFOS_HPP

#include "Grafo.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

namespace PlotGrafos {
    void exportarGrafoDOT(const string& nomeArquivo, const vector<vector<pair<int, int>>>& listaAdjacencia);
    void exportarSolucaoCarteiro(const string& nomeArquivo, const vector<int>& caminho_carteiro);
}

#endif