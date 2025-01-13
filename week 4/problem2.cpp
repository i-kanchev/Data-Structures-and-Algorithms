// https://www.hackerrank.com/contests/sda-hw-4-2022/challenges/find-the-merge-point-of-two-joined-linked-lists

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* step1 = head1;
    SinglyLinkedListNode* step2 = head2;
    
    while (step1 != step2)
    {
        if (step1->next != nullptr)
            step1 = step1->next;
        else
        {
            step1 = head1;
            step2 = step2->next;
        }
    }
    
    
    return step1->data;
}