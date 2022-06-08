#include<iostream>
using namespace std;

void docProb(double **graph, int nodes, int time, int curNode, double p, double *answer){
	if(time <= 0){
		answer[curNode] += p;
		return;
	}

	for(int i=1; i<=nodes; i++){
		if(graph[curNode][i] != 0){
			p *= graph[curNode][i];
			docProb(graph, nodes, time - 10, i, p, answer);
			p /= graph[curNode][i];	
		}
	}

}

int main(){
	int t;
	cin >> t;
	while(t--){
		int nodes, edges, time;
		cin >> nodes >> edges >> time;
		
		double **arr = new double*[nodes]; 
		for(int i=1; i<=nodes; i++){
			arr[i] = new double[nodes];
			for(int j=1; j<=nodes; j++){
				arr[i][j] = 0;
			}
		}

		int from, to;
		double prob;
		for(int i=0; i<edges; i++){
			cin >> from >> to >> prob;
			arr[from][to] = prob;
		}

		/* Initalise answer and function call */
		double answer[nodes] = {0.0};
		docProb(arr, nodes, time, 1, 1.0, answer);
		
		/* Select max Probability node */
		double finalProb = 0.0;
		int finalDivison = 0;
		
		for(int i=1; i<=nodes; i++){
			if(answer[i] > finalProb){
				finalProb = answer[i];
				finalDivison = i;
			}
		}
		cout << finalDivison << " " << finalProb << "\n";
	}
	return 0;
}