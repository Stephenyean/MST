#include "mst.h"
#include "head.h"
#include <iostream>
#include <string.h>
//#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
//#include <CGAL/Delaunay_triangulation_2.h>
//#include <CGAL/Triangulation_vertex_base_with_info_2.h>

//typedef CGAL::Exact_predicates_inexact_constructions_kernel            Kernel;
//typedef CGAL::Triangulation_vertex_base_with_info_2<unsigned int, Kernel> Vb;
//typedef CGAL::Triangulation_data_structure_2<Vb>                       Tds;
//typedef CGAL::Delaunay_triangulation_2<Kernel, Tds>                    Delaunay;
//typedef Kernel::Point_2       Point;
using namespace std;
int main(int argc,char** argv)
{
	//vector<float> v{ 0,0,2,2,3,3,2,0 };
	std::vector<float> points=generatePoints(1,10000,atoi(argv[1]));	
//	Graph graph2(points);
//	cout<<graph2.computeMst()<<endl;
	std::vector<std::pair<int,int> > Edges=getEdges(points);
	Graph graph(points,Edges);
	cout<<graph.pqMst()<<endl;
	return 0;
}
