class Solution 
{
private:
    bool ans = true;
    
    int row[9][10], column[9][10], box[9][10];
    void intialize()
    {
        for (int i = 0; i < 9; i++)
        {
            for(int j = 0; j <= 9; j++)
            {
                row[i][j] = 0;
                column[i][j] = 0;
                box[i][j] = 0;
            }
        }
        return;
    }

    bool isValid(int d, int r, int c)
    {   
        int i = 3 * (r / 3) + (c / 3); // 3R + C
        if(row[r][d] == 1 and column[c][d] == 1 and box[i][d] == 1)
        {
            return true;
        }
        return false;
    }
    
    pair<int, int> nextCell(int r, int c)
    {   
        pair<int, int> p;
        if(c == 8)
        {
            p.first = r + 1;
            p.second = 0;
        }
        else
        {
            p.first = r;
            p.second = c + 1;
        }
        return p;
    }
    
    void setCell(int r, int c, int d)
    {   
        int i = 3 * (r / 3) + (c / 3);
        column[c][d]++;
        row[r][d]++;
        box[i][d]++;
        return;
    }
    
    void help(vector<vector<char>>& board, int r, int c)
    {   
        if(r == 9) return;
        
        if(board[r][c] != '.')
        {
            if(isValid(board[r][c] - '0', r, c) == true)
            {
                pair<int, int> newLocation;
                newLocation = nextCell(r, c);
                help(board, newLocation.first, newLocation.second);
            }
            else
            {
                ans = false;
            }
        }
        else
        {
            pair<int, int> newLocation;
            newLocation = nextCell(r, c);
            help(board, newLocation.first, newLocation.second);
        }
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        intialize();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {   
                if(board[i][j] != '.')
                {
                    setCell(i, j, board[i][j] - '0');    
                }
            }
        }

        help(board, 0, 0);
        return ans;
    }
};