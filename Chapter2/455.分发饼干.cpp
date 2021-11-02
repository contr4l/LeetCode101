/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#ifdef LC_TEST
#include "utils.hpp"
#else
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#endif

class Solution {
public:
    int findContentChildren( vector< int >& g, vector< int >& s ) {
        sort( g.begin(), g.end() );
        sort( s.begin(), s.end() );
        int idx_g = 0, idx_s = 0;
        int g_size = g.size();
        int s_size = s.size();
        while ( idx_s < s_size ) {
            if ( s[ idx_s ] >= g[ idx_g ] ) {
#ifdef LC_TEST
                printf( "s %d gives to g %d.\n", s[ idx_s ], g[ idx_g ] );
#endif
                idx_g++;
            }
            idx_s++;
            if ( idx_g == g_size )
                break;
        }
#ifdef LC_TEST
        cout << "res = " << idx_g << endl;
#endif
        return idx_g;
    }
};

#ifdef LC_TEST
int main() {
    Solution      A;
    vector< int > g{ 1, 2, 5, 4, 3 };
    vector< int > s{ 1, 2, 7, 7, 1 };
    A.findContentChildren( g, s );
    return 0;
}
#endif
// @lc code=end
