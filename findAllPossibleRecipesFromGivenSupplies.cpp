class Solution 
{
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {   
        vector<string> ans;
        unordered_set<string> s;
        queue<int> q;
        for (int i = 0; i < recipes.size(); i++)
        {
            q.push(i);
        }
        for (int i = 0; i < supplies.size(); i++)
        {
            s.insert(supplies[i]);
        }

        bool nextIteration = true;
        while(nextIteration == true)
        {   
            nextIteration = false;
            queue<int> temp;

            while(not q.empty())
            {   
                bool possible = true;
                int i = q.front();
                q.pop();

                for (int j = 0; j < ingredients[i].size(); j++)
                {
                    if(s.find(ingredients[i][j]) == s.end())
                    {
                        possible = false;
                        break;
                    }
                }
                if(possible == true)
                {
                    s.insert(recipes[i]);
                    ans.push_back(recipes[i]);
                    nextIteration = true;
                }
                else
                {
                    temp.push(i);
                }
            }
            q = temp;
        } 
        return ans;
    }   
};