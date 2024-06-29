#include<iostream>
#include<vector>
#include<map>
#include<queue>
/**
 * 
 * 
 *     A --> B --> C
       |           |
       v           v
       D --> E <-- F

       adj list:
       std::unordered_map<char, std::vector<char>> adjList = {
        {'A', {'B', 'D'}},
        {'B', {'C'}},
        {'C', {}},
        {'D', {'E'}},
        {'E', {'F'}},
        {'F', {'E'}}
    };

    this is because we are storing the node also 

     // Print the adjacency list
    for (const auto& [node, neighbors] : adjList) {
        std::cout << node << " -> ";
        for (char neighbor : neighbors) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }


    we can use vector<vector<int>>, 

    / Adjacency list representation as vector of vectors
    std::vector<std::vector<int>> adjList = {
        {1, 3},   // Node A points to nodes B and D
        {2},      // Node B points to node C
        {5},      // Node C points to node F
        {4},      // Node D points to node E
        {},       // Node E has no outgoing edges
        {4}       // Node F points to node E
    };

    to see the node character we can use below formula

    for (int i = 0; i < adjList.size(); ++i) {
        std::cout << "Node " << char('A' + i) << " -> ";
        for (int neighbor : adjList[i]) {
            std::cout << char('A' + neighbor) << " ";
        }
        std::cout << std::endl;
    }


    BFS algo, we need to enqueue the node's neighbours and print the node and pop it

I will do it with both representations

 * 
 * 
 * ***/

using namespace std;

class bfsAdjList
{
    private:
    vector<vector<int> > adjlist;
    vector<bool> visited;
    public:
    bfsAdjList(vector<vector<int> >& list): adjlist(list), visited(4,false){}
    void print()
    {
       for(int i = 0; i<adjlist.size(); i++)
       {
        for(int j=0; j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j]<<"\t";
        }
        cout<<endl;
       } 
    }
    void bfsVector(int start, vector<int> &bfsorder)
    {
        queue<int> q;
        q.push(start);
        while(q.empty() == false )
        {
            int ele = q.front();
            //cout<<ele<<"\t";
            bfsorder.push_back(ele);
            
            //i have to push all neighbor of this ele now
            //into the que
            for(int i=0; i<adjlist[ele].size(); i++)
            {
                if(visited[adjlist[ele][i]] == false)
                {
                    visited[adjlist[ele][i]] = true;
                    q.push(adjlist[ele][i]);
                }
                   
            }
            q.pop();
        }
    }
    
};
int main()
{
    /*
       A --> B --> C
       |           |
       v           v
       D --> E <-- F
    */
    std::vector<std::vector<int>> adjList = {
        {1, 3},   // Node A points to nodes B and D
        {2},      // Node B points to node C
        {5},      // Node C points to node F
        {4},      // Node D points to node E
        {},       // Node E has no outgoing edges
        {4}       // Node F points to node E
    };
    bfsAdjList obj(adjList);
    //obj.print();
    vector<int> bfsorder;
    obj.bfsVector(0, bfsorder);
    for(auto x: bfsorder)
    {
        cout<<char('A' + x)<<"\t";
    }

    // Expected (A B D C E F )

    // Output (A	B	D	C	E	F)
    cout<<endl;
    return 0;
}