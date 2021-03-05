/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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

// Solution1: Iterative  solution
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == nullptr || head->next == nullptr) {
//             return head;
//         }

//         auto prePtr, curPtr = head, head->next;
//         head->next = nullptr
//         while(curPtr != nullptr) {
//             auto nextPtr = curPtr->next;
//             curPtr->next = prePtr;

//             prePtr = curPtr;
//             curPtr = nextPtr;
//         }

//         return curPtr;
//     }
// };

// Solution2: Recursive solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next ==nullptr) {
            return head;
        }

        auto node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return node;
    }
};
// @lc code=end

