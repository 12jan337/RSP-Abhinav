#include <iostream>
#include <vector>

using namespace std;

class Graph{
    private:
        int Vertices;
        vector<vector<int>> adjList;

    public:
        Graph(int v){
            this->Vertices = v;
            this->adjList.resize(v);
        }

        void addEdge(int u, int v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        void printList(){
            for(int i = 0; i < adjList.size(); i++){
                cout << i << ":";

                for(int j :adjList[i]){
                    cout << j << ",";
                }
                cout << endl;
            }
        }
};

class Edge{
    public:
        int u;
        int v;
        int wt;

    Edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    };

};

void bellmanFord(vector<vector<Edge>>graph, int src, int V){
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i = 0; i < V - 1; i++){
        for(int u = 0; u < V; u++){
            for(Edge e: graph[u]){
                if(dist[e.v] > dist[e.u] + e.wt){
                    dist[e.v] = dist[e.u] + e.wt;
                }
            }
        }
    }

    for(int i = 0; i < V; i++){
        cout << dist[i] << " ";
    }
}