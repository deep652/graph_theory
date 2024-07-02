/*
cycle in a graph using BFS 
*/

/*
consider below graph
    0 -- 1 -- 2
    |    |  
    4 -- 3

adjlist

0 -> 1, 4
1 -> 2, 3
2 -> 1
3 -> 1, 4
4 -> 0, 3

this is undirected graph


directed graph example

    0 → 1 → 2
    ↑    ↓
    4 ← 3

std::vector<std::vector<int>> adjList = {
    {1},       // 0 -> 1
    {2, 3},    // 1 -> 2, 1 -> 3
    {},        // 2
    {4},       // 3 -> 4
    {0}        // 4 -> 0
};

using BFS solve this
and again revise the dfs algo to solve the same problem
*/
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class CycleDetection
{
    private:
    vector<vector<int> > adjlist;
    vector<bool> visited;
    public:
    CycleDetection(vector<vector<int> >& adj, int N): adjlist(adj),visited(N, false){}
    CycleDetection(){}
    void bfs(int start, vector<int>& path){}
    bool isCycle(int start){}

};
int main()
{
    vector<vector<int> > adjlist = {
        {1},
        {2, 3},
        {},
        {4},
        {0}
    };
    
    return 0;
}
