#include "definitions.h"
#include <iostream>
void printList(ListNode *head) {
  ListNode *itr = head;
  std::cout << "[ ";
  while (itr != nullptr) {
    std::cout << itr->val << " ";
    itr = itr->next;
  }
  std::cout << "]\n";
}
