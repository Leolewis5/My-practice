#include <iostream>
#include <vector>
#include <list>
#include <iomanip>

using namespace std;

int ExtractMin(int* ,bool* , int );

struct Edge{
	int from, to, weight;
	Edge(){}
	Edge(int f, int t, int w):from(f),to(t),weight(w){}
};



class GraphSP{
	private:
		int vertex;
		vector<list<Edge> > AdjList;
	public:
		GraphSP(){}
		GraphSP(int v):vertex(v){
			AdjList.resize(vertex);
		}
		void AddEdgeList(int, int, int);
		void DijkstraSP(int);
		friend int ExtractMin(int*,bool* , int);
		
};



void GraphSP::DijkstraSP(int start = 0){
	
	// allocated predecessor and value and visted array
	int predecessor[vertex], value[vertex];
	bool visted[vertex];
	
	//initial informantion
	for (int i=0; i<vertex ;i++){
		predecessor[i]=-1;
		value[i]=1000;//maxmun weight, should find a better method to assign it
		visted[vertex]=false;
	}
	
	
	int Checknode = vertex;
	
	//start from enter vertex
	int current = start;
	visted[current]=true;
	value[current]=0;
	Checknode--;
	
	// Dijkstra's visted
	while(Checknode != 0){
		for (list<Edge>::iterator itr = AdjList[current].begin(); itr != AdjList[current].end(); itr ++){
			if (visted[(*itr).to]==false&&value[(*itr).to]>(*itr).weight+value[current]) {
				value[(*itr).to] = (*itr).weight+value[current];
				predecessor[(*itr).to] = current;
			}
		}

		int extract = ExtractMin(value, visted, vertex);
		
		visted[extract] = true;
		current = extract;
		Checknode--;
	}
			

	
	// printSP
	cout << "begin from: "<< start <<" to each node which weight: "<<endl;
	for (int i=0; i< vertex; i++){
		cout << "vertex:" << i <<" , which weight is: "<<setw(3)<<value[i]<<endl;
	}
}

int ExtractMin(int * value, bool* visted,  int vertex){
	int min = 1000;
	int extract=0;
	for (int i=0; i<vertex; i++){
		if (visted[i]==false&&value[i]<min) {
			min = value[i];
			extract = i;
		}
	}
	return extract;
}


void GraphSP::AddEdgeList(int from, int end, int weight){
	Edge NewEdge(from,end,weight);
	AdjList[from].push_back(NewEdge);
}





int main(){
	/*
	GraphSP G(7);
    G.AddEdgeList(0, 1, 5);G.AddEdgeList(0, 5, 3);
    G.AddEdgeList(1, 0, 5);G.AddEdgeList(1, 2, 10);G.AddEdgeList(1, 4, 1);G.AddEdgeList(1, 6, 4);
    G.AddEdgeList(2, 1, 10);G.AddEdgeList(2, 3, 5);G.AddEdgeList(2, 6, 8);
    G.AddEdgeList(3, 2, 5);G.AddEdgeList(3, 4, 7);G.AddEdgeList(3, 6, 9);
    G.AddEdgeList(4, 1, 1);G.AddEdgeList(4, 3, 7);G.AddEdgeList(4, 5, 6);G.AddEdgeList(4, 6, 2);
    G.AddEdgeList(5, 0, 3);G.AddEdgeList(5, 4, 6);
    G.AddEdgeList(6, 1, 4);G.AddEdgeList(6, 2, 8);G.AddEdgeList(6, 3, 9);G.AddEdgeList(6, 4, 2);
	*/


    GraphSP G(6);
    G.AddEdgeList(0, 1, 8);G.AddEdgeList(0, 5, 1);
    G.AddEdgeList(1, 0, 3);G.AddEdgeList(1, 2, 1);
    G.AddEdgeList(2, 0, 5);G.AddEdgeList(2, 3, 2);G.AddEdgeList(2, 4, 2);
    G.AddEdgeList(3, 1, 4);G.AddEdgeList(3, 2, 6);G.AddEdgeList(3, 4, 7);G.AddEdgeList(3, 5, 3);
    G.AddEdgeList(5, 3, 2);G.AddEdgeList(5, 4, 8);
   



    std::cout << "SP found by Dijkstra :\n";
    G.DijkstraSP();

	
	return 0;
}

