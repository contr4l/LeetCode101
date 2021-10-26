/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
#ifndef LC_TEST
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#else
#include "utils.h"
#endif
// @lc code=start
bool start_cmp(vector< int >& a, vector< int >& b) {
    if (a[0] > b[0]) {
        return true;
    }
    else if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return false;
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), start_cmp);
        vector<vector<int>> queue;
        queue.push_back(people[0]);
        #ifdef LC_TEST
        print_vec_vec(people);
        #endif
        for (int i = 1; i < people.size(); i++)
        {
            queue.insert(queue.begin()+people[i][1], people[i]);
        }
        #ifdef LC_TEST
        print_vec_vec(queue);
        #endif
        
        return queue;
    }
};
// @lc code=end

#ifdef LC_TEST
int main()
{
    
    vector< vector< int > > g{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution A;
    // print_vec_vec(g);
    A.reconstructQueue(g);
    return 0;
}
#endif
