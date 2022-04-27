class Solution 
{
public:
    bool ans = false;
    
    bool isValid(int i, int j, int x, int y)
    {
        if(i < x and j < y and i >= 0 and j >= 0)
        {
            return true;
        }
        return false;
    }
    
    void help(string &osf, string &word, vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
    {
        if(osf.size() == word.size())
        {
            if(word.compare(osf) == 0)
            {
                ans = true;
            }
            return;
        }
        if(isValid(i, j, grid.size(), grid[0].size()) == false) return;
        if(visited[i][j] == true) return; 
        if(grid[i][j] != word[osf.size()]) return;
        
        osf.push_back(grid[i][j]);
        visited[i][j] = true;
          
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1,-1, 0, 0};
        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            help(osf, word, grid, visited, x, y); 
            
        }
        visited[i][j] = false;
        osf.pop_back();
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {   
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {   
                string osf = "";
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                help(osf, word, board, visited, i, j);
                if(ans == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};