#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#define WEIGHT 2
using Vertex = int;
using Weight = long long;
using Edge = std::tuple<Vertex, Vertex, Weight>;
using Graph = std::vector<Edge>;

class DisjointSet
{
private:
	static DisjointSet *arr;
	unsigned int rank;
	DisjointSet *p;
	DisjointSet() : rank(0), p(this) {}	
	static DisjointSet* Link(DisjointSet* x, DisjointSet* y)
	{
		if ( x->rank > y->rank )
			y->p = x;
		else
		{
			x->p = y;
			if ( x->rank == y->rank )
				++y->rank;
		}
		return y->p;
	}	
public:
	static void setN(int N)
	{
		arr = new DisjointSet[N]();
	}
	static DisjointSet* FindSet(DisjointSet* set)
	{
		if ( set != set->p ) {
			DisjointSet *ancestor = set->p;
			while ( ancestor != ancestor->p )
				ancestor = ancestor->p;
			set->p = ancestor;
		}
		return set->p;
	}
	static DisjointSet* FindSet(const int key)
	{
		return FindSet(&arr[key - 1]);
	}
	static DisjointSet* Union(DisjointSet* x, DisjointSet* y)
	{
		return Link(FindSet(x), FindSet(y));
	}
	static void Clear()
	{
		delete[] arr;
	}
};
DisjointSet* DisjointSet::arr;

int V, E;

Graph readData(){
	Graph graph;
	Vertex A, B;
	Weight C;
	
	std::cin >> V >> E;
	for(auto i = 0; i < E; ++i){
		std::cin >> A >> B >> C;
		auto [s, e] = std::minmax(A, B);
		graph.emplace_back(s, e, C);
	}
	return graph;
}

Weight findMSTWeight(Graph&& edgeList){
	Edge edge;
	Weight result = 0;
		
	// Sort by accending weights.
	std::sort(edgeList.begin(), edgeList.end(), [](const Edge& a, const Edge& b){ return std::get<WEIGHT>(a) < std::get<WEIGHT>(b); });
	
	// Initialize the disjoint set containing V elements.
	DisjointSet::setN(V);
	
	DisjointSet *a, *b;
	
	for(const auto& edge : edgeList){
		auto [A, B, weight] = edge;
		
		if((a = DisjointSet::FindSet(A)) != (b = DisjointSet::FindSet(B))){
			DisjointSet::Union(a, b);
			result += weight;
			std::cout << A << "->" << B << ":"<< weight << "\n";
		}
	}
	
	DisjointSet::Clear();
	
	return result;
}

int main()
{
	// Optimization Tricks
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	// Turn off the synchronization from c-style I/O functions(printf, scanf)
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);
	std::cout << findMSTWeight(readData()) << '\n';
	return 0;
}