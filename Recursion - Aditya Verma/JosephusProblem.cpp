#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class linked_list
{
public:
    ll data;
    linked_list *next;
    linked_list()
    {
        this->next = NULL;
    }
    linked_list(ll data)
    {
        this->data = data;
        this->next = NULL;
    }
    linked_list *add(ll data, linked_list *head)
    {
        if (head == NULL)
        {
            linked_list *temp = new linked_list(data);
            head = temp;
        }
        else
        {
            linked_list *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new linked_list(data);
        }
        return head;
    }
    void print(linked_list *head)
    {
        linked_list *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

ll josephus(linked_list *head, linked_list *prev, linked_list *next, int count)
{
    if (head->next == head)
    {
        return head->data;
    }
    if (count == 7)
    {
        prev->next = next;
        delete head;
        head = next;
        next = next->next;
        count = 1;
        josephus(head, prev, next, count);
    }
    else if (count < 7)
    {
        prev = head;
        head = next;
        next = next->next;
        count++;
        josephus(head, prev, next, count);
    }
}

int main()
{
    linked_list *head = NULL;
    head = head->add(1, head);
    head = head->add(2, head);
    head = head->add(3, head);
    head = head->add(4, head);
    head = head->add(5, head);
    head = head->add(6, head);
    head = head->add(7, head);
    head = head->add(8, head);
    head = head->add(9, head);
    head = head->add(10, head);
    head = head->add(11, head);
    head = head->add(12, head);
    head = head->add(13, head);
    head = head->add(14, head);
    head = head->add(15, head);
    head = head->add(16, head);
    head = head->add(17, head);
    head = head->add(18, head);
    head = head->add(19, head);
    head = head->add(20, head);
    head = head->add(21, head);
    head = head->add(22, head);
    head = head->add(23, head);
    head = head->add(24, head);
    head = head->add(25, head);
    head = head->add(26, head);
    head = head->add(27, head);
    head = head->add(28, head);
    head = head->add(29, head);
    head = head->add(30, head);
    head = head->add(31, head);
    head = head->add(32, head);
    head = head->add(33, head);
    head = head->add(34, head);
    head = head->add(35, head);
    head = head->add(36, head);
    head = head->add(37, head);
    head = head->add(38, head);
    head = head->add(39, head);
    head = head->add(40, head);
    linked_list *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    linked_list *prev = temp;
    linked_list *next = head->next;
    cout << josephus(head, prev, next, 1) << endl;
    return 0;
}