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

class Solution {
public:

    //104
    int maxDepth(TreeNode* root) 
    {

        if(NULL == root)
            return 0;

        return 1+ max(maxDepth(root->left), maxDepth(root->right));
    }

    //226
    TreeNode* invertTree(TreeNode* root) 
    {
        if(NULL == root)
            return NULL;
        
        TreeNode* left = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(left);

        return root;

    }

    //112
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(NULL == root)
            return false;
        if(root->right == NULL && root->left == NULL)
            return sum == root->val;
        
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);

    }

    //257
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
        if(NULL == root)
            return res;
        
        if(root->right == NULL && root->left == NULL)
        {
            res.push_back(to_string(root->val));
            return res;
        }
        vector<string> left = binaryTreePaths(root->left);
        for(int i=0;i<left.size(); i++)
            res.push_back(to_string(root->val) + "->" + left[i]  );

        vector<string> right = binaryTreePaths(root->right);
        for(int i=0;i<right.size(); i++)
            res.push_back(to_string(root->val)  + "->" + right[i]  ); 

        return res;

    }

    //437
    int pathSum(TreeNode* root, int sum) 
    {
        if(NULL == root)
            return 0;
        
        return findPath(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);

    }

    //235
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(NULL == root)
            return NULL;
        
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }

private:
    int findPath(TreeNode* root, int sum)
    {
        if(root ==NULL)
            return 0;
        int res = 0;
        if(root->val == sum)
            res+=1;
        
        res += findPath(root->left, sum - root->val);
        res += findPath(root->right, sum - root->val);

        return res;
    }
};


int main()
{



    return 0;
}