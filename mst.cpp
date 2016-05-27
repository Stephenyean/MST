#include "mst.h"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
Graph::Graph(vector<float> pV)
{
	N = pV.size()/2;
	E = new float*[N];
	status = new bool[N];
	for (int i = 0; i < N; i++) status[i] = false;
	for (int i = 0; i < N; i++)
		E[i] = new float[N];
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			if (i == j) E[i][j] = -1;
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

void Graph::printE()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << E[i][j] << " ";
		cout << endl;
	}
}
