// https://www.hackerrank.com/contests/sda-hw-4-2022/challenges/insert-a-node-at-a-specific-position-in-a-linked-list

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {    
    int counter = 1;
    SinglyLinkedListNode* temp = llist;
    
    while (temp->next != nullptr)
    {
        if (counter == position)
        {
            SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        counter++;
        
        cout << temp->data << ' ';
        temp = temp->next;
    }
    
    return llist;
}