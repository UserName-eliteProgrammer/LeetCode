class Solution 
{
public:
    unordered_set<int> s;
    unordered_set<int> fS;
    int maxi = 0;
    vector<int> ans;

    void help(vector<int> &arr, int n, int index, int curr)
    {   
        if(index < 0) 
        {   
            if(curr > maxi)
            {
                maxi = curr;
                fS.clear();
                for(auto val: s)
                {
                    fS.insert(val);
                }
            }
            return;
        }
        if(n == 0)
        {
            if(curr > maxi)
            {
                maxi = curr;
                fS.clear();
                for(auto val: s)
                {
                    fS.insert(val);
                }
            }
            return;
        }

        if(n > arr[index])
        {   
            s.insert(index);
            help(arr, n - (arr[index] + 1), index - 1, curr + index);
            s.erase(index);
        }
        help(arr, n, index - 1, curr);
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) 
    {
        ans.resize(12);
        help(aliceArrows, numArrows, aliceArrows.size() - 1, 0);
        
        int sum = 0;
        for(auto ele : fS)
        {
            ans[ele] = aliceArrows[ele] + 1;
            sum += ans[ele];
        }

        if(sum < numArrows)
        {
            ans[11] += numArrows - sum;
        }
        return ans;
    }
};