#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class graph
{
private:
    int v;//no of vertices
    set<int> *adj;
public:
    void create(int v)
    {
        this->v = v;
        adj = new set<int>[v];
    }

    void addEdge(int u, int v)
    {
        adj[u].insert(v);
        //adj[v].insert(u);
    }
    void display()
    {
        for(int i=0; i<v; i++)
        {
            cout<<i;
            for(auto x: adj[i])
            {
                cout<<"->" << x<<"\t";
            }
            cout<<endl;
        }
    }
    void searchEdge(int u, int v)
    {
        auto it =  adj[u].find(v);
        if(it!=adj[u].end())
        {
            cout<<"Edge is available between node "<< u<<" and node "<<v <<" of the underlying graph"<<endl;
        }
        else
        {
            cout<<"There is no edge between node "<< u << " and node " <<v <<" of the underlying graph"<<endl;
        }
    }

    void removeEdge(int u, int v)
    {
        auto it = adj[u].find(v);
        if(it!=adj[u].end())
        {
            cout<<"Found the edge. removing.."<<endl;
            adj[u].erase(it);
            cout<<"Removed"<<endl;
        }
        else
        {
           cout<<"There is no edge between node "<< u << " and node " <<v <<" of the underlying graph"<<endl;
        }
    }

    void transposegraph(graph &gt)
    {
        gt.create(v);
        for(int i=0; i<v; i++)
        {
            for(auto x: adj[i])
            {
                gt.adj[x].insert(i);
            }
        }
    }
};
int main()
{
    graph g;

    g.create(3);

    g.addEdge(0, 1);
    g.addEdge(2, 0);
    g.addEdge(2, 1);

    g.display();

    //g.searchEdge(1, 0);

    //g.removeEdge(2, 0);

    graph gt;

    g.transposegraph(gt);

    cout<<"transpose of the above graph is"<<endl;
    gt.display();



    return 0;
}

