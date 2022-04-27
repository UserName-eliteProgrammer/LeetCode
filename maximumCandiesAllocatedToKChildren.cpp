#define ll long long int
class Solution 
{
public:
    int maximumCandies(vector<int>& candies, long long k)  // binary Search
    {
        int h = *max_element(candies.begin(), candies.end()), l = 1, ans = 0;
        
        while(l <= h)
        {
            ll candiesGiven = (l + h) / 2, numOfStacksTillNow = 0;
            bool possible = false;
            for(int i = 0; i < candies.size(); i++)
            {
                if(candies[i] >= 0)
                {
                    numOfStacksTillNow += candies[i] / candiesGiven;
                }
                if(numOfStacksTillNow >= k)
                {   
                    possible = true;
                    break;
                }
            }
            if(possible == true)
            {
                ans = candiesGiven;
                l = candiesGiven + 1;
            }
            else
            {
                h = candiesGiven - 1;
            }
        }
        return ans;
    }
};