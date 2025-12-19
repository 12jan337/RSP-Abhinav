#include <vector>
#include <iostream>

using namespace std;

class graph{
    private:
        int V;
        vector<vector<int>>adjList;
    public:
        graph(int V){
            this->V = V;
            adjList.resize(V);       
        }

        void addEdge(int u, int v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
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
        }
};

void Dijkstra(vector<vector<Edge>>graph, int src, int V){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
    vector<int>dist(V, INT_MAX);
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(pq.size() > 0){
        int u = pq.top().second;
        pq.pop();

        vector<Edge>edges = graph[u];

        for(Edge e :edges){
            if(dist[e.v] > dist[e.u] + e.wt){
                dist[e.v] = dist[e.u] + e.wt;
            }
        }
    }


}