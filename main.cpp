#include "mst.h"
#include "head.h"
#include <iostream>
using namespace std;
int main()
{
	//vector<float> v{ 0,0,2,2,3,3,2,0 };
	Graph graph(generatePoints(1,10000,100));
	//Graph graph(v);
	cout << graph.computeMst() << endl;
	cout << graph.pqMst() << endl;
	return 0;
}