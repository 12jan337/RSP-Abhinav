#include <iostream>
#include <vector>
#include <list>

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

        void dfs(int u, vector<bool>& visited){
            visited[u] = true;
            cout << u << " ";

            for(int v: adjList[u]){
                if(!visited[v]){
                    dfs(v, visited);
                }
            }

        }
};

int main(){
    Graph graph(7);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    vector<bool>visited(7, false);
    graph.dfs(0, visited);
}