#pragma once
#ifndef ADJECENCY_MATRIX
#define ADJECENCY_MATRIX

#include <vector>

class AdjMatrix {

private:
	int **matrix;
	int vertices;
public:
	AdjMatrix(int V);
	int min_distance(std::vector<int> distance, std::vector<bool> set);
	void print_path(std::vector<int> path, int src, int dest);
	void print_distance(std::vector<int> distance, int src, int dest);
	void dijkstra(int src, int dest);
	void add_edge(int i, int j, int weight);
	void remove_edge(int i, int j);
	void to_string();
	~AdjMatrix();
};
#endif

