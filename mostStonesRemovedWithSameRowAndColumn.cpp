class Solution 
{
public:
    int n = INT32_MIN, m = INT32_MIN;

    bool isValid(int i, int j)
    {
        if(i >= 0 and i <= n and j >= 0 and j <= m)
        {
            return true;
        }
        return false;
    }

    void dfs(int i, int j, vector<string> &grid, vector<vector<bool>> &visited)
    {   
        if(visited[i][j] == true)
        {
            return;
        }
        
        visited[i][j] = true;
        int newX = i, newY = j;
        while(isValid(newX, newY))
        {
            if(grid[newX][newY] == '*' and visited[newX][newY] == false)
            {
                dfs(newX, newY, grid, visited);
            }
            newX++;
        }
        
        newX = i;
        while(isValid(newX, newY))
        {
            if(grid[newX][newY] == '*' and visited[newX][newY] == false)
            {
                dfs(newX, newY, grid, visited);
            }
            newX--;
        }
        
        newX = i;
        while(isValid(newX, newY))
        {
            if(grid[newX][newY] == '*' and visited[newX][newY] == false)
            {
                dfs(newX, newY, grid, visited);
            }
            newY++;
        }
        
        newY = j;
        while(isValid(newX, newY))
        {
            if(grid[newX][newY] == '*' and visited[newX][newY] == false)
            {
                dfs(newX, newY, grid, visited);
            }
            newY--;
        }
    }
    

    int removeStones(vector<vector<int>>& stones) 
    {   
        int ans = 0;
        set<vector<int>> s;
        for (int i = 0; i < stones.size(); i++)
        {   
            if(stones[i][0] > n)
            {
                n = stones[i][0];
            }
            if(stones[i][1] > m)
            {
                m = stones[i][1];
            }
            s.insert(stones[i]);
        }

        vector<string> grid(n + 1);
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {   
                vector<int> coordinate(2);
                coordinate[0] = i;
                coordinate[1] = j;
                if(s.find(coordinate) != s.end())
                {
                    grid[i].push_back('*');
                }
                else
                {
                    grid[i].push_back('.');
                }
            }
        }

        vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if(visited[i][j] == false and grid[i][j] == '*')
                {   
                    ans++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return stones.size() - ans;
    }
};