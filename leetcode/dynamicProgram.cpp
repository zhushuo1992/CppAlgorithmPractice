#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cassert>

using namespace std;

int fib(int n)
{

    if (n == 1)
        return 1;

    if (n == 2)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

vector<int> memo;

int fibMemResearch(int n)
{
    if (n == 1)
        return 1;

    if (n == 2)
        return 1;

    if(-1== memo[n])
    {
        memo[n] = fibMemResearch(n-1) + fibMemResearch(n-2);
    }   

    return memo[n];
    
    
}


int fibDynamicProgram(int n)
{
    if (n == 1)
        return 1;

    if (n == 2)
        return 1;

    int res[n+1] = {0};
    res[1] = 1;
    res[2] = 1;

    for(int i = 3;i<=n;i++)
        res[i] = res[i-1]+res[i-2];
    
    return res[n];
}

int knapsack01(const vector<int> &w, const vector<int> &v, int C)
{
    assert(w.size() == v.size() && C >= 0);
    int n = w.size();
    if(n == 0 || C == 0)
        return 0;
    
    vector<int> memo(C+1, 0);

    for(int i= 0;i<=C; i++)
    {
        memo[i] = i >= w[0]?v[0]:0;
    }

    for(int i = 0;i< n;i++)
    {
        for(int j = C;j>=w[i];j--)
        {

            memo[i] = max(memo[i], v[i] + memo[j-w[i]]);
        }
    }

    return memo[C];

}

class Solution {
public:

    //77
    int climbStairs(int n) 
    {
        if(0 == n)
            return 0;
        if(1 == n)
            return 1;
        
        int res[n+1] = {0};
        res[1] = 1;
        res[2] = 2;

        for(int i = 3; i<= n; i++)
            res[i] = res[i-1] + res[i-2];

        
        return res[n];
    }

    //343
    int integerBreak(int n) 
    {
        if(n <= 1)
            return 0;

        int res[n+1] = {0};

        res[1] = 1;
        res[2] = 1;
        //res[3] = 3;

        for(int i = 3; i<= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                res[i] = max3(res[i], j*(i-j), j*res[i-j]);
            }
        }


        return res[n];

    }

    //198
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(0 == n)
            return 0;
        if(1 == n)
            return nums[0];

        int res[n +1] = {0};

        res[1] = nums[0];
        res[2] = nums[0] > nums[1]? nums[0]:nums[1];

        for(int i = 3;i<= n; i++)
        {
            res[i] = max(res[i-2]+ nums[i-1], res[i-1]);
        }

        return res[n];
    }

    //416
    bool canPartition(vector<int>& nums) 
    {

        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum+= nums[i];
        
        if(sum % 2 != 0)
            return false;
        
        int n = nums.size();
        int C = sum/2;

        vector<bool> memo(C+1, false);

        for(int i =0;i<=C ;i++)
            memo[i] = (nums[0] == i);
        
        for(int i = 1; i< n; i++)
        {
            for(int j = C; j >=nums[i]; j--)
            {
                memo[j] = memo[j] || memo[j - nums[i]];
            }
        }

        return memo[C];

    }

    //300
    int lengthOfLIS(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        
        int n = nums.size();
        vector<int> memo(n, 1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                    memo[i] = max(memo[i], 1+ memo[j]);
                }
            }
        }

        int res = 0;

        for(int i =0;i< n;i++)
            res = max(res, memo[i]);

        return res;

    }

    //1143   真的不会了...
    int longestCommonSubsequence(string text1, string text2) 
    {

    }

private:
    int max3(int i, int j, int k)
    {
        return max(max(i, j), k);
    }
};


int main()
{

    cout << fib(6) << endl;

    int n = 20;
    memo = vector<int>(n+1, -1);

    cout << fibMemResearch(n) << endl;
    cout << fibDynamicProgram(n) << endl;


    return 0;
}