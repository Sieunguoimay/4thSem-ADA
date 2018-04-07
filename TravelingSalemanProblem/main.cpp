//this program is to implement TSP problem
//State the problem:
//given a complete weighted graph of n Cities.
//we have to find a cycle that starts from one city,
//travel through all other cities exactly once and
//get back to the starting city and contains minimum cost.

//this program solve the problem by dynamic programming
//with the time complexity of O(n^2*2^n);

//algorithm describe:
//find among each vertex j the minimum cost of all the paths
//that travel through j as the last vertex i.e.
//1-........-j-1

//for each vertex j, we run the loop to find the
//min cost for n-2 vertices (let it S) that connect to j.
//and that is again same as finding the min cost of j.
//i.e. for each vertex k in |S|-2 vertices other than j and 1.
//the recursion stop condition is when the set S includes only vertex 1 and j. the min cost then is distance(1,j)

#include<iostream>
#define V 4
#define INF 999999
struct VertexSet{
	int Vertices[V];//boolean is ok
	int Size = V;//how many vertices left
	VertexSet(){
		for(int i = 0; i<V; i++)
			Vertices[i] = 1;//put it in the set
	}
	void pop(int v){
		if(v<-1||v>V) return ;
		if(Vertices[v]>0){
			Vertices[v] = -1;//deleted =))
			//since vertex is indexed by unsigned  integer.
			Size --;
		}
	}
};

int MinCost(int G[][V],VertexSet a, int b,int c, int arr[]);
void TravelingSaleman(int G[][V]){
	int m = INF;
	int array[V+1];
	for(int i = 1; i<V; i++){// 1 2 3
		std::cout<<"For vertex: "<<i<<"\n";



		int arr[V+1];
		arr[0] = 0;
		arr[V] = 0;
		arr[V-1] = i;


		VertexSet remaining_set;//a full set of vertex for each new i
		int temp = MinCost(G,remaining_set,i,V-1, arr);
		temp += G[i][0];
		if(m>temp){
			m = temp;
			for(int j = 0; j<V+1; j++)
				array[j] = arr[j];
		}
		for(int i = 0;i<V+1; i++)
			std::cout<<arr[i]<<(i==V?"":"-");
		std::cout<<"\nCost: "<<temp<<"\n\n";
		
	}

	std::cout<<"Min cost for the trip is: "<<m<<"\n";
	for(int i = 0;i<V+1; i++)
		std::cout<<array[i]<<(i==V?"":"-");
}

int MinCost(int G[][V],
	VertexSet remaining_set, int last_vertex, int n, int arr[V]){
	n--;
	std::cout<<"Recursive level: "<<n<<"\n";

	if(remaining_set.Size == 2){
		return G[0][last_vertex];
	}

	//find the min cost of
	int m = INF;
	remaining_set.pop(last_vertex);
	int v = -1;
	for(int i = 1; i < V; i++){
		if(remaining_set.Vertices[i] >0){
			std::cout<<"Create New Branch from level: "<<n<<"\n";
			int temp = MinCost(G,remaining_set,i,n,arr)+G[i][last_vertex];
			std::cout<<"Come back to level: "<<n<<"\n";
			if(m>temp){
				m = temp; 
				v = i;
			}
		}
	}
	arr[n] = v;
	std::cout<<n<<"->"<<v<<"\n";
	return m;
}
int main(){
	std::cout<<"Hello Travelling saleman problem\n";
	//let's store the graph in a matrix
//	    8
//	(0)----(1)
//	 | \  / |
//	6|  /\  |9
//	 |5/  3\|
//	(3)----(2)
//	    7
	int G[V][V] = {
		{0,10,15,20},
		{5,0,9,10},
		{6,13,0,12},
		{8,8,9,0}
	};//symmatric matrix 
	TravelingSaleman(G);	
	return 0;
}