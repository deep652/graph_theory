#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void addEdge(vector<int>g[], int u, int v)
{
    g[u].push_back(v);
}
void displayGraph(vector<int> g[], int s)
{
     for(int i=0;i<s;i++)
    {
        cout<<i<<"\t";
       for(auto t = g[i].begin(); t!=g[i].end(); t++)
        {
            cout<<"->"<<*t<<"\t";
        }
        cout<<endl;
    }
}

void removeGraph(vector<int> g[], int u, int v)
{
    auto it = find(g[u].begin(), g[u].end(), v);

    if(it != g[u].end())
    {
        g[u].erase(it);
    }
    else
    {
        cout<<"Sorry.. No edge found between "<< u << " and "<< v;
    }
}
int main()
{
    vector<int> g[5];
    int u, v;
    addEdge(g, 0, 1);
    addEdge(g, 1, 4);
    addEdge(g, 0, 4);
    addEdge(g, 4, 3);
    addEdge(g, 1, 3);
    addEdge(g, 2, 1);
    addEdge(g, 3, 2);
    //addEdge(g, 2, 0);
    //addEdge(g, 2, 0);

    cout<<"Adjency list is: "<<endl;
    displayGraph(g, 5);

    removeGraph(g, 1, 4);

    cout<<"after removeing the edge new Adjency list: "<<endl;
    displayGraph(g, 5);

    return 0;
}
