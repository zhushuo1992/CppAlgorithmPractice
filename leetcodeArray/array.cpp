#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //283
    void moveZeroes(vector<int> &nums)
    {

        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (0 != nums[i])
                res.push_back(nums[i]);
        }

        for (int j = 0; j < res.size(); j++)
            nums[j] = res[j];
        for (int j = res.size(); j < nums.size(); j++)
            nums[j] = 0;

        return;
    }

    void moveZeroes2(vector<int> &nums)
    {

        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (0 != nums[i])
                nums[k++] = nums[i];
        }

        for (int j = k; j < nums.size(); j++)
            nums[j] = 0;

        return;
    }

    //75
    void sortColors(vector<int> &nums)
    {
        int num0 = 0, num1 = 0, num2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (1 == nums[i])
                num1++;
            else if (2 == nums[i])
                num2++;
            else
            {
                num0++;
            }
        }

        for (int i = 0; i < num0; i++)
        {
            nums[i] = 0;
        }

        for (int i = 0; i < num1; i++)
        {
            nums[num0 + i] = 1;
        }

        for (int i = 0; i < num2; i++)
        {
            nums[num0 + num1 + i] = 2;
        }

        return;
    }

    //167
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int start = 0;
        int end = numbers.size() - 1;
        while (start < end)
        {
            if (numbers[start] + numbers[end] == target)
            {
                vector<int> res = {start + 1, end + 1};
                return res;
            }
            else if (numbers[start] + numbers[end] > target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        vector<int> res;
        return res;
    }

    //209
    int minSubArrayLen(int s, vector<int> &nums)
    {

        int l = 0, r = -1; // nums[l...r]为我们的滑动窗口
        int sum = 0;
        int res = nums.size() + 1;

        while (l < nums.size())
        {

            if (r + 1 < nums.size() && sum < s)
                sum += nums[++r];
            else
            {
                sum -= nums[l++];
            }

            if (sum >= s)
                res = min(res, r - l + 1);
        }

        if (res == nums.size() + 1)
            return 0;

        return res;
    }

    //3
    int lengthOfLongestSubstring(string s) 
    {
        int freq[256] = {0};
        int l=0, r=-1;
        int len=0;

        while(l<s.size())
        {
            if(r+1<s.size() && freq[s[r+1]] == 0)
                freq[s[++r]] ++;
            else
            {
                freq[s[l++]]--;
            }

            len=max(len, r-l+1);
            
        }

        return len;

    }

};

int main()
{

    int nums[] = {2, 2, 2, 1, 1, 0};
    vector<int> vec = vector<int>(nums, nums + sizeof(nums) / sizeof(int));

    Solution().sortColors(vec);
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}