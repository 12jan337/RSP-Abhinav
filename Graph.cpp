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

        void topoHelper(int src, vector<bool>& vis, stack<int> &s){
            vis[src] = true;
            vector<int> neighbours = adjList[src];

            for(int v : neighbours){
                if(!vis[v]){
                    topoHelper(v, vis, s);
                }
            }

             s.push(src);
        }

        void topSort(){
            vector<bool> vis(Vertices, false);
            stack<int> s;

            for(int i = 0; i < Vertices; i++){
                if(!vis[i]){
                    topoHelper(i, vis, s);
                }
            }

            while(s.size() > 0){
                cout << s.top() << " ";
                s.pop();
            }

            cout << endl;
        }
        

};


int main(){
    int vertices = 4;
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(0, 3);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);

    graph.printList();

}