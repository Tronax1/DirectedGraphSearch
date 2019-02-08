#include "AdjMatrix.h"
#include <iostream>

using namespace std;

AdjMatrix::AdjMatrix(int V) {
	this->vertices = V;
	matrix = new int*[V];
	for (int i = 0; i < V; i++) {
		matrix[i] = new int[V];
		for (int j = 0; j < V; j++) {
			matrix[i][j] = -1;
		}
	}
}
void AdjMatrix::add_edge(int i, int j, int weight) {
	matrix[i][j] = weight;
}
void AdjMatrix::remove_edge(int i, int j) {
	matrix[i][j] = -1;
}
void AdjMatrix::to_string() {
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
AdjMatrix::~AdjMatrix() {
	for (int i = 0; i < vertices; i++) 
		delete[] matrix[i];
	delete[] matrix;
}

