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
#include "utils.hpp"
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

/* 
设P点经过的总路程为S
则在带环的链表中，P点实际坐标为
Pos(P) = (S - m) % C + m
其中m为非环的长度，C为环的长度
 */
