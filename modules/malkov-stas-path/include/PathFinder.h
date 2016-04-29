// Copyright 2016 Malkov Stanislav

#ifndef MODULES_MALKOV_STAS_PATH_INCLUDE_PATHFINDER_H_
#define MODULES_MALKOV_STAS_PATH_INCLUDE_PATHFINDER_H_

#define PATH_NOT_EXISTS -1

#define MAX_DISTANCE 100000000

/* Алгоритм Дейкстры.
С помощью SetGraph передаем указатель на таблицу расстояний между vertice_num
вершин, после чего класс обрабатывает и сохраняет данные. */
class PathFinder {
    bool _IsInitialized = false;
    int ** _Graph;
    int _Size;
    int _StartVertex;
    int* _Distance;
    bool* _Visited;
    void UpdateGraph();
    void Reset();
    void CheckVetricesWithoutPath();
 public:
    PathFinder();
    PathFinder(int**, int, int = 0);
    ~PathFinder();
    void SetGraph(int**, int, int = 0);
    int GetDistance(int vertex);
    int* GetDistances();
    void SetStartVertex(int vertex);
    void SetPath(int, int, int);
};

#endif  // MODULES_MALKOV_STAS_PATH_INCLUDE_PATHFINDER_H_
