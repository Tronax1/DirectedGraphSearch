#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>

#include "AdjMatrix.h"

using namespace std;

int main() {
	ifstream myFile;
	int data_entry;
	vector<int> vertices;
	myFile.open("Graph.txt");
	int data[4][3];

	if (!myFile) {
		cout << "Couldnt open file"<<endl;
		exit(1);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			myFile >> data_entry;
			data[i][j] = data_entry;
			if (j < 2)
				vertices.push_back(data_entry);
		}
	}
	myFile.close();

	sort(vertices.begin(), vertices.end());
	vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());

	int V = vertices[vertices.size()-1]+1;
	AdjMatrix DirectedGraph(V);

	for (int i = 0; i < 4; i++) {	
		DirectedGraph.add_edge(data[i][0], data[i][1], data[i][2]);
	}
	DirectedGraph.to_string();

	return 0;
}

