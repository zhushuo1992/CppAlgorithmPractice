#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    //349
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> record(nums1.begin(), nums1.end());

        vector<int> resultSet;
        for (int i = 0; i < nums2.size(); i++)
            if (record.find(nums2[i]) != record.end())
            {
                resultSet.push_back(nums2[i]);
                record.erase(nums2[i]);
            }

        return resultSet;
    }

    //350
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> map1;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++)
        {
            map1[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (map1[nums2[i]])
            {
                res.push_back(nums2[i]);
                map1[nums2[i]]--;
            }
        }

        return res;
    }

    //1
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> map1;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map1[(target - nums[i])])
            {

                res.push_back(map1[target - nums[i]] - 1);
                res.push_back(i);
                return res;
            }

            map1[nums[i]] = i + 1;
        }

        return res;
    }

    //454
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        unordered_map<int, int> sumAB;
        unordered_map<int, int> sumCD;

        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                sumAB[A[i] + B[j]]++;
            }
        }

        for (int i = 0; i < C.size(); i++)
        {
            for (int j = 0; j < D.size(); j++)
            {
                sumCD[C[i] + D[j]]++;
            }
        }
        int num = 0;
        auto iter = sumAB.begin();
        while (iter != sumAB.end())
        {
            auto iterCD = sumCD.find(-(iter->first));
            if (iterCD != sumCD.end())
            {
                num += (iter->second) * (iterCD->second);
            }

            iter++;
        }

        return num;
    }

    //447
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int res = 0;

        for (int i = 0; i < points.size(); i++)
        {
            map<int, int> dis;
            for (int j = 0; j < points.size(); j++)
            {
                if (i != j)
                {
                    dis[getDistance(points[i], points[j])]++;
                }
            }

            for (auto iter = dis.begin(); iter != dis.end(); iter++)
                res += iter->second * (iter->second - 1);
        }
        return res;
    }

    //219
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        if (nums.size() < 2)
            return false;
        if (k <= 0)
            return false;

        set<int> record;
        for (int i = 0; i < nums.size(); i++)
        {
            if (record.find(nums[i]) != record.end())
            {
                return true;
            }

            record.insert(nums[i]);

            if (k + 1 == record.size())
            {
                record.erase(nums[i - k]);
            }
        }

        return false;
    }

    //220
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        if (nums.size() < 2)
            return false;
        if (k <= 0)
            return false;
   

        set<long long> record;
        for (int i = 0; i < nums.size(); i++)
        {
            if (record.lower_bound((long long)nums[i] - (long long)t) != record.end() && *record.lower_bound((long long)nums[i] - (long long)t) 
                    <= (long long)nums[i]+(long long)t)
                return true;
            record.insert((long long)nums[i]);

            if (k + 1 == record.size())
            {
                record.erase((long long)nums[i - k]);
            }
        }

        return false;
    }

private:
    int getDistance(const vector<int> &A, const vector<int> &B)
    {
        return ((A[0] - B[0]) * (A[0] - B[0]) + (A[1] - B[1]) * (A[1] - B[1]));
    }
};

int main()
{

    return 0;
}