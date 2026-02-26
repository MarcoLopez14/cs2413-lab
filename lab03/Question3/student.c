#include "student.h"
#include <stddef.h>

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode* newHead = head->next;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr && curr->next) {
        struct ListNode* second = curr->next;

        curr->next = second->next;
        second->next = curr;

        if (prev) prev->next = second;

        prev = curr;
        curr = curr->next;
    }

    return newHead;
}