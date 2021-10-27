/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        int cnt = 0;
        while (fast) {
            fast = fast->next;
            if (!fast){
                return NULL;
            }
            fast = fast->next;
            slow = slow->next;
            cnt++;
            if (fast == slow) break;
        }
        if (!fast) return NULL;
        // printf("cnt = %d.\n", cnt);
        slow = head;
        while (fast!=slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end

