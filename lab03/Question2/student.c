#include "student.h"
#include <stddef.h>

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode* newHead = head->next;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL && curr->next != NULL) {
        struct ListNode* next = curr->next;
        struct ListNode* nextPair = next->next;

        next->next = curr;
        curr->next = nextPair;

        if (prev != NULL) {
            prev->next = next;
        }

        prev = curr;
        curr = nextPair;
    }

    return newHead;
}