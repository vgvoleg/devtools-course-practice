#include "PathFinder.h"

#include <iostream>

PathFinder::PathFinder() {

}

PathFinder::PathFinder(int** graph, int vertice_num, int start_vertex) {
    SetGraph(graph, vertice_num, start_vertex);
}

void PathFinder::SetGraph(int** graph, int vertice_num, int start_vertex) {
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
}

void PathFinder::Reset() {
    if (_IsInitialized) {
        delete[] _Graph;
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
    return _Distance[vertex];
}