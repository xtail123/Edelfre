#include<bits/stdc++.h>

using namespace std;

bool vis[105] = {0}; // Esto funciona si quieres inicializar un arreglo con 0. Solo funciona con 0
vector< vector<int> > G; // Un grafo representado como una lista de aristas
int indegree[105];

vector <int> order;
void khan(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<G[i].size();j++){
            int vecino=G[i][j];
            indegree[vecino]++;
        }
    }
    priority_queue <int, vector <int>, greater<int> > q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int vertice=q.top();
        q.pop();
        order.push_back(vertice);
        for(int i=0;i<G[vertice].size();i++){
            int vecino=G[vertice][i];
            if(--indegree[vecino]==0){
                q.push(vecino);
            }
        }

    }

}
int main(){
	for(int i =0; i<=7;i++){
		vector<int> auxi;
		G.push_back(auxi);
	} // Creas vectores vacios, para crear la lista de adjacencia.
	// Cada nuevo vector, tendra los vecinos del vertice correspondiente
	// G[1] -> vecinos del vertice 1
	
	G[1].push_back(3); // Arista 1-2
	G[1].push_back(2); // Arista 1-3
	G[2].push_back(5); // Arista 2-4
	G[2].push_back(4); // Arista 2-5
	G[3].push_back(6); // Arista 3-6
	G[3].push_back(7); // Arista 3-7
	
	// Pruebas
	//dfs1(1);
	//dfs2(1);
	//bfs(1);
	khan(7);
	for(int i=0;i<order.size();i++){
		cout<<order[i]<<" ";
	}
}