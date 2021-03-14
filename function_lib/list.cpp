#include "list.h"

void LinkedList::print()
{
    struct Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void LinkedList::push_back(int data)
{
	if (head == nullptr)
		head = new Node(data);
	else
	{
		Node* current = this->head;
		while (current->next != nullptr)
			current = current->next;
		current->next = new Node(data);
	};
}

bool LinkedList::find_loop_floyd()
{
    Node* slow = head;
    Node* fast = head;

    while (slow && fast && fast->next) {
        
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

bool LinkedList::find_loop_reverse()
{
    Node* current = head;
    Node* prev = nullptr, * next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;

        if (next != head)
            current = next;
        else
        {
            current = next;
            head->next = prev;

            prev = nullptr, next = nullptr;

            while (current != nullptr)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            head = prev;

            return true;
        }
    }
    head = prev;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    return false;
}
