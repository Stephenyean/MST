#include "mst.h"
#include "head.h"
#include <iostream>
using namespace std;
int main()
{
	vector<float> v{ 0,0,2,2,3,3,2,0 };
	Graph graph(v);
	cout << graph.computeMst() << endl;
	return 0;
}