#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1e9+7;
#define take_input freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
class linked_list{
public:
    ll data;
    linked_list *next;
    linked_list(){
        this->next = NULL;
    }
    linked_list(ll data){
        this->data = data;
        this->next = NULL;
    }
    linked_list *add(ll data,linked_list *head){
        if(head == NULL){
            linked_list *temp = new linked_list(data);
            head = temp;
        } else{
            linked_list *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new linked_list(data);
        }
        return head;
    }
    void print(linked_list *head){
        linked_list *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    ll middleElement(linked_list *head){
        linked_list *fastptr = head;
        linked_list *slowptr = head;
        while(fastptr != NULL && fastptr->next != NULL){
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        return slowptr->data;
    }
    void deleteMiddle(linked_list *head){
        linked_list *fastptr = head;
        linked_list *slowptr = head;
        linked_list *pre;
        while(fastptr != NULL && fastptr->next != NULL){
            pre = slowptr;
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        pre->next = slowptr->next;
        delete slowptr;
    }
    linked_list *deleteLL(linked_list *head){
        linked_list *pre = head;
        head = head->next;
        if(head == NULL){
            delete pre;
        }
        while(head!=NULL){
            delete pre;
            pre=head;
            head=head->next;
        }
        return head;
    }
};
int main(){
    linked_list *head = NULL;
    head = head->add(1,head);
    head = head->add(2,head);
    head = head->add(3,head);
    head = head->add(4,head);
    head = head->add(5,head);
    if(head != NULL){
        head->print(head);
    } else{
        cout<<"Linked List is empty"<<endl;
    }
    head = head->deleteLL(head);
    if(head != NULL){
        cout<<head<<endl;
    } else{
        cout<<"Linked List is empty"<<endl;
    }
}