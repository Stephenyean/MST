#ifndef HEAD_H
#define HEAD_H
#include <algorithm>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>
#include <vector>

typedef CGAL::Exact_predicates_inexact_constructions_kernel            Kernel;
typedef CGAL::Triangulation_vertex_base_with_info_2<unsigned int, Kernel> Vb;
typedef CGAL::Triangulation_data_structure_2<Vb>                       Tds;
typedef CGAL::Delaunay_triangulation_2<Kernel, Tds>                    Delaunay;
typedef Kernel::Point_2                                                Point;

using namespace std;
std::vector<float> generatePoints(int L, int H, int Number);
std::vector<std::pair<Point,unsigned> > generatePointsVector(std::vector<float>);
std::vector<pair<int,int> > getEdges(vector<float>);
#endif
