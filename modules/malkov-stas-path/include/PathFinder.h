#pragma once

/* Алгоритм Дейкстры.
С помощью SetGraph передаем указатель на таблицу расстояний между vertice_num вершин, 
после чего класс обрабатывает и сохраняет данные. */
class PathFinder {
    bool _IsInitialized = false;                            // Флаг инициализации
    int ** _Graph;                                          // Граф
    int _Size;                                              // Размер
    int _StartVertex;                                       // Вершина, от которой измеряем расстояние
    int* _Distance;                                         // Минимальные расстояния до вершин
    bool* _Visited;                                         // Посещенные вершины
    void UpdateGraph();                                     // Обработка графа
    void Reset();                                           // Сбрасывает все данные
public:
    PathFinder();
    PathFinder(int**, int, int = 0);
    void SetGraph(int**, int, int = 0);                     // Установка графа и параметров
    int GetDistance(int);                                   // Получение расстояния
};