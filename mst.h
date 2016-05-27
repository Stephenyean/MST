#ifndef MST_H
#define MST_H
#include <vector>
using namespace std;
/*
class Vertex {
public:
	int data;
	int status;
	int parent;
};

class Edge {
public:
	int data;
	float weight;
	int status;
};
*/
class Graph {
public:
	Graph(vector<float>);
	~Graph();
	int N;
	float** E;
	bool* status;
	float computeMst();
	void printE();
};


#endif
