/** 3. Реализация класса графа (дополнительное задание)
    Что нужно сделать
    1. Прочитайте, что такое графы в дискретной математике, как граф можно представить в программе, 
    что такое матрицы смежности и списки смежности:
— «Просто о графах. Попытка популяризации»;
— «Теория графов. Дискретная математика»;
— «Представление графа с помощью матриц смежности, инцидентности и списков смежности».
    2. У вас есть базовый интерфейс для представления ориентированного графа. Напишите две реализации интерфейса:
ListGraph, хранящий граф в виде массива списков смежности;
MatrixGraph, хранящий граф в виде матрицы смежности.
    3. Реализуйте конструктор, принимающий IGraph. Такой конструктор должен скопировать переданный граф в создаваемый объект. 
    Обратите внимание, что иногда в одну реализацию графа копируется другая. Реализуйте все конструкторы копий 
    и операторы присваивания, если это необходимо.

Советы и рекомендации
Во всех алгоритмах поиска вам потребуются рёбра для вершин. Для этого используйте std::unordered_set и его метод contains.
Пример кода:

class IGraph {
public:
virtual ~IGraph() {}
IGraph() {};
IGraph(IGraph *_oth) {};
virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро
virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин
virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор «вершины» все вершины, в которые можно дойти по ребру из данной
virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор «вершины» все вершины, из которых можно дойти по ребру в данную
};

Чек-лист для проверки задания
• Реализованы два класса-наследника, имплементирующие корректные алгоритмы работы с графом как с матрицей смежности и списками смежности. */

#include <iostream>
#include <vector>
#include <unordered_set>

class IGraph {
public:
    virtual ~IGraph() {}
    IGraph() {};
    IGraph(IGraph *_oth) {};
    virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро
    virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор «вершины» все вершины, в которые можно дойти по ребру из данной
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор «вершины» все вершины, из которых можно дойти по ребру в данную
};

class ListGraph : public IGraph {
private:
    std::vector<std::unordered_set<int>> graph;
    
public:
    ListGraph() {};
    ListGraph(IGraph *_oth) {};
    void AddEdge(int from, int to) override {
        if (from >= graph.size() || to >= graph.size()) {
            graph.resize(std::max(from, to) + 1);
        }
        graph[from].insert(to);
    }
    int VerticesCount() const override {
        return graph.size();
    }
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override {
        for (auto i : graph[vertex]) {
            vertices.push_back(i);
        }
    }
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i].count(vertex) > 0) {
                vertices.push_back(i);
            }
        }
    }
};

class MatrixGraph : public IGraph {
private:
    std::vector<std::vector<int>> graph;

public:
    MatrixGraph() {};
    MatrixGraph(IGraph *_oth) {};
    void AddEdge(int from, int to) override {
        if (from >= graph.size() || to >= graph.size()) {
            graph.resize(std::max(from, to) + 1);
            for (int i = 0; i < graph.size(); i++) {
                graph[i].resize(std::max(from, to) + 1);
            }
        }
        graph[from][to] = 1;
    }
    int VerticesCount() const override {
        return graph.size();
    }
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override {
        for (int i = 0; i < graph[vertex].size(); i++) {
            if (graph[vertex][i] == 1) {
                vertices.push_back(i);
            }
        }
    }
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i][vertex] == 1) {
                vertices.push_back(i);
            }
        }
    }
};

int main() {
    ListGraph listGraph;
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 2);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(2, 3);
    listGraph.AddEdge(3, 0);
    std::vector<int> vertices;
    listGraph.GetNextVertices(0, vertices);
    for (auto i : vertices) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    listGraph.GetPrevVertices(2, vertices);
    for (auto i : vertices) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    MatrixGraph matrixGraph;
    matrixGraph.AddEdge(0, 1);
    matrixGraph.AddEdge(0, 2);
    matrixGraph.AddEdge(1, 2);
    matrixGraph.AddEdge(2, 3);
    matrixGraph.AddEdge(3, 0);
    matrixGraph.GetNextVertices(0, vertices);
    for (auto i : vertices) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    matrixGraph.GetPrevVertices(2, vertices);
    for (auto i : vertices) {
        std::cout << i << " ";
    }
    return 0;
}