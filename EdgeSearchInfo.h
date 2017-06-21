/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EdgeSearchInfo.h
 * Author: Usuario
 *
 * Created on 11 de Dezembro de 2016, 12:14
 */

#ifndef EDGESEARCHINFO_H
#define EDGESEARCHINFO_H

#include "No.h"
#include "Aresta.h"

class EdgeSearchInfo {
public:
    EdgeSearchInfo();
    EdgeSearchInfo( No* node, Aresta* edge);
    virtual ~EdgeSearchInfo();
    
    void SetWeigth(int weigth);
    int GetWeigth();
    
    void SetDestinyNodeName(int destinyName);
    int GetDestinyNodeName();
    
    void SetEdgeFather(Aresta* edge);
    Aresta* GetEdgeFather();
    
    void SetRootNodeName(int rootName);
    int GetRootNodeName();
    
    void SetRootNode(No* root);
    No* GetRootNode();
    
    bool ifHas(int rootName, int destinyName);
    bool ifHas(int rootName);
    
    bool hasVisited();
    bool hasBothVisited();
    bool hasBothInSolution();
    
    void setBoth( bool value);
    
private:
    No* noRaiz;
    int noRaizNome;
    
    Aresta* arestaPai;
    int noDestinoNome;
    
    int peso; 
};

#endif /* EDGESEARCHINFO_H */

