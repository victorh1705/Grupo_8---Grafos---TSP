/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tsp.cpp
 * Author: Usuario
 * 
 * Created on 27 de Junho de 2017, 14:36
 */

#include "Tsp.h"

Tsp::Tsp(Grafo* grafo) {
    this->grafo = grafo;
}

Tsp::~Tsp() {
}

void Tsp::funcaoCriterio(double alfa) {

    unsigned int intervaloRandomico = (int) alfa*vetor->getSize();
    
    infoArestaAux = vetor->getMinimalConnectedToSolution();
}

string Tsp::reativoRandomizado(int iteracoes) {

    AuxSS.str(string());
    time_t begin, end;
    double diferenca,
            alfa = 0;

    time(&begin);

    AuxSS << "------------------------------------------------------------\n";
    AuxSS << "-------------- Algoritmo Randomizado Reativo ---------------\n";
    AuxSS << "------------------------------------------------------------\n";

    tempoRandomizadoReaivo.resize(iteracoes);
    srand(time(NULL));
    
    vector<unsigned int> nosSolucao;
    
    for ( int i = 0; i < iteracoes; i++ ) {
        
        time(&begin);
        
        vetor = new VectorEdgeSearch(grafo->getNoRaiz(), grafo);
        infoArestaAux = vetor->getMinimal();
        nosSolucao.resize(grafo->getOrdem());
        
        infoArestaAux->setBoth(true);
        nosSolucao.push_back(infoArestaAux->GetNoRaizName());
        nosSolucao.push_back(infoArestaAux->GetNoDestinoName());
        
        while( nosSolucao.size() != nosSolucao.capacity() ){
            
        }
    }


}
