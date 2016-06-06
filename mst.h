#ifndef MST_H
#define MST_H
#include <vector>
#include <algorithm>
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
class Node {
public:
	Node(int _w, int _e, float _weight) :w(_w), e(_e), weight(_weight) {}
	int w;
	int e;
	float weight;
	friend bool operator<(const Node&l, const Node&r);
};
class Graph {
public:
	Graph(vector<float>);
	Graph(vector<float>,std::vector<std::pair<int,int> >);
	~Graph();
	int N;
	float** E;
	bool* status;
	float computeMst();
	float pqMst();
	void printE();
};


#endif
