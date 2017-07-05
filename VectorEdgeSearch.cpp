/*
 * To change this license header, choose License Headers in Project Properties->
 * To change this template file, choose Tools | Templates
 * and open the template in the editor->
 */

/* 
 * File:   VectorEdgeSearch->cpp
 * Author: Usuario
 * 
 * Created on 11 de Dezembro de 2016, 15:20
 */

#include <algorithm>

#include "VectorEdgeSearch.h"
#include "EdgeSearchInfo.h"
#include "Tsp.h"

VectorEdgeSearch::VectorEdgeSearch() {
}

VectorEdgeSearch::VectorEdgeSearch(No* node, Grafo* graph) {

    //    graph->breadthFirstSearchTree();

    No* auxNode = graph->getNoRaiz();
    while ( auxNode != NULL ) {

        Aresta* auxEdge = auxNode->getPrimeiraAresta();

        while ( auxEdge != NULL ) {
            //verify which is in the same Connected Component
            if ( node->getSearchInfo()->getConnectedComponent() == auxNode->getSearchInfo()->getConnectedComponent() ) {

                if ( !graph->isDigraph() ) {
                    if ( auxNode->getNome() < auxEdge->getNoDestino()->getNome() ) {
                        EdgeSearchInfo* edgeSearch = new EdgeSearchInfo(auxNode, auxEdge);
                        vetor.push_back(edgeSearch);
                    }
                } else {
                    EdgeSearchInfo* edgeSearch = new EdgeSearchInfo(auxNode, auxEdge);
                    vetor.push_back(edgeSearch);
                }
            }

            auxEdge = auxEdge->getProxAresta();
        }

        auxNode = auxNode->getProxNo();
    }
    sortVetor();
    //std::sort( vetor.begin(), vetor.end(), compararPeso );
}

VectorEdgeSearch::~VectorEdgeSearch() {
    vetor.clear();
}

void VectorEdgeSearch::insertEdgeSearch(EdgeSearchInfo* edgeSearchInfo) {
    vetor.push_back(edgeSearchInfo);
}

EdgeSearchInfo* VectorEdgeSearch::containsEdge(EdgeSearchInfo* edgeSearchInfo) {
    for ( EdgeSearchInfo* edgeAux : vetor ) {
        if ( edgeAux->ifHas(edgeSearchInfo->GetNoRaizName(), edgeSearchInfo->GetNoDestinoName()) )
            return edgeAux;
    }
    return NULL;
}

bool VectorEdgeSearch::containsAny(EdgeSearchInfo* edgeSearchInfo) {
    for ( int i = 0; i < vetor.size(); i++ ) {
        EdgeSearchInfo* edgeAux = vetor[i];
        if ( edgeAux->ifHas(edgeSearchInfo->GetNoRaizName()) || edgeAux->ifHas(edgeSearchInfo->GetNoDestinoName()) )
            return true;
    }
    return false;
}

vector<int> VectorEdgeSearch::connectedWith(int conectado) {
    vector<int> retorno;
    for ( EdgeInfo* elem : vetor ) {
        if ( elem->ifHas(conectado) ) {
            if ( elem->GetNoDestinoName() == conectado )
                retorno.push_back(elem->GetNoRaizName());
            else
                retorno.push_back(elem->GetNoDestinoName());
        }
    }
    return retorno;
}

int VectorEdgeSearch::getSize() {
    vetor.size();
}

EdgeSearchInfo* VectorEdgeSearch::get(int position) {
    return vetor[position];
}

EdgeSearchInfo* VectorEdgeSearch::getMinimal() {
    EdgeSearchInfo* auxEdgeSearch;

    if ( vetor[0]->hasBothInSolution() ) {
        while ( !vetor[0]->hasBothInSolution() ) {
            vetor.erase(vetor.begin());
            auxEdgeSearch = vetor[0];
        }
    }
    auxEdgeSearch = deletePosition(0);
    return auxEdgeSearch;
}

/**
 * Return the minimal weighted edgeInfo connected to a specific node
 * 
 * @param int nodeName
 * @return EdgeSearchInfo
 */
