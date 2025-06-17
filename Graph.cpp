#include<iostream>
#include<vector>
using namespace std ;
class Node
{
public :
    int data;
    Node(int data)
    {
        this->data=data;
    }
};
class Graph
{
    vector<vector<Node>>adjlist;
public :
    Graph(int u)
    {
        adjlist.resize(u);
    }
    Graph(double v)
    {
        adjlist.resize(v);
    }
    void addEdge(int u,int v)
    {
        adjlist[u].push_back(Node(v));
        adjlist[v].push_back(Node(u));
    }
    void printGraph()
    {
        for(int v=0; v<adjlist.size(); v++)
        {
            cout<<"\n Printing node :"<<v<<endl;
            for(auto i:adjlist[v])
            {
                cout<<"The Neighbour of the list are :"<<i.data<<""<<endl;
            }
            cout<<endl;
        }
    }
};
int main()
{
    int v=5;
    Graph graph(v) ;
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(3,4);
    graph.printGraph();
}
