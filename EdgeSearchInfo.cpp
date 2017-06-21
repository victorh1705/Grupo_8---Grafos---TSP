/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EdgeSearchInfo.cpp
 * Author: Usuario
 * 
 * Created on 11 de Dezembro de 2016, 12:14
 */

#include "EdgeSearchInfo.h"
#include "No.h"

EdgeSearchInfo::EdgeSearchInfo() {
}

EdgeSearchInfo::EdgeSearchInfo(No* node, Aresta* edge) {
    noRaiz = node;
    noRaizNome = node->getNome();
    arestaPai = edge;
    noDestinoNome = edge->getNoDestino()->getNome();
    peso = edge->getPeso();
}

EdgeSearchInfo::~EdgeSearchInfo() {
}

void EdgeSearchInfo::SetWeigth(int weigth) {
    weigth = weigth;
}

int EdgeSearchInfo::GetWeigth() {
    return peso;
}

void EdgeSearchInfo::SetDestinyNodeName(int destinyNodeName) {
    destinyNodeName = destinyNodeName;
}

int EdgeSearchInfo::GetDestinyNodeName() {
    return noDestinoNome;
}

void EdgeSearchInfo::SetEdgeFather(Aresta* edgeFather) {
    edgeFather = edgeFather;
}

Aresta* EdgeSearchInfo::GetEdgeFather() {
    return arestaPai;
}

void EdgeSearchInfo::SetRootNodeName(int rootNodeName) {
    rootNodeName = rootNodeName;
}

int EdgeSearchInfo::GetRootNodeName() {
    return noRaizNome;
}

void EdgeSearchInfo::SetRootNode(No* rootNode) {
    rootNode = rootNode;
}

No* EdgeSearchInfo::GetRootNode() {
    return noRaiz;
}

/**
 * Set parameter visited of both nodes
 * 
 * @param bool
 */
void EdgeSearchInfo::setBoth(bool value) {
    noRaiz->getSearchInfo()->setVisited( true );
    arestaPai->getNoDestino()->getSearchInfo()
        ->setVisited( true );
}

/**
 * Return if one of the both nodes are the same to parameter
 * 
 * @param int rootName - node to be checked
 * @param int destinyName - node to be checked
 * @return bool
 */
bool EdgeSearchInfo::ifHas(int rootName, int destinyName) {
    if( noRaizNome == rootName || noDestinoNome == destinyName )
        return true;
    if( noRaizNome == destinyName || noDestinoNome == rootName )
        return true;
    return false;
}

/**
 * Return if one of the both nodes are the same to parameter
 * 
 * @param int rootName - node to be checked
 * @return bool
 */
bool EdgeSearchInfo::ifHas(int rootName) {
    if( noRaizNome == rootName  || noDestinoNome == rootName )
        return true;
    return false;
}

/**
 * Return if one of the both nodes have been visited.
 * 
 * @return bool
 */
bool EdgeSearchInfo::hasVisited() {
    if( noRaiz->getSearchInfo()->getVisited() != 0 )
        return true;
    else if( arestaPai->getNoDestino()->getSearchInfo()->getVisited() != 0 )
        return true;
    return false;
}

/**
 * Return if both nodes have already been visited.
 * 
 * @return bool
 */
bool EdgeSearchInfo::hasBothVisited() {
    if( noRaiz->getSearchInfo()->isVisited() ){
        if( arestaPai->getNoDestino()->getSearchInfo()->isVisited() )
            return true;
    }
    return false;
}

/**
 * Return if both nodes are already in the solution
 * 
 * @return bool
 */
bool EdgeSearchInfo::hasBothInSolution() {
    
    cout << "\n Root : " << noRaizNome  
            << " visited: "<< noRaiz->getSearchInfo()->getVisited()
            << " - Destiny : " << noDestinoNome 
            << " visited: "<< arestaPai->getNoDestino()->getSearchInfo()->getVisited();
            
    
    if( noRaiz->getSearchInfo()->getVisited() == 2 ){
        if( arestaPai->getNoDestino()->getSearchInfo()->getVisited() == 2 )
            return true;
    }
    return false;
}
