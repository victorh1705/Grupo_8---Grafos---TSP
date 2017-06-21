#include "FileManager.h"

FileManager::FileManager() {
}

FileManager::~FileManager() {
}

/**
 * Essa funcao e chamada no main() quando o usuario pressiona 1.\n
 * 
 * O usuario coloca se ele deseja sobre o grafo digrafo, o programa le o arquivo
 * e faz as insercoes dos no e arestas. se bool askUser ==  FALSE,
 * o valor padrão do grafo e nao digrafo.\n
 *
 * ATTENTION: Ask the user to choose digraph makes it not necessary to make a 
 * check function, prevents edges are inserted when they should not be able
 * and the most interesting is that the same input file can now be used or not 
 * for digraphs.\n
 *
 * Exemplo: 1 2 333\n
 *    > Em um grafo normal: Cria 2 arestas(1 to 2 and 2 to 1)\n
 *    > em um digrafo: Cria 1 aresta (1 to 2)
 *
 * @param filename (file to be readed)
 */
Grafo *FileManager::readAndCreateGraph(string filename, bool isDigraph) {
    
    cout << "\nLendo o arquivo '" << filename << "' e criando o grafo...\n";
    
    fstream inputFile(filename.c_str());
    string linha;
    int noRaizNome, noDestinoNome, pesoAresta, numNo;
    int numberOfArgumentsFilled;
    
    Grafo *graph = new Grafo(isDigraph);

    getline(inputFile, linha);
    const char* aux = linha.c_str();
    sscanf(aux, "%d", &numNo);

    while (!inputFile.eof()) {
        getline(inputFile, linha);
        aux = linha.c_str();
        numberOfArgumentsFilled = sscanf(aux, "%d %d %d", &noRaizNome, &noDestinoNome, &pesoAresta);
        if (numberOfArgumentsFilled == -1) {
            continue;
        }
        
        No *noRaiz = graph->insereNo(noRaizNome, 0, true);
        if (!pesoAresta) {
            pesoAresta = 0;
        }
        
        if (noRaizNome != noDestinoNome) {
            No *noDestino = graph->insereNo(noDestinoNome, 0, true);
            graph->inserirAresta(noRaiz, noDestino, pesoAresta);
        } else if (noRaizNome == noDestinoNome) {
            graph->inserirAresta(noRaiz, noRaiz, pesoAresta);
        }
        
    }
    inputFile.close();
    return graph;
}

