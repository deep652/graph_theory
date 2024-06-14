#include<iostream>
#include<vector>
#include<list>

using namespace std;
void buildGraph(vector< vector<int> >& adj)
{
    vector<int> connetion;
    connetion.push_back(1);
    connetion.push_back(2);
    adj.push_back(connetion);
    //adj[0].push_back(2);
    connetion.clear();
    connetion.push_back(3);
    connetion.push_back(4);
    adj.push_back(connetion);
    connetion.clear();
    connetion.push_back(5);
    adj.push_back(connetion);
    connetion.clear();
    connetion.push_back(1);
    adj.push_back(connetion);
    connetion.clear();
    connetion.push_back(1);
    adj.push_back(connetion);
    connetion.clear();
    connetion.push_back(2);
    adj.push_back(connetion);
}

void print(vector < vector <int> >& adj)
{
    for(int i=0; i<adj.size(); i++)
    {
        cout<<i<<"->";
        for(int j=0; j<adj[i].size(); j++)
        {
            cout<<adj[i][j]<<", ";
        }
        cout<<endl;
    }
}

void print_list(vector<list<int> >& adjList)
{
    for(auto x: adjList)
    {
        for(auto e: x)
        {
            cout<<e<<",";
        }
        cout<<endl;
    }
}
int main()
{

    /*
    0
    / \
    1   2
    /|   |
    3 4   5

    */

   //represent the above graph in both adjacency matrix and adjacency list

   int N = 6;
   vector< vector<int> > adj; //this is not correct way
   //either have this as adj<vector<int> > adj_matrix(v, vector(v, 0)); this is equivalent of array declaration
   //or have it like adj_matrix[v][v], this way you can use adj_matrix[root][edge] way. 
   //the current way is not okay becuase we are not able to use vector dynamic way to initialise the vector

   /**important 
    * you can do vector<vecotr<int> > adj(3) this will make the outer vector hold space for all the vertices
    * then do vector[0].push_back(res) where res is vector of int
    * 
    * the way you did above is also fine, only thing to keep in mind is it the order you have pushed the element is importanat
    * if you messed up that, it won't work as the indexes in outer vector will be messed up
    * **/

   //lets try with list
   vector<list<int> > adjList(6);
   adjList[0].push_back(1);
   adjList[0].push_back(2);
   adjList[1].push_back(3);
   adjList[1].push_back(4);
   adjList[2].push_back(5);
   adjList[3].push_back(1);
   adjList[4].push_back(1);
   adjList[5].push_back(2);

    //print the graph
    print_list(adjList);
    return 0;
}