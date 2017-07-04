#ifndef SEARCHINFO_H
#define SEARCHINFO_H

#include "No.h"

class No;

class SearchInfo {
public:
    SearchInfo();
    virtual ~SearchInfo();

    void setNodeFather(No *node);
    No *getNodeFather();

    void setLevel(int value);
    int getLevel();

    void setVisited(int value);
    void setVisited(bool value);
    bool isVisited();
    int getVisited();

    void setConnectedComponent(int value);
    int getConnectedComponent();

    int getShortestPath();
    void setShortestPath(int shortestPath);

private:
    No *nodeFather;
    int level;
    int visited;
    int connectedComponent;
    int shortestPath;
};

#endif /* SEARCHINFO_H */

