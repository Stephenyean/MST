#include "head.h"
#include <map>
using namespace std;
vector<float> generatePoints(int L, int H, int Number)
{
	vector<float > pointVector;
	map<float, float> pointMap;
	for (int i = 0; i < Number; i++)
	{
		while (true)
		{
			float first = rand() % (H - L) + L;
			float second = rand() % (H - L) + L;
			if (pointMap[first] == second)
				continue;
			pointMap[first] = second;
			pointVector.push_back(first);
			pointVector.push_back(second);
			break;
		}
	}
	return pointVector;
}
