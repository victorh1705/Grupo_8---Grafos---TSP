#include "SearchInfo.h"

/**
 * SearchInfo constructor. The default variable configuration is:\n
 * 
 * nodeFather = NULL\n
 * level = -1\n
 * visited = false\n
 * connectedComponent = -1
 * shortestPath = -1
*/
SearchInfo::SearchInfo() {
    this->nodeFather = NULL;
    this->level = -1;
    this->visited = 0;
    this->connectedComponent = -1;
    this->shortestPath = -1;
}

/** Destructor */
SearchInfo::~SearchInfo() {
    //destrutor
}

/**
 * This function sets a new pointer to nodeFather.
 * 
 * @param nodeFather (new pointer)
 */
void SearchInfo::setNodeFather(No *nodeFather) {
    this->nodeFather = nodeFather;
}

/**
 * This function returns the nodeFather.
 */
No *SearchInfo::getNodeFather() {
    return this->nodeFather;
}

/**
 * This function sets a new value to level.
 * 
 * @param level (new value)
 */
void SearchInfo::setLevel(int value) {
    this->level = value;
}

/**
 * This function returns the level.
 */
int SearchInfo::getLevel() {
    return this->level;
}

/**
 * This function verify if the node was visited.
 */
bool SearchInfo::isVisited() {
    if (this->visited ==  0)
        return false;
    return true;
}

/**
 * This function sets the state of visited.
 * 
 * @param value (new value)
 */
void SearchInfo::setVisited(int value) {
    if( this->visited != 2)
        this->visited = value;
}

/**
 * This function sets the state of visited.
 * 
 * @param value (new value)
 */
void SearchInfo::setVisited(bool value) {
    if( value )
        this->visited = 2;
    else
        this->visited = 0;
}

/**
 * This function get the state of visited.
 * 
 */
int SearchInfo::getVisited() {
    return this->visited;
}

/**
 * This function sets a new value to connectedComponent.
 * 
 * @param level (new value)
 */
void SearchInfo::setConnectedComponent(int value) {
    this->connectedComponent = value;
}

/**
 * This function returns the connectedComponent.
 */
int SearchInfo::getConnectedComponent() {
    return this->connectedComponent;
}

int SearchInfo::getShortestPath() {
    return this->shortestPath;
}

void SearchInfo::setShortestPath(int shortestPath) {
    this->shortestPath = shortestPath;
}