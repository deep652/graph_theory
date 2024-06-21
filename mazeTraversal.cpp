#include<iostream>
#include<vector>
#include<map>

using namespace std;

class MazeTraversal
{
    private:
    vector<vector<int> > maze;;
    vector<vector<int> > visited;
    int row = 4;
    int col = 4;
    int rowDir[4] =  {1, -1, 0, 0}; //right , left, 0, 0
    int colDir[4] = {0, 0, 1, -1}; //0, 0, up, down
    
    vector<vector<pair<int, int>>> allPaths;
    vector<pair<int,int> > result;
    public:
    MazeTraversal():visited(4, vector<int>(4,0)){}
    MazeTraversal(vector<vector<int> >& grid): visited(4, vector<int>(4, 0)), maze(grid){}
    bool isSafe(int x, int y)
    {
        if((x>=0 && x < row) && (y>=0 && y < col) && maze[x][y] == 1 && visited[x][y] == 0)
        {
            return true;
        }
        return false;
    }
    
    void dfs(int desX, int desY, int x, int y)
    {
        if(x == desX && y == desY)
        {
            allPaths.push_back(result);
            return;
        }
        visited[x][y] = 1;
        //check from x all row direction and from y all col direction
        for(int i=0; i<4; i++)
        {
            int newx = x + rowDir[i];
            int newy = y + colDir[i];
            //cout<<x<<","<<y<<endl;
            if(isSafe(newx,newy))
            {
                result.push_back(make_pair(newx,newy));
                dfs( desX, desY, newx, newy);
                result.pop_back();
            }
        }
        visited[x][y] = 0;
    }

    bool dfsPossible(int desX, int desY, int x, int y)
    {
        if(x == desX && y == desY)
        {
            return true;
        }
        visited[x][y] = 1;
        //check from x all row direction and from y all col direction
        for(int i=0; i<4; i++)
        {
            int newx = x + rowDir[i];
            int newy = y + colDir[i];
            //cout<<x<<","<<y<<endl;
            if(isSafe(newx,newy))
            {
                
                if(dfsPossible( desX, desY, newx, newy))
                {
                    return true;
                }  
            }
        }
        visited[x][y] = 0;
        return false;
    }


    void print()
    {
        for (const auto& p : allPaths)
        {
            for (const auto& cell : p) 
            {
                cout << "(" << cell.first << ", " << cell.second << ") ";
            }
            cout << endl;
        }
        
    }
};

int main()
{
    vector<vector<int> > grid = { 
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 1}
        };
    MazeTraversal obj(grid);

    obj.dfs(3,3,0,0);
    obj.print();

    cout<<endl<<obj.dfsPossible(3,3,0,0)<<endl;
    return 0;
}

// 1	0
// 1	1
// 1	2
// 2	2
// 3	2
// 3	3

// 3	1
// 3	0
// 2	3
// 3	3

// 1	3
// 1	3
// 2	3
// 3	3

// 2	2
// 3	2
// 3	3
// 3	1
// 3	0

/**
 * for the below maze

//  { 
//         {1, 0, 0, 0},
//         {1, 1, 1, 1},
//         {0, 0, 1, 1},
//         {1, 1, 1, 1}
// };

// (1, 0) (1, 1) (1, 2) (2, 2) (3, 2) (3, 3) 
// (1, 0) (1, 1) (1, 2) (2, 2) (2, 3) (3, 3) 
// (1, 0) (1, 1) (1, 2) (1, 3) (2, 3) (3, 3) 
// (1, 0) (1, 1) (1, 2) (1, 3) (2, 3) (2, 2) (3, 2) (3, 3) 

**/

/**
 * for another input
 *   
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 1}
        };
 * 
 * 

(1, 0) (1, 1) (2, 1) (3, 1) (3, 2) (3, 3) 
 * **/