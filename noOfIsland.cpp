#include<iostream>
#include<vector>
#include<map>

using namespace std;

class MazeTraversal
{
    private:
    vector<vector<int> > maze;
    int row = 4;
    int col = 4;
    int rowDir[4] =  {1, -1, 0, 0}; //right , left, 0, 0
    int colDir[4] = {0, 0, 1, -1}; //0, 0, up, down
    int noOfIsland = 0;
    public:
    MazeTraversal(vector<vector<int> >& grid): maze(grid){}
    int getNoOfIslands()
    {
        return noOfIsland;
    }
    bool isSafe(int x, int y)
    {
        if(x >= row || x < 0 || y>= col || y<0 || maze[x][y] == 0)
            return false;
        
        return true;
    }
    void dfs(int x, int y)
    {
        int movrow[] = { -1, 1, 0, 0};
        int movcol[] = { 0, 0, -1, 1};
        maze[x][y] = 0;
        
        for(int i=0; i<4; i++)
        {
            int newx = x + movrow[i];
            int newy = y + movcol[i];

            if(isSafe(newx, newy))
            {
                dfs(newx, newy);
                return;  //important point to understnd this, why we are returning from here is because, when we are at this
                /**
                 * it means we have traverse all the direction form the given newx and newy
                 *  but we couldn't move anymore from here 
                 * so we would return
                 * 
                 * if you note in other problems, while printing all the paths, we poped the element from the results
                 * that also from the same reasion, if we are that this line, it means we can move any direction and cannot
                 * reach the destionation
                 * so this path is invlaid, go back and search another path, 
                 * 
                 * we have two points to return, either when the path lead us to a destination or when that path doesn't lead us to the
                 * destination
                 * 
                 * after dfs can't move in any direction, we have to make a choic here, so we are as per requirement we decide
                 * 
                 * 
                 * simlar was the sitiation when we checked if path exits or not, we reurn from here, also check we have dfs in if condition
                 * 
                 * that means what we are retrunign is important, so we retunr truen
                 * 
                 * if(dfsPossible( desX, desY, newx, newy))
                {
                    return true;
                }  
                
                in this condition it is not negative condition, this means we dfs till the end and we got true, so we are returning true
                
                this is important, without if, we will have neagtive condtion too, 
                
                also when alll the direction are trired outside of that toop we will mark the visited node unvisited
                to consider then in next path, node is unmarking is not needed if we only are concered if path exits or not**/
            }
        }
    }
    void dsfUtil()
    {
        for(int i=0; i<maze.size(); i++)
        {
            for(int j=0; j<maze[0].size(); j++)
            {
                if(maze[i][j] == 1)
                {
                    noOfIsland++;
                    dfs(i,j);
                }
            }
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

    obj.dsfUtil();
    cout<< "Number of islands in the maze is: "<<obj.getNoOfIslands()<<endl;

    return 0;
}