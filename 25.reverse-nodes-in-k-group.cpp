/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0 || k == 1) {
            return head;
        }

        // 检查剩余的Node数目是否小于k，if yes, return head directly;
        // 同时找到本组的尾指针
        ListNode* pTail = head;
        for(int i = 1; i < k; i++) {
            if(pTail->next == nullptr) {
                return head;
            }

            pTail = pTail->next;
        }
        // 保存下一组Node的首地址
        auto pTailNext = reverseKGroup(pTail->next, k);

        // Reverse 本组的Node
        ListNode* prev = head;
        ListNode* pCur = head->next;
        for(int i = 1; i < k; i++) {
            ListNode* tmp = pCur->next;
            pCur->next = prev;

            prev = pCur;
            pCur = tmp;
        }

        // 将本组的结尾指向下一组的首地址
        head->next = pTailNext;
        return pTail;
    }
};
// @lc code=end

