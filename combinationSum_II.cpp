class Solution
{
private:
    unordered_map<int, int> mp;
    vector<vector<int>> ans;
    vector<int> validAns;

    void help(vector<int> &validAns, int target, int start = 0, int currSum = 0)
    {
        if (currSum == target)
        {
            ans.push_back(validAns);
            return;
        }

        for (int i = start; i <= target; i++)
        {
            if (i + currSum > target)
            {
                break;
            }
            if (mp[i] > 0)
            {
                mp[i]--;
                validAns.push_back(i);

                help(validAns, target, i, currSum + i);

                mp[i]++;
                validAns.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        for (int i = 0; i < candidates.size(); i++)
        {
            mp[candidates[i]]++;
        }

        help(validAns, target);
        return ans;
    }
};