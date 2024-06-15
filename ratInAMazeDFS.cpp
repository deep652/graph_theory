#include<iostream>
#include<vector>
#include<list>

using namespace std;

void printList(vector<vector<int> >& adjList)
{
    for(int i=1; i<adjList.size(); i++)
    {
        for(int j=1; j<adjList[i].size(); j++)
        {
            cout<<adjList[i][j]<<",";
        }
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



    return 0;
}