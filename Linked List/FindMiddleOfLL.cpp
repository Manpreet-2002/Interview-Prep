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
};
int main(){
    linked_list *head = NULL;
    head = head->add(1,head);
    head = head->add(2,head);
    head = head->add(3,head);
    head = head->add(4,head);
    head = head->add(5,head);
    cout<<head->middleElement(head)<<endl;
}