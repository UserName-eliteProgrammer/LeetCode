class DSU
{
	char parent[26]; 
	int size[26];
public:
	DSU()
	{
		char temp = 'a';
		for (int i = 0; i < 26; i++)
		{
			parent[i] = temp + i;
			size[i] = 1;
		}
	}

	char findParent(char c1)
	{
		if(parent[c1 - 'a'] == c1)
		{
			return c1;
		}
		return parent[c1 - 'a'] = findParent(parent[c1 - 'a']);
	}

	void unionOfChars(char c1, char c2)
	{
		char p1 = findParent(c1);
		char p2 = findParent(c2);
		if(p1 == p2)
		{
			return;
		}

		if(size[p1 - 'a'] > size[p2 - 'a'])
		{
			parent[p2 - 'a'] = p1;
			size[p1 - 'a'] += size[p2 - 'a'];
		}
		else
		{
			parent[p1 - 'a'] = p2;
			size[p2 - 'a'] += size[p1 - 'a'];
		}
	}
};


class Solution 
{
public:
    bool equationsPossible(vector<string>& equations) 
    {	
    	DSU dsu;
        vector<string> eqWithNot;
        bool ans = true;

        for (int i = 0; i < equations.size(); i++)
        {
        	if(equations[i][1] == '!')
        	{
        		eqWithNot.push_back(equations[i]);
        	}
        }

        for (int i = 0; i < equations.size(); i++)
        {
        	if(equations[i][1] != '!')
        	{
        		if(dsu.findParent(equations[i][0]) != dsu.findParent(equations[i][3]))
        		{
        			dsu.unionOfChars(equations[i][0], equations[i][3]);
        		}
        	}
        }

        for (int i = 0; i < eqWithNot.size(); i++)
        {
        	char p1 = dsu.findParent(eqWithNot[i][0]);
        	char p2 = dsu.findParent(eqWithNot[i][3]);

        	if(p1 == p2)
        	{
        		ans = false;
        		break;
        	}
        }
        return ans;
    }
};