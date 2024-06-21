#include<iostream>
#include<vector>
#include<list>
#include<map>

using namespace std;

void printList(vector<vector<int> >& adjList)
{
    for(int i=0; i<adjList.size(); i++)
    {
        cout<<i+1<<"-> ";
        for(int j=0; j<adjList[i].size(); j++)
        {
            cout<<adjList[i][j]<<",";
        }
        cout<<endl;
    }
}

void dfs(vector<vector<int> >& adj, int v, map<int, bool>& visited)
{
     visited[v] = true;
     cout<<v<<" ";
     for(auto i = adj[v].begin(); i != adj[v].end(); i++ )
     {
        if(visited[*i] == false)
            dfs(adj, *i, visited);
     }
}
bool issafe(int x, int y, vector<vector<int> >& adj)
{
    if(x<adj.size() && y < adj[0].size() && x >=0 && y>=0 && adj[x][y] == 1 )
        return true;

    return false;
}
bool ratInMaze(vector<vector<int> >& adj, int x, int y, int dest_x, int des_y, vector<vector<int> >visited) //note
{
    if(des_y == y && dest_x == x)
    {
        return true;
    }
    int row_mov[4] = {1, -1, 0, 0};
    int col_mov[4] = {0, 0, 1, -1};
    visited[x][y] = 1;

    
    //for each neighbour, which is safe and a wall is not there, repeat this process
    //you can do it by sepeartly too, but try the ilterative way
    for(int move = 0; move < 4; move++)
    {
        int newx = x + row_mov[move];
        int newy = y + col_mov[move];

        if(issafe(newx, newy, adj) )
        {
            if(ratInMaze(adj, newx, newy, dest_x, des_y, visited))
            {
                return true; //check the reason here
            }
        }
        //this is for backtracking.. check this one too
        visited[x][y] = 0;
        return false
    }
    
}
int main()
{
    /**
    1
   / \
  2   3
 / \ / \
4   5   6

**/

//create adjlist for the above graph
vector<vector<int> > adjList(7);
adjList[1].push_back(2);
adjList[1].push_back(3);
adjList[2].push_back(4);
adjList[2].push_back(5);
adjList[3].push_back(5);
adjList[3].push_back(6);
adjList[4].push_back(2);
adjList[5].push_back(2);
adjList[5].push_back(3);
adjList[6].push_back(3);

printList(adjList);

//DFS travesal of the graph is
/**
 *      1 -> 2 -> 4 -> 5 -> 3 -> 6
 * we need 2D visited node Note: we don't need 2D, as our pourpose is to mark the node only
 * so 1D array is okay, as it denotes the node of the graph
 * and a stack, which is to go to the end of the neighbours
 *  **/
map<int, bool> visited;
dfs(adjList, 1, visited);


    return 0;
}