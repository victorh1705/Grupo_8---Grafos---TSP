/*
 * To change this license header, choose License Headers in Project Properties->
 * To change this template file, choose Tools | Templates
 * and open the template in the editor->
 */

/* 
 * File:   vectorEdgeSearch->cpp
 * Author: Usuario
 * 
 * Created on 11 de Dezembro de 2016, 15:20
 */

#include <algorithm>

#include "vectorEdgeSearch.h"
#include "EdgeSearchInfo.h"

vectorEdgeSearch::vectorEdgeSearch() {
}

vectorEdgeSearch::vectorEdgeSearch(No* node, Grafo* graph) {
    
//    graph->breadthFirstSearchTree();
    
    No* auxNode = graph->getNoRaiz();
    while (auxNode != NULL) {
        
        Aresta* auxEdge = auxNode->getPrimeiraAresta();

        while (auxEdge != NULL) {
            //verify which is in the same Connected Component
            if( node->getSearchInfo()->getConnectedComponent() == auxNode->getSearchInfo()->getConnectedComponent() ){
                
                if (!graph->isDigraph()) {
                    if( auxNode->getNome() < auxEdge->getNoDestino()->getNome() ){
                        EdgeSearchInfo* edgeSearch = new EdgeSearchInfo( auxNode, auxEdge);
                        vetor.push_back( edgeSearch );    
                    }
                }else{
                    EdgeSearchInfo* edgeSearch = new EdgeSearchInfo( auxNode, auxEdge);
                    vetor.push_back( edgeSearch );    
                }
            }
            
            auxEdge = auxEdge->getProxAresta();
        }   
        
        auxNode = auxNode->getProxNo();
    }
    sortVetor();
    //std::sort( vetor.begin(), vetor.end(), compararPeso );
}


vectorEdgeSearch::~vectorEdgeSearch() {
    vetor.clear();
}

void vectorEdgeSearch::insertEdgeSearch(EdgeSearchInfo* edgeSearchInfo) {
    vetor.push_back( edgeSearchInfo );
}

int vectorEdgeSearch::getSize() {
    vetor.size();
}

EdgeSearchInfo* vectorEdgeSearch::get(int position) {
    return vetor[position];
}

EdgeSearchInfo* vectorEdgeSearch::getMinimal() {
    EdgeSearchInfo* auxEdgeSearch;
    
    if( vetor[0]->hasBothInSolution() ){
        while( !vetor[0]->hasBothInSolution() ){
            vetor.erase( vetor.begin() );
            auxEdgeSearch = vetor[0];
        }
    }
    auxEdgeSearch = deletePosition( 0 );
    return auxEdgeSearch;
}

/**
 * Return the minimal weighted edgeInfo connected to a specific node
 * 
 * @param int nodeName
 * @return EdgeSearchInfo
 */
EdgeSearchInfo* vectorEdgeSearch::getMinimal(int nodeName) {
    EdgeSearchInfo* auxEdgeSearch = NULL;
    
    for (int i = 0; i < vetor.size(); i++) {
        
        if ( vetor[i]->ifHas(nodeName) ){
            auxEdgeSearch = deletePosition( i );
            break;
        }
    }
    return auxEdgeSearch;
}

/**
 * Return the minimal weighted edgeInfo connected to the sollution
 * 
 * @return EdgeSearchInfo
 */
EdgeSearchInfo* vectorEdgeSearch::getMinimalConnectedToSolution() {
    EdgeSearchInfo* auxEdgeSearch = NULL;
    
    for (int i = 0; i < vetor.size(); i++) {
        //verify if mininal is connected to the solution
        if( vetor[i]->hasVisited() ){                
            auxEdgeSearch = deletePosition( i );
            break;
        }

    }
    return auxEdgeSearch;
}

/**
 * Relax the vector of Nodes, deleting those who have both nodes visited
 */
void vectorEdgeSearch::relaxVector() {
    
    for (int j = 0; j < vetor.size() ; j++) {        
        if( vetor[j]->hasBothInSolution() ){
            
            vetor.erase( vetor.begin() + j );
            --j;
        }
    }
}

/**
 * Relax the solution, verifying if the solution is connected
 */
void vectorEdgeSearch::relaxSolution() {
    for (int j = 0; j < vetor.size() ; j++) {        
        if( vetor[j]->hasVisited() ){
            
            vetor[j]->setBoth( true );
        }
    }
}

/**
 * Delete the edgeSeachInfo from a specific position
 * 
 * @param int i - position
 * @return EdgeSearchInfo* - delete object
 */
