#include<bits/stdc++.h>
using namespace std;


// Link --> https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/


class node
{
public:
    char data;
    map<char, node *> children;
    bool isPresent;

    node(char data)
    {
        this->data = data;
        isPresent = false;
    }
};

class Trie
{
public:
    node *root = new node('\0');

    node *createNode(char ch)
    {
        node *newNode = new node(ch);
        return newNode;
    }

    void insert(string input)
    {
        node *tempRoot = root;

        for (int i = 0; i < input.size(); i++)
        {
            if (tempRoot->children.find(input[i]) != tempRoot->children.end())
            {
                tempRoot = tempRoot->children[input[i]];
            }
            else
            {
                node *newNode = createNode(input[i]);
                tempRoot->children[input[i]] = newNode;
                tempRoot = newNode;
            }
        }
        tempRoot->isPresent = true;
        return;
    }

    string maxXor(string input)
    {
        node *tempRoot = root;
        string tempStr;
        for (int i = 0; i < input.size(); i++)
        {
            if (tempRoot->children.find('1') != tempRoot->children.end() and input[i] == '0')
            {
                tempStr.push_back('1');
                tempRoot = tempRoot->children['1'];
            }
            else if (tempRoot->children.find('0') != tempRoot->children.end() and input[i] == '1')
            {
                tempStr.push_back('0');
                tempRoot = tempRoot->children['0'];
            }
            else
            {
                tempStr.push_back(input[i]);
                tempRoot = tempRoot->children[input[i]];
            }
        }
        return tempStr;
    }
};

string numToBin(int num)
{
    string bin;
    int one = 1;
    for (int i = 31; i >= 0; i--)
    {
        if (num & (one << i))
        {
            bin.push_back('1');
        }
        else
        {
            bin.push_back('0');
        }
    }
    return bin;
}

int binToNum(string bin)
{
    int res = 0;
    for (int i = 0; i < bin.size(); i++)
    {
        if (bin[i] == '1')
        {
            res = res | (1 << (bin.size() - i - 1));
        }
    }
    return res;
}


class Solution {
public:
    int findMaximumXOR(vector<int>& arr) 
    {
        Trie T;
        T.insert(numToBin(arr[0]));

        int maxAns = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            int temp;
            string bin = numToBin(arr[i]);
            string output = T.maxXor(bin);
            temp = arr[i] xor binToNum(output);
            maxAns = max(maxAns, temp);
            T.insert(bin);
        }
        return maxAns;
    }
};