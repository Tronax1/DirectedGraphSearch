#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>

#include "AdjMatrix.h"

using namespace std;

int main() {
	ifstream myFile;
	int data_entry, source, destination, Rows = 0;
	vector<int> vertices;
	myFile.open("Graph.txt");
	vector<vector<int>> data;//Size of the text file
	vector<int> rows;

	if (!myFile) {
		cout << "Couldnt open file"<<endl;
		exit(1);
	}
	int j = 0, i = 0;
	while (myFile >> data_entry) {
		if (j < 3) {
			rows.push_back(data_entry);
			if (j < 2) {
				vertices.push_back(data_entry);
				j++;
			}
			j++;
		}
		else {
			data.push_back(rows);
			rows.clear();
			data[i].push_back(data_entry);
			i++;
			j = 0;
		}
	}
	myFile.close();
	sort(vertices.begin(), vertices.end());
	vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());

	int V = vertices[vertices.size()-1]+1;
	AdjMatrix DirectedGraph(V);
	
	for (int i = 0; i < data.size(); i++) {	
		DirectedGraph.add_edge(data[i][0], data[i][1], data[i][2]);
	}

	cout << "Testing the results" << endl;
	cout << "Input the starting vertex: ";
	cin >> source;
	cout<<"Input the goal: ";
	cin >> destination;
	DirectedGraph.dijkstra(source, destination);
	
	return 0;
}

