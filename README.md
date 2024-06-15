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

3. 
     


 
   
