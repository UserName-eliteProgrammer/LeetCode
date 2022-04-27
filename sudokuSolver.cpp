class Solution 
{
private:
    int row[9][10], column[9][10], box[9][10], flag = 0;
    void initialize()
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
        return column[c][d] + row[r][d] + box[i][d] == 0;
    }

    void setCell(vector<vector<char>>& board, int r, int c, int d)
    {   
        int i = 3 * (r / 3) + (c / 3);
        column[c][d] = 1;
        row[r][d] = 1;
        box[i][d] = 1;
        board[r][c] = (char)(d + '0');
        return;
    }

    void resetCell(vector<vector<char>>& board, int r, int c, int d)
    {
        int i = 3 * (r / 3) + (c / 3);
        column[c][d] = 0;
        row[r][d] = 0;
        box[i][d] = 0;
        board[r][c] = '.';
        return;
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

    void help(vector<vector<char>>& board, int r, int c)
    { 
        if(r == 9)
        {   
            flag = 1;
            return;
        }

        if(board[r][c] == '.')
        {   
            for (int i = 1; i <= 9; i++)
            {
                if(isValid(i, r, c) == true)
                {
                    setCell(board, r, c, i);
                    
                    pair<int, int> newLocation;
                    newLocation = nextCell(r, c);
                    help(board, newLocation.first, newLocation.second);

                    if(flag == true)
                    {
                        return;
                    }
                    else
                    {
                        resetCell(board, r, c, i);
                    }
                }
            }
        }
        else
        {   
            pair<int, int> newLocation;
            newLocation = nextCell(r, c);
            help(board, newLocation.first, newLocation.second);
        }
        return;
    }

public:
    void solveSudoku(vector<vector<char>>& board) 
    {   
        initialize();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {   
                if(board[i][j] != '.')
                {
                    setCell(board, i, j, board[i][j] - '0');    
                }
            }
        }

        help(board, 0, 0);
        return;
    }
};