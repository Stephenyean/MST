#include "head.h"
#include <map>
#include <fstream>
#include <iostream>
#include <set>
typedef CGAL::Exact_predicates_inexact_constructions_kernel            Kernel;
typedef CGAL::Triangulation_vertex_base_with_info_2<unsigned int, Kernel> Vb;
typedef CGAL::Triangulation_data_structure_2<Vb>                       Tds;
typedef CGAL::Delaunay_triangulation_2<Kernel, Tds>                    Delaunay;
typedef Kernel::Point_2                                                Point; 
using namespace std;
vector<float> generatePoints(int L, int H, int Number)
{
	vector<float > pointVector;
	set<double> Set;
	for (int i = 0; i < Number; i++)
	{
		while (true)
		{
			int first = rand() % (H - L) + L;
			int second = rand() % (H - L) + L;
			if(Set.find(first*10000000+second)!=Set.end())
				continue;
			Set.insert(first*10000000+second);
//			cout<<i<<" "<<first<<" "<<second<<endl;
			pointVector.push_back(first);
			pointVector.push_back(second);
			break;
		}
	}
	return pointVector;
}
std::vector<std::pair<Point,unsigned> > generatePointsVector(std::vector<float> vP)
{
	std::vector<std::pair<Point,unsigned> > result;
	for(int i=0;i<vP.size();i+=2)
	{
		result.push_back(std::make_pair(Point(vP[i],vP[i+1]),i/2));
	}
	return result;	
}

std::vector<std::pair<int,int> > getEdges(vector<float> fVector)
{
	std::vector<std::pair<int,int> > result;
	std::vector<std::pair<Point,unsigned> > points=generatePointsVector(fVector);
        Delaunay triangulation;
        //cout<<points.size()<<" "<<fVector.size()<<endl;
        triangulation.insert(points.begin(),points.end());

        for(Delaunay::Finite_faces_iterator fit = triangulation.finite_faces_begin();fit != triangulation.finite_faces_end(); ++fit) {

                Delaunay::Face_handle face = fit;
		result.push_back(std::make_pair((int)face->vertex(0)->info(),(int)face->vertex(1)->info()));
		result.push_back(std::make_pair((int)face->vertex(0)->info(),(int)face->vertex(2)->info()));
		result.push_back(std::make_pair((int)face->vertex(1)->info(),(int)face->vertex(2)->info()));
        }
	return result;
}
	
