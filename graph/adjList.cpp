#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;

    public:
     Graph(int v){
         V = v;
         l= new list<int>[V];
     }

     void addEdge(int x,int y,bool undir=true){
            if(undir){
                l[x].push_back(y);
            }
     }
     void printAdjList(){
         for(int i=0;i<V;i++){
             cout<<"Vertex "<<i<<"-->";
             for(auto x:l[i]){
                 cout<<x<<",";
             }
             cout<<endl;
         }
     }
};

int main(int argc, char const *argv[])
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.printAdjList();

    return 0;
}
