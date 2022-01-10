class Solution 
{
public:
    int BFS_Helper(vector<vector<int>> &grid)
    {   
        int totalComponents = 0, cornerComponents = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 0 and visited[i][j] == false)
                {   
                    totalComponents++;
                    queue<pair<int, int>> q;
                    bool isCorner = false;
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    // checking for cornnerComponent
                    if( (i == 0 or i == grid.size() - 1) or (j == 0 or j == grid[0].size() - 1 ))
                    {
                        cornerComponents++;
                        isCorner = true;
                    }

                    while(q.size())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++)
                        {
                            int newX = x + dx[k];
                            int newY = y + dy[k];

                            if(newX >= 0 and newX < grid.size() and newY >= 0 and newY < grid[0].size() and grid[newX][newY] == 0 and visited[newX][newY] == false)
                            {
                                q.push({newX, newY});
                                visited[newX][newY] = true;

                                // checking for cornerComponent
                                if((newX == 0 or newX == grid.size() - 1) or (newY == 0 or newY == grid[0].size() - 1))
                                {   
                                    if(isCorner == false)
                                    {
                                        cornerComponents++;
                                        isCorner = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return totalComponents - cornerComponents;
    }

    int closedIsland(vector<vector<int>>& grid) 
    {
        return BFS_Helper(grid);   
    }
};