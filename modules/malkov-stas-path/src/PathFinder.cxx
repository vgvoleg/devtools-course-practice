#include "PathFinder.h"

#include <iostream>
#include <exception>

PathFinder::PathFinder() {

}

PathFinder::PathFinder(int** graph, int vertice_num, int start_vertex) {
    SetGraph(graph, vertice_num, start_vertex);
}

void PathFinder::SetGraph(int** graph, int vertice_num, int start_vertex) {
    if (graph == 0)
        throw std::exception("Null Graph");
    if (vertice_num < 0)
        throw std::exception("Cannot Set Negative Size");
    if (start_vertex < 0 || start_vertex >= vertice_num)
        throw std::exception("Invalid Start Vertex");
    _Graph = graph;
    _Size = vertice_num;
    _StartVertex = start_vertex;
    Reset();
    UpdateGraph();
    _IsInitialized = true;
}

void PathFinder::UpdateGraph() {
    for (int i = 0; i < _Size; i++) {
        int max_distance = INT_MAX;
        int index_of_min_distance = -1;
        for (int k = 0; k < _Size; k++)
            if (!_Visited[k] && _Distance[k] < max_distance)
                index_of_min_distance = k;
        if (index_of_min_distance == -1)
            break;
        int im = index_of_min_distance;
        for (int j = 0; j < _Size; j++)
            if (im != j && _Graph[im][j] && _Distance[im] + _Graph[im][j] < _Distance[j])
                _Distance[j] = _Distance[im] + _Graph[im][j];
        _Visited[im] = true;
    }
    CheckVetricesWithoutPath();
}

void PathFinder::CheckVetricesWithoutPath() {
    for (int i = 0; i < _Size; i++)
        if (_Distance[i] == INT_MAX)
            _Distance[i] = PATH_NOT_EXISTS;
}

void PathFinder::Reset() {
    if (_IsInitialized) {
        delete _Distance;
        delete _Visited;
    }
    _Distance = new int[_Size];
    _Visited = new bool[_Size];
    for (int i = 0; i < _Size; i++) {
        _Distance[i] = INT_MAX;
        _Visited[i] = false;
    }
    _Distance[_StartVertex] = 0;
}

int PathFinder::GetDistance(int vertex) {
    if (!_IsInitialized)
        throw std::exception("Not Initialized");
    if (vertex < 0 || vertex >= _Size)
        throw std::exception("Vertex Index Out Of Range");
    return _Distance[vertex];
}

int* PathFinder::GetDistances() {
    if (!_IsInitialized)
        throw std::exception("Not Initialized");
    return _Distance;
}

void PathFinder::SetStartVertex(int index) {
    if (!_IsInitialized)
        throw std::exception("Not Initialized");
    if (index < 0 || index >= _Size)
        throw std::exception("Start Vertex Index Out Of Range");
    SetGraph(_Graph, _Size, index);
}