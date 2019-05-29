/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/

#define ListNode Node
class Solution {
public:
    Node* flatten(Node* head, Node* rest = nullptr) {
      if(!head){
        return rest;
      }
      head->next=flatten(head->child,flatten(head->next,rest));
      if(head->next){
        head->next->prev=head;
      }
      head->child=NULL;
      return head;
    }
};
