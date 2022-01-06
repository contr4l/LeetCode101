/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#ifndef LC_TEST
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#else
#include "utils.hpp"
#endif
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<string>& res, string tmp)
    {
        if (!root)
            return;
        if (tmp.length())
            tmp.append("->");
        tmp.append(to_string(root->val));
        if (!root->left && !root->right)
        {
            res.push_back(tmp);
            return;
        }
        dfs(root->left, res, tmp);
        dfs(root->right, res, tmp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string tmp;
        dfs(root, res, tmp);
        return res;
    }
};
// @lc code=end

