#ifndef TSP_H
#define TSP_H

#include <ctime>
#include <vector>
#include "Aresta.h"
#include "No.h"
#include "Grafo.h"
#include "EdgeSearchInfo.h"
#include "VectorEdgeSearch.h"

#define INFINITO 999999

typedef EdgeSearchInfo EdgeInfo;
typedef VectorEdgeSearch VectorEdge;

using namespace std;

class Tsp {
public:
    Tsp(Grafo* grafo);
    virtual ~Tsp();
    
    void funcaoCriterio(double alfa);
    string reativoRandomizado(int iteracoes);
    void criarCicloInicial(int noAInserir, int** floyd);


private:
    Grafo* grafo;

    stringstream AuxSS;
    
    VectorEdgeSearch* vetor;
    VectorEdgeSearch* solucao;
    EdgeInfo* infoArestaAux;
    
    vector<int> coverSetLengthRandomizedReactiveGreedyAlgorithm;
    vector<double> alphaRandomizadoReativo;
    vector<int> tempoRandomizadoReaivo;
    vector<int> custoRandomizadoReativo;

};

#endif /* TSP_H */

