Rat in  a maze problem
1. point to understand is DFS traversal
2. DFS algo can be done in many ways
    1. ilterative way using a stack == We can skip this as this is not needed now, we can utilise the call stack, recusion provides 
     2. recursive 
        one point here is that for dfs traversal of a graph, we don't use directions manupulations, we do it by checking the neighbours
        but for graph or grid problem(e.g. rat in maze, island problem, etc, many backtracking problem too) we use the direction row[ 1, -1, 0, 0] and col[0, 0, 1, -1] to move inside the grid.
        and as because we do so like that, we also need to make sure after the movement, the positions are valids

        another point to understand is what is our goal,
        1. do we need to check whether it is possible to reach to the goal
        2. or do we need to print all the paths leading us to the goal

        In both the versions, the way we backtrack is a bit different.

3. important points
   1. while dealing with recursion, it is important to save the result somewhere which doesn't get lost while you backtrack
   2. in the below line of code it is important to note two things and understand it
   3. for(int i=0; i<4; i++)
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

        1. at line 28, if reach at apoint where you can't move forward, you need to backtrack, that will be handled by the call stack (which is the root of dfs) but before we do, the path/result need to be updated, i.e. the indexs we already pushed need to poped out, because followinf that path we didn't reach to our destination
        2.  why we have marked visited[x][y] = 0 at the outside of the loop
        because understand the recursion
        when you called dfs on 0, 0 you will try to move all direction from 0. the loop is for that movement. now while doing so, you are also calling the recursion on the dfs, this means a new copy of the method will get called with new x, y
        so when we reach a point when we can no longer move in any direction, we need to go back, that is when we come out of the loop (movement loop). and that is where we will want the x, y to be  marked as unvisited. 
     


 
   
