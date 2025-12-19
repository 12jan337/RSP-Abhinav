#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph{
    private:
        int Vertices;
        vector<vector<int>> adjList;
        vector<vector<pair<int, int>>>list;

    public:
        Graph(int v){
            this->Vertices = v;
            this->adjList.resize(v);
            this->list.resize(v);
        }

        void addEdge(int u, int v, int wt){
            list[u].push_back(make_pair(v, wt));
            list[v].push_back(make_pair(u, wt));
        }

        void primsAlgo(int src){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap
            vector<bool>mstSet(Vertices, false);
            pq.push(make_pair(0, src));
            int cost = 0;

            while(pq.size() > 0){
                int u = pq.top().second;
                int wt = pq.top().first;
                pq.pop();

                if(!mstSet[u]){
                    mstSet[u] = true;
                    cost += wt;

                    vector<pair<int, int>> neighbours = list[u];

                    for(auto n : neighbours){
                        int v = n.first;
                        int currentWt = n.second;

                        pq.push(make_pair(currentWt, v));
                    }

                }

            }
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

class graph{
    public:
        vector<Edge>edges;
        int V;
        vector<int>par;
        vector<int>rank;

    graph(int V){
        this->V = V;

        for(int i =0; i < V; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int i){
        if(par[i] == i){
            return i;
        }

        return par[i] = find(par[i]);
    }

    void unionByRank(int a, int b){

        int parA = find(a);
        int parB = find(b);

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        } else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        } else{
            par[parA] = parB;
        }
    }

    void addEdge(int u, int v, int wt){
        edges.push_back(Edge(u, v, wt));
    }

    void kruskals (){
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){
            return a.wt < b.wt;
            });
        
        int minCost = 0;
        for(int i=0; i < edges.size(); i++) {
            Edge e = edges[i];
            int parU = find(e.u);
            int parV = find(e.v);
            if(parU != parV) {//no cycle edge unionByRank (parU, parV);
            minCost += e.wt;
        }   
    }
cout << "min cost" << endl;
}
};
