#include "PlotGrafos.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

namespace PlotGrafos {
    // Função para exportar o grafo original
    void exportarGrafoDOT(const string& nomeArquivo, const vector<vector<pair<int, int>>>& listaAdjacencia) {
        ofstream arquivo(nomeArquivo);
        
        if (!arquivo.is_open()) {
            return; // Falha ao abrir o arquivo
        }

        // Usamos digraph porque o carteiro percorre as ruas em um sentido específico no seu trajeto
        arquivo << "graph G {\n";
        // ---- CONFIGURAÇÕES DE HARMONIA VISUAL ----
        arquivo << "    layout=neato;\n";            // Altera o motor de renderização (veja abaixo)
        arquivo << "    overlap=false;\n";           // Impede que nós fiquem uns em cima dos outros
        arquivo << "    splines=false;\n";            // Faz as arestas desviarem dos nós de forma elegante
        arquivo << "    node [shape=circle, style=filled, fillcolor=\"#E43F3F\", fontcolor=white, width=0.4];\n"; 
        arquivo << "    edge [fontsize=9, fontcolor=\"#333333\"];\n"; // Ajusta a fonte dos pesos
        // ------------------------------------------

        // Para evitar duplicar arestas (ex: 0-1 e 1-0), usamos uma matriz de visitados ou a regra i < vizinho
        for (int i = 0; i < listaAdjacencia.size(); ++i) {
            for (const auto& aresta : listaAdjacencia[i]) {
                int vizinho = aresta.first;
                if (i < vizinho) { // Garante que a aresta só seja impressa uma vez
                    int peso = aresta.second;
                    arquivo << "    " << i << " -- " << vizinho 
                        << " [label=\"" << peso << "\"];\n";
                }
            }
        }
        arquivo << "}\n";
        arquivo.close();
    }

    // Função para exportar a solução do Carteiro Chinês
    // O vetor 'caminho_carteiro' contém a sequência de vértices visitados (ex: 0 -> 1 -> 2 -> 1 -> 0)
    void exportarSolucaoCarteiro(const string& nomeArquivo, const vector<int>& caminho_carteiro) {
        ofstream arquivo(nomeArquivo);
        
        // Usamos digraph porque o carteiro percorre as ruas em um sentido específico no seu trajeto
        arquivo << "graph G {\n";
        // ---- CONFIGURAÇÕES DE HARMONIA VISUAL ----
        arquivo << "    layout=fdp;\n";            // Altera o motor de renderização (veja abaixo)
        arquivo << "    overlap=false;\n";           // Impede que nós fiquem uns em cima dos outros
        arquivo << "    splines=true;\n";            // Faz as arestas desviarem dos nós de forma elegante
        arquivo << "    node [shape=circle, style=filled, fillcolor=\"#E43F3F\", fontcolor=white, width=0.6];\n"; 
        arquivo << "    edge [fontsize=11, fontcolor=\"#333333\"];\n"; // Ajusta a fonte dos pesos
        // ------------------------------------------
        // Para evitar poluir o gráfico se ele passar pela mesma rua na mesma direção, 
        // podemos colocar um contador ou apenas desenhar as setas sequenciais.
        for (size_t i = 0; i < caminho_carteiro.size() - 1; ++i) {
            int u = caminho_carteiro[i];
            int v = caminho_carteiro[i+1];
            
            // Coloca o número do passo na aresta (ex: 1º passo, 2º passo...)
            arquivo << "    " << u << " -> " << v << " [label=\" " << i+1 << "º \", penwidth=1.5];\n";
        }
        
        arquivo << "}\n";
        arquivo.close();
        cout << "Arquivo '" << nomeArquivo << "' gerado com sucesso para visualizacao!\n";
    }

}