EdgeSearchInfo* VectorEdgeSearch::getMinimal(int nodeName) {
    EdgeSearchInfo* auxEdgeSearch = NULL;

    for ( int i = 0; i < vetor.size(); i++ ) {

        if ( vetor[i]->ifHas(nodeName) ) {
            auxEdgeSearch = deletePosition(i);
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
EdgeSearchInfo* VectorEdgeSearch::getMinimalConnectedToSolution() {
    EdgeSearchInfo* auxEdgeSearch = NULL;

    for ( int i = 0; i < vetor.size(); i++ ) {
        //verify if mininal is connected to the solution
        if ( vetor[i]->hasVisited() ) {
            auxEdgeSearch = deletePosition(i);
            break;
        }

    }
    return auxEdgeSearch;
}

/**
 * Relax the vector of Nodes, deleting those who have both nodes visited
 */
void VectorEdgeSearch::relaxVector() {

    for ( int j = 0; j < vetor.size(); j++ ) {
        if ( vetor[j]->hasBothInSolution() ) {
            vetor.erase(vetor.begin() + j);
            --j;
        }
    }
}

/**
 * Relax the solution, verifying if the solution is connected
 */
void VectorEdgeSearch::relaxSolution() {
    for ( int j = 0; j < vetor.size(); j++ ) {
        if ( vetor[j]->hasVisited() ) {

            vetor[j]->setBoth(true);
        }
    }
}

/**
 * Delete the edgeSeachInfo from a specific position
 * 
 * @param int i - position
 * @return EdgeSearchInfo* - delete object
 */
EdgeSearchInfo* VectorEdgeSearch::deletePosition(int i) {
    EdgeSearchInfo* auxEdgeInfo = get(i);

    int visitedOne = auxEdgeInfo->GetNoRaiz()->getSearchInfo()->getVisited();
    int visitedTwo = auxEdgeInfo->GetEdgeFather()->getNoDestino()->
            getSearchInfo()->getVisited();

    if ( visitedTwo == 2 )
        auxEdgeInfo->GetNoRaiz()->getSearchInfo()->setVisited(2);
    else
        auxEdgeInfo->GetNoRaiz()->getSearchInfo()->setVisited(1);

    if ( visitedOne == 2 )
        auxEdgeInfo->GetEdgeFather()->
        getNoDestino()->getSearchInfo()->setVisited(2);
    else
        auxEdgeInfo->GetEdgeFather()->
        getNoDestino()->getSearchInfo()->setVisited(1);

    vetor.erase(vetor.begin() + i);

    return auxEdgeInfo;
}

string VectorEdgeSearch::printVetor() {

    auxSS << endl;
    for ( int i = 0; i < vetor.size(); i++ ) {
        auxSS << vetor[i]->GetNoRaizName() << " : " << vetor[i]->GetNoDestinoName()
                << " -> " << vetor[i]->GetPeso() << endl;
    }
    return auxSS.str();
}

/**
 * Print the size of between two nodes
 * 
 * @return string
 */
string VectorEdgeSearch::printVetorShortestPath() {

    for ( int i = 0; i < vetor.size(); i++ ) {
        vetor[i]->GetNoRaiz()->getSearchInfo()->setVisited(false);
        vetor[i]->GetEdgeFather()->getNoDestino()
                ->getSearchInfo()->setVisited(false);
    }


    for ( int i = 0; i < vetor.size(); i++ ) {

        if ( !vetor[i]->GetNoRaiz()->getSearchInfo()->isVisited() ) {
            //Print
            auxSS << "\n No: " << vetor[i]->GetNoRaizName()
                    << "\t Custo do menor caminho: " << vetor[i]->GetNoRaiz()->
                    getSearchInfo()->getShortestPath();
            //Set visited true
            vetor[i]->GetNoRaiz()->
                    getSearchInfo()->setVisited(true);


        }
        if ( !vetor[i]->GetEdgeFather()->getNoDestino()->getSearchInfo()->isVisited() ) {

            auxSS << "\n No: " << vetor[i]->GetNoDestinoName()
                    << "\t Custo do menor caminho: " << vetor[i]->GetEdgeFather()->getNoDestino()
                    ->getSearchInfo()->getShortestPath();

            vetor[i]->GetEdgeFather()->getNoDestino()
                    ->getSearchInfo()->setVisited(true);
        }
    }
    return auxSS.str();
}

/**
 * Sort the vector
 */
void VectorEdgeSearch::sortVetor() {
    for ( int i = 0; i < vetor.size(); i++ ) {
        for ( int j = i + 1; j < vetor.size(); j++ ) {
            if ( vetor[i]->GetPeso() > vetor[j]->GetPeso() ) {
                std::swap(vetor[i], vetor[j]);
            }
        }
    }

}

void VectorEdgeSearch::setPeso(EdgeSearchInfo* edgeSearchInfo) {

    //Set the shorteste path if root node is not in the solution
    if ( edgeSearchInfo->GetNoRaiz()->getSearchInfo()->getShortestPath() == -1 ) {

        edgeSearchInfo->GetNoRaiz()->getSearchInfo()->setShortestPath(

                edgeSearchInfo->GetEdgeFather()->getNoDestino()->getSearchInfo()->getShortestPath()
                + edgeSearchInfo->GetEdgeFather()->getPeso()
                );

    } else if ( edgeSearchInfo->GetEdgeFather()->getNoDestino()->getSearchInfo()->getShortestPath() == -1 ) {

        edgeSearchInfo->GetEdgeFather()->getNoDestino()->getSearchInfo()->setShortestPath(

                edgeSearchInfo->GetNoRaiz()->getSearchInfo()->getShortestPath()
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
void VectorEdgeSearch::setPeso(EdgeSearchInfo* edgeSearchInfo, int raiz) {

    No* auxNode = edgeSearchInfo->GetNoRaiz();
    if ( auxNode->getNome() == raiz ) {
        auxNode->getSearchInfo()->setShortestPath(0);

        No* auxNode2 = edgeSearchInfo->GetEdgeFather()->getNoDestino();
        auxNode2->getSearchInfo()->setShortestPath(
                auxNode->getSearchInfo()->getShortestPath()
                + edgeSearchInfo->GetEdgeFather()->getPeso());
    } else {
        auxNode = edgeSearchInfo->GetEdgeFather()->getNoDestino();
        auxNode->getSearchInfo()->setShortestPath(0);

        No* auxNode2 = edgeSearchInfo->GetNoRaiz();
        auxNode2->getSearchInfo()->setShortestPath(
                auxNode->getSearchInfo()->getShortestPath()
                + edgeSearchInfo->GetEdgeFather()->getPeso());
    }
}
