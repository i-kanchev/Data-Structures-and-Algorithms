// https://www.hackerrank.com/contests/sda-hw-4-2022/challenges/delete-a-node-from-a-linked-list

/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if (position == 0)
    {
        if (llist->next == nullptr)
        {
            delete llist;
            return nullptr;
        }
        
        SinglyLinkedListNode* toDelete = llist;
        llist = llist->next;
        
        delete toDelete;
    }
    else
    {
        int counter = 1;
        SinglyLinkedListNode* temp = llist;
        
        while (temp->next != nullptr)
        {
            if (counter++ == position)
            {
                SinglyLinkedListNode* toDelete = temp->next;
                temp->next = toDelete->next;
                
                
                delete toDelete;
                continue;
            }
            temp = temp->next;
        }
    }
    
    return llist;
}