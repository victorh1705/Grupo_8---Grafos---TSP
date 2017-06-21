#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

#include "Aresta.h"
#include "Grafo.h"
#include "No.h"

using namespace std;

class FileManager {
public:
    FileManager();
    virtual ~FileManager();
    
    static Grafo *readAndCreateGraph(string filename, bool isDigraph);
private:

};

#endif /* FILEMANAGER_H */

