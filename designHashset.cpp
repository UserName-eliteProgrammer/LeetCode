class MyHashSet 
{
private:
    vector<list<int>> hashMap;
    int giveHashVal(int num)
    {
        int hashVal = num % 1009;
        return hashVal;
    }

public:
    MyHashSet() 
    {
        hashMap.resize(1009);
    }
    
    void add(int key) 
    {
        int hashVal = giveHashVal(key);
        hashMap[hashVal].push_back(key);
    }
    
    void remove(int key) 
    {
        int hashVal = giveHashVal(key);
        hashMap[hashVal].remove(key);
    }
    
    bool contains(int key) 
    {
        int hashVal = giveHashVal(key);
        for(auto ele : hashMap[hashVal])
        {
            if(ele == key) return true;
        }
        return false;
    }
};
