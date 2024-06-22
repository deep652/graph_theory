#include<iostream>
#include<vector>
#include<map>

using namespace std;

class MazeTraversal
{
    private:
    vector<vector<int> > maze;
    vector<vector<int> > visited;
    int row = 4;
    int col = 4;
    public:
    MazeTraversal(vector<vector<int> >& grid): maze(grid){}
    MazeTraversal():visited(4, vector<int>{4, 0}){}
    void printGrid()
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cout<<maze[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    
};
int main()
{
    vector<vector<int> > grid = { 
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 1, 0, 0}
        };
    MazeTraversal obj(grid);
    obj.printGrid();
    
    return 0;
}