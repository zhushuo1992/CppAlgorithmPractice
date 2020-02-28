#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cassert>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    //20
    bool isValid(string s)
    {
        stack<char> record;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                record.push(s[i]);
            }
            else
            {
                if(record.empty())
                    return false;
                if (s[i] == ')')
                {
                    if (record.top() == '(')
                    {
                        record.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (s[i] == '}')
                {
                    if (record.top() == '{')
                    {
                        record.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (s[i] == ']')
                {
                    if (record.top() == '[')
                    {
                        record.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }

        }

        if (record.size() != 0)
            return false;

        return true;
    }


    //144
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        m_preorderTraversal(root, ret);
        return ret;
    }

    //94
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        m_inorderTraversal(root, ret);
        return ret;
    }

    //145
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        m_postorderTraversal(root, ret);
        return ret;
    }

    //102
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(NULL == root)
            return res;
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(level == res.size())
                res.push_back(vector<int>());

            res[level].push_back(node->val);

            if(node->left)
                q.push(make_pair(node->left, level+1));
             if(node->right)
                q.push(make_pair(node->right, level+1));    

        }

        return res;

    }

    //279
    int numSquares(int n) 
    {
        int res[n+1] = {0};
        for(int i=1; i <= n; i++)
        {
            res[i] = i;

            for(int j=1;i-j*j>=0;j++)
            {
                res[i] = min(res[i], res[i-j*j]+1);
            }
        }

        return res[n];

    }

    //347
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int, int> freq;
        for(int i=0;i<nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> q;

        for(auto iter = freq.begin(); iter != freq.end();  iter++)
        {
            if(q.size() < k)
            {
                q.push(make_pair(iter->second, iter->first));
            }
            else
            {
                if(q.top().first < iter->second)
                {
                    q.pop();
                    q.push(make_pair(iter->second, iter->first));
                }
            }
            
        }
        vector<int> res;
        while(!q.empty())
        {
            res.push_back(q.top().second);
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;

    }

private:
    void m_preorderTraversal(TreeNode* root, vector<int>& ret) 
    {
        if(root)
        {
            ret.push_back(root->val);
            m_preorderTraversal(root->left, ret);
            m_preorderTraversal(root->right, ret);
        }

        return;
    }

    void m_inorderTraversal(TreeNode* root, vector<int>& ret) 
    {
        if(root)
        {
            m_inorderTraversal(root->left, ret);
            ret.push_back(root->val);
            m_inorderTraversal(root->right, ret);
        }

        return;
    }

    void m_postorderTraversal(TreeNode* root, vector<int>& ret) 
    {
        if(root)
        {
            m_postorderTraversal(root->left, ret);
            m_postorderTraversal(root->right, ret);
            ret.push_back(root->val);
        }

        return;
    }
};

int main()
{
    
    return 0;
}