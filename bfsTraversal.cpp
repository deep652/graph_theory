#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

class BFSadjMatrixTraversal
{
    private:
    vector<vector<int> > adjMatrix;
    vector<int> visited;
    queue<int> q; 
    int row;
    int col;
    public:
    BFSadjMatrixTraversal(vector<vector<int> >& adjMatrix, int r, int c): adjMatrix(adjMatrix),row(r), col(c), visited(r){}
    BFSadjMatrixTraversal():visited(){}
    void printadjMatrix()
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cout<<adjMatrix[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    void bfs(int start)
    {
        /**
         * Algo is ilterative, we take help of queue
         * we mark the element and move to next element by process all the nodes of the graph**/

        q.push(start);
        int i=0;
        while(!q.empty())
        {
            //process the node
            int ele = q.front();
            cout<<ele<<"\t";
            q.pop();
            for(int j=0; j<col; j++)
            {
                if(adjMatrix[ele][j] == 1 && visited[j] == 0) //this means, if there is a edge between current elemet and jth element
                //and jth node is not visited, visit it/processit
                {
                    visited[j] = 1;
                    q.push(j);
                }
            }
            
        }

    }
    
};

int main()
{
    vector<vector<int> > adjMatrix = 
    {
    {0, 1, 0, 1, 0, 0},  // Edges from node 0 (a)
    {1, 0, 1, 0, 1, 0},  // Edges from node 1 (b)
    {0, 1, 0, 0, 0, 1},  // Edges from node 2 (c)
    {1, 0, 0, 0, 1, 0},  // Edges from node 3 (d)
    {0, 1, 0, 1, 0, 1},  // Edges from node 4 (e)
    {0, 0, 1, 0, 1, 0}   // Edges from node 5 (f) 
    };

    BFSadjMatrixTraversal obj(adjMatrix, adjMatrix.size(), adjMatrix[0].size());
    obj.printadjMatrix();
    cout<<"BFS traversal is: "<<endl;
    obj.bfs(0);


    /** graph is 
     * 
     * a - b - c
      |
      d - e


        {
        {0, 1, 0, 0, 0},  // Edges from node 0 (a)
        {1, 0, 1, 1, 0},  // Edges from node 1 (b)
        {0, 1, 0, 0, 0},  // Edges from node 2 (c)
        {0, 1, 0, 0, 1},  // Edges from node 3 (d)
        {0, 0, 0, 1, 0}   // Edges from node 4 (e)
        };

     its bfs traversal is 0 1 2 3 4 where we consider a b c d e at 0, 1, 2, 3, 4 node



       a - b - c
       |   |   |
       d - e - f


        vector<vector<int>> graph5 = {
        {0, 1, 0, 1, 0, 0},  // Edges from node 0 (a)
        {1, 0, 1, 0, 1, 0},  // Edges from node 1 (b)
        {0, 1, 0, 0, 0, 1},  // Edges from node 2 (c)
        {1, 0, 0, 0, 1, 0},  // Edges from node 3 (d)
        {0, 1, 0, 1, 0, 1},  // Edges from node 4 (e)
        {0, 0, 1, 0, 1, 0}   // Edges from node 5 (f)
        };
        
        0 1 3 2 4 5

    */


    
    return 0;
}