EdgeSearchInfo* vectorEdgeSearch::deletePosition(int i) {
    EdgeSearchInfo* auxEdgeInfo = get(i);
    
    int visitedOne = auxEdgeInfo->GetRootNode()->getSearchInfo()->getVisited();
    int visitedTwo = auxEdgeInfo->GetEdgeFather()->getNoDestino()->
                        getSearchInfo()->getVisited();
    
    if( visitedTwo == 2)
        auxEdgeInfo->GetRootNode()->getSearchInfo()->setVisited( 2 );
    else
        auxEdgeInfo->GetRootNode()->getSearchInfo()->setVisited( 1 );
    
    if( visitedOne == 2)
        auxEdgeInfo->GetEdgeFather()->
            getNoDestino()->getSearchInfo()->setVisited( 2 );
    else
        auxEdgeInfo->GetEdgeFather()->
            getNoDestino()->getSearchInfo()->setVisited( 1 );
    
    vetor.erase( vetor.begin() + i ); 
    
    return auxEdgeInfo;
}

string  vectorEdgeSearch::printVetor() {
    
    auxSS << endl;
    for (int i = 0; i < vetor.size(); i++) {
        auxSS << vetor[i]->GetRootNodeName() << " : " << vetor[i]->GetDestinyNodeName()
                << " -> " << vetor[i]->GetWeigth() << endl;
    }
    return auxSS.str();
}

/**
 * Print the size of between two nodes
 * 
 * @return string
 */
string vectorEdgeSearch::printVetorShortestPath() {
    
    for ( int i = 0; i < vetor.size(); i++ ) {
        vetor[i]->GetRootNode()->getSearchInfo()->setVisited( false );
        vetor[i]->GetEdgeFather()->getNoDestino()
            ->getSearchInfo()->setVisited( false );
    }

    
    for (int i = 0; i < vetor.size(); i++) {
        
        if( !vetor[i]->GetRootNode()->getSearchInfo()->isVisited() ){
            //Print
            auxSS << "\n No: " << vetor[i]->GetRootNodeName()
                    << "\t Custo do menor caminho: " << vetor[i]->GetRootNode()->
                        getSearchInfo()->getShortestPath();
            //Set visited true
            vetor[i]->GetRootNode()->
                        getSearchInfo()->setVisited( true );
            
            
        }if ( !vetor[i]->GetEdgeFather()->getNoDestino()->getSearchInfo()->isVisited() ){
            
            auxSS << "\n No: " << vetor[i]->GetDestinyNodeName()
                    << "\t Custo do menor caminho: " << vetor[i]->GetEdgeFather()->getNoDestino()
                        ->getSearchInfo()->getShortestPath();
            
            vetor[i]->GetEdgeFather()->getNoDestino()
                        ->getSearchInfo()->setVisited( true );
        }
    }
    return auxSS.str();
}

/**
 * Sort the vector
 */
void vectorEdgeSearch::sortVetor() {
    for (int i = 0; i < vetor.size(); i++) {
        for (int j = i + 1; j < vetor.size(); j++) {
            if ( vetor[i]->GetWeigth() > vetor[j]->GetWeigth() ) {
                std::swap( vetor[i], vetor[j]);
            }
        }
    }

}

void vectorEdgeSearch::setWeigth(EdgeSearchInfo* edgeSearchInfo) {
    
    //Set the shorteste path if root node is not in the solution
    if( edgeSearchInfo->GetRootNode()->getSearchInfo()->getShortestPath() == -1 ){
        
        edgeSearchInfo->GetRootNode()->getSearchInfo()->setShortestPath( 
        
                edgeSearchInfo->GetEdgeFather()->getNoDestino()->getSearchInfo()->getShortestPath()
                + edgeSearchInfo->GetEdgeFather()->getPeso()
        );
    
    }else if( edgeSearchInfo->GetEdgeFather()->getNoDestino()->getSearchInfo()->getShortestPath() == -1 ){
        
        edgeSearchInfo->GetEdgeFather()->getNoDestino()->getSearchInfo()->setShortestPath(
        
                edgeSearchInfo->GetRootNode()->getSearchInfo()->getShortestPath()
                + edgeSearchInfo->GetEdgeFather()->getPeso()
        );
    }
}

/**
 * Set the weigth adding the minimal cost to reach the node
 * 
 * @param EdgeSearchInfo* edgeSearchInfo
 * @param int raiz - rootNode
 */
void vectorEdgeSearch::setWeigth(EdgeSearchInfo* edgeSearchInfo, int raiz) {
    
    No* auxNode = edgeSearchInfo->GetRootNode();
    if( auxNode->getNome() == raiz ){
        auxNode->getSearchInfo()->setShortestPath( 0 );
        
        No* auxNode2 = edgeSearchInfo->GetEdgeFather()->getNoDestino();
        auxNode2->getSearchInfo()->setShortestPath( 
                auxNode->getSearchInfo()->getShortestPath()
                + edgeSearchInfo->GetEdgeFather()->getPeso() );
    }else{
        auxNode = edgeSearchInfo->GetEdgeFather()->getNoDestino();
        auxNode->getSearchInfo()->setShortestPath( 0 );
        
        No* auxNode2 = edgeSearchInfo->GetRootNode();
        auxNode2->getSearchInfo()->setShortestPath( 
                auxNode->getSearchInfo()->getShortestPath()
                + edgeSearchInfo->GetEdgeFather()->getPeso() );
    }
}
