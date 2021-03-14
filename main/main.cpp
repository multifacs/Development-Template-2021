#include <iostream>
#include "list.h"

int main()
{
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    ll.head->next->next->next->next->next = ll.head->next->next;

    //cout << "Given linked list\n";
    //ll.print();

    cout << "\nLoop decetion algorithm number 1 \n";
    if (ll.find_loop_floyd())
        cout << "Loop found\n";
    else
        cout << "Loop not found\n";

    cout << "\nLoop decetion algorithm number 2 \n";
    if (ll.find_loop_reverse())
        cout << "Loop found\n";
    else
        cout << "Loop not found\n";

    return 0;
}