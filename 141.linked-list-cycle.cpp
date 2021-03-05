/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

// Solution1: 暴力法，一开始就应该想的到
// #include <set>

// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         std::set<ListNode*> usedSet;
//         for(auto ptr = head; ptr != nullptr; ) {
//             if(usedSet.find(ptr) != usedSet.end()) {
//                 return true;
//             }

//             usedSet.insert(ptr);
//             ptr = ptr->next;
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto fp = head;
        auto sp = head;
        while(fp != nullptr && fp->next != nullptr) {
            fp = fp->next->next;
            sp = sp->next;

            if(fp == sp) {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

