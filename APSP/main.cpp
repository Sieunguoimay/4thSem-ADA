#include<iostream>
#define INF 99999
#define V 5
void copyMatrix(int A[][V], int B[][V]);
void printSolution(int A[][V]);
int counter = 0;

void matrix_multiply(int D[][V],int G[][V]){
	int C[V][V];//temp
	for(int i = 0; i<V; i++)
		for(int j = 0; j<V; j++){

			int m = INF;
			for(int k = 0; k< V; k++){
				m = std::min(m,D[i][k]+G[k][j]);
				counter ++;
			}
			C[i][j] = m;//record the min weight sum of ???

		}
	copyMatrix(D,C);//return
}
void naiveMethod(int G[][V]){
	int D[V][V];
	copyMatrix(D,G);
	for(int i = 0; i<V-2;i++){
		matrix_multiply(D,G);//do this n-2 times..
		printSolution(G);
		printSolution(D);
	}
}

void RepeatedSquaring(int G[][V]){
	int D[V][V];
	copyMatrix(D,G);
	printSolution(G);
	for(int i = 1; i<V-1; i=2*i){
		matrix_multiply(D,D);
		printSolution(D);
	}
}
void FloydWarshall(int G[][V]){
	int D[V][V];
	int Temp[V][V];
	copyMatrix(D,G);
	for(int k = 0; k<V-1; k++){
		for(int i = 0; i<V; i++)
		for(int j = 0; j<V; j++){
			Temp[i][j] = std::min(D[i][j],D[i][k]+D[k][j]);
			counter++;
		}
		copyMatrix(D,Temp);//D is the previous matrix
		printSolution(D);
	}
}

/* A utility function to print solution */
void printSolution(int dist[][V])
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
void copyMatrix(int A[][V], int B[][V]){
	for(int i = 0; i<V; i++)
	for(int j = 0; j<V; j++)
		A[i][j] = B[i][j];
}
int main(){
	std::cout<<"Hello All Pair Shortest Path Algorithm\n";
	/* Let us create the following weighted graph
            10		7
       (0)------->(3)----->(4)
        |         /|\     /
      5 |          |	 /
        |          | 1	/ 9
       \|/         |   /
       (1)------->(2)<~
            3           */	
	int G[V][V] = { {0,   5,  INF, 10, INF},
                        {INF, 0,   3, INF, INF},
                        {INF, INF, 0,   1, INF},
                        {INF, INF, INF, 0, 7},
                        {INF, INF, 9, INF, 0}
                      };
	naiveMethod(G);//time complexity O(n^4)
	std::cout<<counter<<"\n";

	counter = 0;
	RepeatedSquaring(G);//time complexity O(logn*n^3)
	std::cout<<counter<<"\n";

	counter = 0;
	FloydWarshall(G);//time complexity O(n^3)
	std::cout<<counter<<"\n";

	return 0;
}