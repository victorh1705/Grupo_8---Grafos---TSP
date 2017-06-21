/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vectorEdgeSearch.h
 * Author: Usuario
 *
 * Created on 11 de Dezembro de 2016, 15:20
 */

#ifndef VECTOREDGESEARCH_H
#define VECTOREDGESEARCH_H

#include "EdgeSearchInfo.h"
#include "Grafo.h"
#include <vector>

class vectorEdgeSearch {
public:
    vectorEdgeSearch();
    vectorEdgeSearch(No* node, Grafo* graph);
    virtual ~vectorEdgeSearch();
    
    void insertEdgeSearch( EdgeSearchInfo* edgeSearchInfo);
    
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
    
    void setWeigth( EdgeSearchInfo* edgeSearchInfo );
    void setWeigth( EdgeSearchInfo* edgeSearchInfo, int raiz );
private:
    EdgeSearchInfo* deletePosition( int i);
    
    std::vector<EdgeSearchInfo*> vetor;
    stringstream auxSS;
};

#endif /* VECTOREDGESEARCH_H */