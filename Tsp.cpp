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

    unsigned int intervaloRandomico = (int) alfa * vetor->getSize();
    if ( alfa == 0 ) {
        infoArestaAux = vetor->getMinimalConnectedToSolution();
    } else {
        VectorEdge* vetorConectados = new VectorEdge();
        for ( int i = 0; i < vetor->getSize(); i++ ) {
            EdgeInfo* auxEdge = vetor->get(i);
            if ( solucao->containsAny(auxEdge) ) {
                vetorConectados->insertEdgeSearch(auxEdge);
            }
        }

        intervaloRandomico = (int) alfa * vetorConectados->getSize();
        unsigned int indiceRandomico = (int) rand() % intervaloRandomico;

        infoArestaAux = vetorConectados->get(indiceRandomico);
        vetor->relaxSolution();
    }
}

void Tsp::criarCicloInicial(int noAInserir, int** floyd) {

    infoArestaAux = vetor->getMinimalConnectedToSolution();
    noAInserir(infoArestaAux->GetNoRaiz()->getSearchInfo()->isVisited()) ? infoArestaAux->GetNoDestinoName() : infoArestaAux->GetNoRaizName();

    EdgeInfo* edgeJaInserido = vetor->get(0);
    VectorEdge vetorAInserir;
    vetorAInserir.insertEdgeSearch(new EdgeSearchInfo(noAInserir, edgeJaInserido->GetNoRaizName()));
    vetorAInserir.insertEdgeSearch(new EdgeSearchInfo(noAInserir, edgeJaInserido->GetNoDestinoName()));
    for ( auto elem : vetorAInserir ) {
        EdgeInfo* inserir = vetor->containsEdge(elem);
        if ( inserir != NULL ) {
            solucao->insertEdgeSearch(inserir);
        } else {
            int menorCaminho = floyd[inserir->GetNoRaizName()][inserir->GetNoDestinoName()];
            grafo->inserirAresta(inserir->GetNoRaizName(), inserir->GetNoDestinoName(), menorCaminho);

            Aresta* arestaAux = grafo->getArestaAux();
            inserir = new EdgeSearchInfo(arestaAux->getNoDestino(), arestaAux);
            solucao->insertEdgeSearch(inserir);
        }
    }
}

string Tsp::reativoRandomizado(int iteracoes) {

    time_t begin, end;
    AuxSS.str(string());

    int noAInserir, noJaInserido;
    double diferenca,
            alfa = 0;
    int** floyd = grafo->constroiFloyd(grafo->getOrdem(), floyd);

    time(&begin);

    AuxSS << "------------------------------------------------------------\n";
    AuxSS << "-------------- Algoritmo Randomizado Reativo ---------------\n";
    AuxSS << "------------------------------------------------------------\n";

    tempoRandomizadoReaivo.resize(iteracoes);
    srand(time(NULL));

    vector<unsigned int> nosSolucao;

    for ( int i = 0; i < iteracoes; i++ ) {

        time(&begin);
        //Inicializa a busca
        vetor = new VectorEdge(grafo->getNoRaiz(), grafo);
        nosSolucao.resize(grafo->getOrdem());
        infoArestaAux = vetor->getMinimal();

        infoArestaAux->setBoth(true);
        nosSolucao.push_back(infoArestaAux->GetNoRaizName());
        nosSolucao.push_back(infoArestaAux->GetNoDestinoName());
        solucao->insertEdgeSearch(infoArestaAux);

        criarCicloInicial(noAInserir, floyd);

        //insercao dos nos ao ciclo
        while ( nosSolucao.size() != nosSolucao.capacity() ) {
            funcaoCriterio(0.3);

            if ( !infoArestaAux->GetNoRaiz()->getSearchInfo()->isVisited() ) {
                noAInserir = infoArestaAux->GetNoRaizName();
                noJaInserido = infoArestaAux->GetNoDestinoName();
            } else {
                noAInserir = infoArestaAux->GetNoDestinoName();
                noJaInserido = infoArestaAux->GetNoRaizName();
            }

            vector<int> valoresASubstituir;
            for ( int i = 0; i < solucao->getSize(); i++ ) {

            }

        }
    }


}
