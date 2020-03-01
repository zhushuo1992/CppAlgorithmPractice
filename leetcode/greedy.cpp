#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cassert>

using namespace std;

bool m_compare(const vector<int> &a, const vector<int> &b)
{
    if (a[1] != b[1])
        return a[1] < b[1];

    return a[0] < b[0];
}




class Solution
{


public:
    //455
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int gi = 0, si = 0, res = 0;

        while (gi < g.size() && si < s.size())
        {
            if (s[si] >= g[gi])
            {
                res++;
                gi++;
                si++;
            }
            else
            {
                gi++;
            }
        }

        return res;
    }

    //435
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return 0;

        
        sort(intervals.begin(), intervals.end(), m_compare);

        int res = 1;
        int pre = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= intervals[pre][1])
            {
                res++;
                pre = i;
            }
        }

        return intervals.size() - res;
    }


 
};

int main()
{

    return 0;
}