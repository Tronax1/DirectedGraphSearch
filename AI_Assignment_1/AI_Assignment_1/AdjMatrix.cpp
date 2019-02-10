#include "AdjMatrix.h"
#include <iostream>
#include <vector>

using namespace std;

AdjMatrix::AdjMatrix(int V) {
	this->vertices = V;
	matrix = new int*[V];
	for (int i = 0; i < V; i++) {
		matrix[i] = new int[V];
		for (int j = 0; j < V; j++) {
			matrix[i][j] = 0;
		}
	}
}
int AdjMatrix::min_distance(vector<int> distance, vector<bool> set) {
	int min = INT_MAX, index_min;
	int V = vertices;
	for (int i = 0; i < V; i++) {
		if (set[i] == false && distance[i] <= min) {
			min = distance[i];
			index_min = i;
		}	
	}
	return index_min;
}
void AdjMatrix::print_distance(vector<int> distance, int src, int dest) {
	cout << endl;
	cout << "The distance from vertex "<<src<<" to vertex "<<dest<<" is: " << distance[dest] << endl;
}
void AdjMatrix::print_path(vector<int> path, int src, int dest) {
	cout << endl;
	cout << "The path from vertex " << src << " to vertex " << dest << " is: ";
	for (int i = 0; i < path.size(); i++) {
		cout << path[i]<<" ";
		if (path[i] == dest) {
			cout << endl;
			break;
		}	
	}
}
void AdjMatrix::dijkstra(int src, int dest) {
	int V = vertices;
	vector<int> distances(V);
	vector<bool> set(V);
	vector<int> path;

	for (int i = 0; i < V; i++) {
		distances[i] = INT_MAX;
		set[i] = false;
	}
	distances[src] = 0;
	for (int i = 0; i < V - 1; i++)
	{
		int u = min_distance(distances, set);
		// Mark the picked vertex as processed 
		set[u] = true;
		path.push_back(u);
		// Update dist value of the adjacent vertices of the picked vertex. 
		for (int v = 0; v < V; v++)
			if (!set[v] && matrix[u][v] && distances[u] != INT_MAX
				&& distances[u] + matrix[u][v] < distances[v])
				distances[v] = distances[u] + matrix[u][v];
	}
	// print the constructed distance array 
	print_distance(distances, src, dest);
	print_path(path, src, dest);
}
void AdjMatrix::add_edge(int i, int j, int weight) {
	matrix[i][j] = weight;
}
void AdjMatrix::remove_edge(int i, int j) {
	matrix[i][j] = 0;
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

