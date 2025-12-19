#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Edge{
    public:
        int v;
        int wt;
    
    Edge(int v, int wt){
        this->v = v;
        this->wt = wt;
    }
};

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
        

void Dijkstra(vector<vector<Edge>>graph, int src, int V){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int>dist(V, INT_MAX);
 
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(pq.size() > 0){
        int u = pq.top().second;
        pq.pop();

        vector<Edge>edges = graph[u];

        for(Edge e: edges){
            if(dist[u] + e.wt < dist[e.v]){
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v], e.v));
            }
        }
    }

    for(int d: dist){
        cout << d << " ";
    }
}

};

