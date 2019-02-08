#pragma once
#ifndef ADJECENCY_MATRIX
#define ADJECENCY_MATRIX

class AdjMatrix {

private:
	int **matrix;
	int vertices;
public:
	AdjMatrix(int V);
	void add_edge(int i, int j, int weight);
	void remove_edge(int i, int j);
	void to_string();
	~AdjMatrix();
};
#endif

