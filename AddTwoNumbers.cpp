/**
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//this solution solves digits in order, time complexity is O(n) and splace complexity is O(n) 
class Solution {
public:
    ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
        int jinwei = 0;
        ListNode * ret, * head;
        head = addTwoNumbersRecursive(l1, l2, jinwei);
        if (jinwei) {
            ret = new ListNode(jinwei);
            ret->next = head;
        } else {
            ret = head;
        }
        return ret;
    }
    
    ListNode * addTwoNumbersRecursive(ListNode * l1, ListNode * l2, int & jinwei) {
        //ladd = (l1 + l2) / 10
        //返回是否进位：1，进位；0，不进位
        if (l1 == NULL || l2 == NULL) {
            return l1 == NULL ? l2 : l1;
        }
        
        
        ListNode * next = addTwoNumbersRecursive(l1->next, l2->next, jinwei);
        ListNode * head = new ListNode((l1->val + l2->val + jinwei) % 10);
        head->next = next;
        jinwei = (l1->val + l2->val + jinwei) / 10;
        return head;
    }
};

//this is the corresponding solution. time complexity is O(n), space complexity is O(n)
class Solution {
public:
    ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ret = new ListNode((l1->val + l2->val)%10);
        int jinwei = (l1->val + l2->val) / 10;
        ret->next = addTwoNumbers(l1->next, l2->next, jinwei);
        return ret;
    }
    
    ListNode * addTwoNumbers(ListNode * l1, ListNode * l2, int jinwei) {
        if (l1 == NULL && l2 == NULL) {
            if (jinwei) {
                return new ListNode(jinwei);
            } else {
                return NULL;
            }
        } else if (l1 == NULL || l2 == NULL) {
            ListNode * lval = l1 == NULL ? l2 : l1;
            ListNode * lnull = l1 == NULL ? l1 : l2;
            ListNode * ret = new ListNode((lval->val + jinwei)%10);
            jinwei = (lval->val + jinwei) / 10;
            ret->next = addTwoNumbers(lnull, lval->next, jinwei);
            return ret;
        }
        
        ListNode * ret = new ListNode((l1->val + l2->val + jinwei)%10);
        jinwei = (l1->val + l2->val + jinwei)/10;
        ret->next = addTwoNumbers(l1->next, l2->next, jinwei);
        
        return ret;
    }
};
