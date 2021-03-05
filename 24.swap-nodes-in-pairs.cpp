/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// Solution1: swap the value.
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         auto ptr = head;
//         for(ptr != nullptr && ptr->next != null) {
//             auto tmp = ptr->val;
//             ptr->val = ptr->next->val;
//             ptr->next->val = tmp;

//             ptr = ptr->next->next;
//         }
//     }

//     return head;
// };

// Solution2: Swap nodes
// #include <iostream>
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(head == nullptr || head->next == nullptr) {
//             return head;
//         }

//         auto ptr = head;
//         auto newHead = head->next;
//         // 需要注意prePtr， pnextnext应该在交换的区域之外，不应该参与当前的交换
//         ListNode* prePtr = nullptr;
//         while(ptr != nullptr && ptr->next != nullptr) {
//             auto pnextnext = ptr->next->next;
//             auto pnext = ptr->next;

//             ptr->next = pnextnext;
//             pnext->next = ptr;
//             if(prePtr != nullptr) {
//                 prePtr->next = pnext;
//             }

//             prePtr = ptr;
//             ptr = pnextnext;
//         }

//         return newHead;
//     }
// };

// Solution3: 递归解法
#include <iostream>
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;    
        }

        auto node = swapPairs(head->next->next);
        auto newHead = head->next;
        head->next->next = head;
        head->next = node;

        return newHead;
    }
};

// @lc code=end

