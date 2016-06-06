#include "mst.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;
Graph::Graph(vector<float> pV)
{
	N = pV.size()/2;
	E = new float*[N];
	status = new bool[N];
	for (int i = 0; i < N; i++) status[i] = false;
	for (int i = 0; i < N; i++)
		E[i] = new float[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			E[i][j] = -1;
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				E[i][j] = -1;
			else
				E[i][j] = sqrt((pV[2 * i] - pV[2 * j])*(pV[2 * i] - pV[2 * j]) + (pV[2 * i + 1] - pV[2 * j + 1])*(pV[2 * i + 1] - pV[2 * j +1]));
		}
	//printE();
}
Graph::~Graph()
{
	for (int i = 0; i < N; i++)
		delete[]E[i];
	delete[]E;
}
float Graph::computeMst()
{
	float minEdge;
	int minVertex;
	vector<int> visitedV;
	float Value = 0;
	status[0] = true;
	visitedV.push_back(0);
	while (visitedV.size()!=N)
	{
		minEdge = 1e20;
		for (int i = 0; i < visitedV.size(); i++)
		{
			int start = visitedV[i];
			for (int end = 0; end < N; end++)
			{
				if(status[end]==false)
					if (E[start][end] > 0 && E[start][end] < minEdge)
					{
						minEdge = E[start][end];
						minVertex = end;
					}
			}
		}
		Value += minEdge;
		//cout << minVertex << " " << minEdge << endl;
		status[minVertex] = true;
		visitedV.push_back(minVertex);
	}
	return Value;
}

float Graph::pqMst()
{
	priority_queue<Node> pq;
	for (int i = 0; i < N; i++) status[i] = false;
	status[0] = true;
	float Value = 0;
	Node node(0, 0, 0);
	//float *Min = new float[N];
	float Min[10000];
	for (int i = 0; i < N; i++) Min[i] = 1e20;
	for (int i = 0; i < N; i++)
	{
		if (E[0][i] > 0)
		{
			node.w = 0;
			node.e = i;
			node.weight = E[0][i];
			pq.push(node);
		}
	//		pq.push(Node(0, i, E[0][i]));
	}
	
	int count = 1;
	int current = 0;
	while (count<N)
	{
		while (!pq.empty() && status[pq.top().e])
			pq.pop();
		node = pq.top(); pq.pop();
		Value += node.weight;
		count++;
		//cout << node.weight << endl;
		current = node.e;
		for (int i = 0; i < N; i++)
		{
			if (E[current][i] > 0 && !status[i])
			{
				if (E[current][i] > Min[i])
					continue;
				Min[i] = E[current][i];
				node.w = current;
				node.e = i;
				node.weight = E[current][i];
				pq.push(node);
			}
		}
		status[current] = true;
	}
	return Value;
}

void Graph::printE()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << E[i][j] << " ";
		cout << endl;
	}
}

bool operator<(const Node & l, const Node & r)
{
	return l.weight>r.weight;
}
