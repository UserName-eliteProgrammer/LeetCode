class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> res;
        if(numRows >= 1)
        {
            res.push_back({1});
        }
        if(numRows >= 2)
        {
            res.push_back({1, 1});
        }
        for(int i = 2; i < numRows; i++)
        {
            vector<int> temp(i + 1);
            int j = 1, k = i - 1, z = 0;
            temp[0] = temp[i] = 1;
            while(j <= k)
            {
                temp[j] = res[i - 1][z] + res[i - 1][z + 1];
                j++;
                z++;
            }
            res.push_back(temp);
        }
        return res;
    }
};