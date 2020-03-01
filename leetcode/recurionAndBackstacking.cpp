#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cassert>

using namespace std;


class Solution {
public:
    //17
    vector<string> letterCombinations(string digits) 
    {
        res.clear();
        if("" == digits)
            return res;
        
        findCombination(digits,0,"");

        return res;

    }

    //46
    vector<vector<int>> permute(vector<int>& nums) 
    {
        res46.clear();

        if(nums.size() == 0)
            return res46;

        used46 = vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermutation46(nums, 0, p);

        return res46;

    }

    //77
    vector<vector<int>> combine(int n, int k) 
    {
        res77.clear();

        if(n <=0 || k<=0|| k>n)
            return res77;
        
        vector<int> c;

        m_combine(n, k, 1, c);
        return res77;
    }

private:
    vector<vector<int>> res77;
    
    void m_combine(int n, int k, int start, vector<int>& c)
    {
        if(k == c.size())
        {
            res77.push_back(c);
            return;
        }

        for(int i= start;i<=n - (k-c.size())+1;i++)
        {
            c.push_back(i);
            m_combine(n, k, i +1, c);
            c.pop_back();
        }

        return;

    }


    vector<vector<int>> res46;
    vector<bool> used46;

    void generatePermutation46(vector<int>& nums, int index, vector<int>& p)
    {
        if(index == nums.size())
        {
            res46.push_back(p);
            return;
        }

        for(int i = 0;i<nums.size(); i++)
        {
            if(!used46[i])
            {
                used46[i] = true;
                p.push_back(nums[i]);
                generatePermutation46(nums, index+1, p);
                p.pop_back();
                used46[i] = false;

            }
        }

        return;

    }

    const string letterMap[10]
    {
            " ",    //0
            "",     //1
            "abc",  //2
            "def",  //3
            "ghi",  //4
            "jkl",  //5
            "mno",  //6
            "pqrs", //7
            "tuv",  //8
            "wxyz"  //9
    };

    vector<string> res;

private:

    void findCombination(const string &digits, int index, const string &s)
    {
        if(index == digits.size())
        {
            res.push_back(s);
            return;
        }

        char c = digits[index];
        string letters = letterMap[c-'0'];
        for(int i = 0; i < letters.size(); i++)
        {
            findCombination(digits, index+1, s+letters[i]);
        }

        return;

    }

};

int main()
{




    return 0;
}