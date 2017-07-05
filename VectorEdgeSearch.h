/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VectorEdgeSearch.h
 * Author: Usuario
 *
 * Created on 11 de Dezembro de 2016, 15:20
 */

#ifndef VECTOREDGESEARCH_H
#define VECTOREDGESEARCH_H

#include "EdgeSearchInfo.h"
#include "Grafo.h"
#include <vector>

using namespace std;

class VectorEdgeSearch {
public:
    VectorEdgeSearch();
    VectorEdgeSearch(No* node, Grafo* graph);
    virtual ~VectorEdgeSearch();
    
    void insertEdgeSearch( EdgeSearchInfo* edgeSearchInfo);
    EdgeSearchInfo* containsEdge(EdgeSearchInfo* edgeSearchInfo);
    bool containsAny(EdgeSearchInfo* edgeSearchInfo);
    
    vector<int> connectedWith(int conectado);
    
    EdgeSearchInfo* get(int position);

    int getSize();
    
    EdgeSearchInfo* getMinimal();
    EdgeSearchInfo* getMinimal(int nodeName);
    EdgeSearchInfo* getMinimalConnectedToSolution( );
    
    void relaxVector();
    void relaxSolution();
    
    string printVetor();
    string printVetorShortestPath();
    void sortVetor();
    
    void setPeso( EdgeSearchInfo* edgeSearchInfo );
    void setPeso( EdgeSearchInfo* edgeSearchInfo, int raiz );
private:
    EdgeSearchInfo* deletePosition( int i);
    
    std::vector<EdgeSearchInfo*> vetor;
    stringstream auxSS;
};

#endif /* VECTOREDGESEARCH_H */