/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */
#include <stdio.h>
#ifndef LC_TEST
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;
#else
#include "utils.hpp"
#endif
// @lc code=start
class Solution {
public:
    vector< int > father;
    int _search(int i){
        while (father[i] != i){
            i = father[i];
            #ifdef LC_TEST
            printf("%d father is %d.\n", i, father[i]);
            #endif
        }
        return i;
    }
    void _union(int i, int j){
        int f_j = _search(j);
        int f_i = _search(i);
        while (father[i] != i){
            int tmp = i;
            i = father[i];
            father[tmp] = f_j;
            #ifdef LC_TEST
            printf("%d father is %d.\n", i, father[i]);
            #endif
        }
        father[i] = f_j;
    }
    int _count(){
        int cnt = 0;
        for (int i=0; i<father.size(); ++i) {
            #ifdef LC_TEST
            printf("%d = %d.\n", i, father[i]);
            #endif
            if (father[i]==i) {
                cnt++;
            }
        }
        return cnt;
    }
    int findCircleNum_union_search(vector<vector<int>>& isConnected) {
        father.resize(isConnected.size());
        for (int i=0; i<father.size(); ++i) {
            father[i]=i;
        }
        for (int i=0; i<father.size(); ++i) {
            for (int j=i+1; j<father.size(); ++j) {
                if(isConnected[i][j]==1){
                    #ifdef LC_TEST
                    printf("%d union %d.\n", i, j);
                    #endif
                    _union(i, j);
                }
            }
        }
        return _count();
    }
    void dfs(int i, vector< vector< int > >& grid, vector< int >& visited) {
        #ifdef LC_TEST
        printf("dfs from %d.\n", i);
        #endif
        int j = 0;
        visited[i] = 1;
        while (j < grid.size()) {
            if (!visited[j] && grid[i][j] == 1) {
                dfs(j, grid, visited);
            }
            j++;
        }
        return;
    }
    int findCircleNum_dfs(vector< vector< int > >& isConnected) {
        int res = 0;
        vector< int > visited(isConnected.size(), 0);
        for (int i = 0; i < isConnected.size(); ++i) {
            if (visited[i] == 0) {
                dfs(i, isConnected, visited);
                res++;
            }
        }
        // printf("res = %d.\n",res);
        return res;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        return findCircleNum_dfs(isConnected);
    }
};
// @lc code=end
int main()
{
    Solution A;
    vector<vector<int>> connect_{{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    A.findCircleNum(connect_);
    return 0;
}