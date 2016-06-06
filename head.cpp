#include "head.h"
#include <map>
#include <fstream>
#include <iostream>
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

vector<float> generatePoints(string filename)
{
	vector<float> V;
	ifstream fin(filename);
	float value;
	while (fin >> value)
		V.push_back(value);
	if (V.size() % 2 != 0) V.pop_back();
	cout << V.size() << endl;
	return V;
}
void processData(string filename)
{
	ifstream fin(filename);
	multimap<float, pair<int, int>> Map;
	float value;
	int l, r;
	pair<int, int> P;
	while (fin >> l >> r >> value)
	{
		P.first = l; P.second = r;
		Map.insert({ value,P });
	}
	cout << Map.size() << endl;
	ofstream fout("result_2.txt");
	for (auto iter = Map.begin(); iter != Map.end(); iter++)
		fout << iter->second.first << " " << iter->second.second << " " << iter->first << endl;
	fout.close();
	fin.close();
}
void processData2(string filename)
{
	ifstream fin(filename);
	vector<pair<int, int>> pairVector;
	int l, r;
	float value;
	while (fin >> l >> r >> value)
		pairVector.push_back(make_pair(l, r));
	vector<vector<int>> allClasses;
	for (int i = 0; i < pairVector.size() - 200; i++)
	{
		int j = 0, k = 0;
		for (j = 0; j < allClasses.size(); j++)
		{
			int j1;
			for (j1 = 0; j1 < allClasses[j].size(); j1++)
				if (pairVector[i].first == allClasses[j][j1])
					break;
			if (j1 != allClasses[j].size())
				break;
		}
		for (k = 0; k < allClasses.size(); k++)
		{
			int k1;
			for (k1 = 0; k1 < allClasses[k].size(); k1++)
				if (pairVector[i].second == allClasses[k][k1])
					break;
			if (k1 != allClasses[k].size())
				break;
		}
		if (j == allClasses.size())
		{
			if (k == allClasses.size())
			{
				vector<int> V{ pairVector[i].first,pairVector[i].second };
				allClasses.push_back(V);
			}
			else
			{
				allClasses[k].push_back(pairVector[i].first);
			}
		}
		else
		{
			if (k == allClasses.size())
				allClasses[j].push_back(pairVector[i].second);
			else
			{
				if (j != k)
				{
					for (int m = 0; m < allClasses[k].size(); m++)
						allClasses[j].push_back(allClasses[k][m]);
					allClasses[k].clear();
					allClasses.erase(allClasses.begin() + k);
				}
			}
		}
	}
	vector<vector<int>> realClasses;
	vector<int> falseClasses;
	ofstream fout("result4.txt");
	for (int i = 0; i < allClasses.size(); i++)
	{
		if (allClasses[i].size() > 100)
			realClasses.push_back(allClasses[i]);
	}
	ifstream fin2("data2.txt");
	vector<pair<float, float>> positions;
	float x, y;
	while (fin2 >> x >> y)
		positions.push_back(make_pair(x, y));
	vector<pair<float, float>> centers;
	for (int i = 0; i < realClasses.size(); i++)
	{
		float xx = 0, yy = 0;
		for (int j = 0; j < realClasses[i].size(); j++)
		{
			xx += positions[realClasses[i][j]].first;
			yy += positions[realClasses[i][j]].second;
		}
		xx /= realClasses[i].size();
		yy /= realClasses[i].size();
		centers.push_back(make_pair(xx, yy));
	}
	for (int i = 0; i < positions.size(); i++)
	{
		int j;
		for (j = 0; j < realClasses.size(); j++)
		{
			int k;
			for (k = 0; k < realClasses[j].size(); k++)
				if (realClasses[j][k] == i)
					break;
			if (k != realClasses[j].size())
				break;
		}
		if (j == realClasses.size())
			falseClasses.push_back(i);
	}
	for (int i = 0; i < falseClasses.size(); i++)
	{
		float distance = 1e20;
		int realclass = -1;
		for (int j = 0; j < realClasses.size(); j++)
		{
			if (sqrt(pow(positions[falseClasses[i]].first - centers[j].first, 2) + pow(positions[falseClasses[i]].second - centers[j].second, 2)) < distance)
			{
				distance = sqrt(pow(positions[falseClasses[i]].first - centers[j].first, 2) + pow(positions[falseClasses[i]].second - centers[j].second, 2));
				realclass = j;
			}
		}
		realClasses[realclass].push_back(falseClasses[i]);
	}
	ofstream fout2("result_3.txt");
	for (int i = 0; i < centers.size(); i++)
	{
		fout2 << realClasses[i].size() << endl;
		for (int j = 0; j < realClasses[i].size(); j++)
			fout2 << realClasses[i][j] << " ";
		fout2 << endl;
	}
}
