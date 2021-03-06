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
    void printReverse(linked_list *head){
        if(head==NULL){
            return;
        }
        printReverse(head->next);
        cout<<head->data<<" ";
    }
    linked_list *reverseLL(linked_list *head){
        linked_list *prev = NULL;
        linked_list *curr = head;
        linked_list *post = head;
        while(curr){
            post = curr->next;
            curr->next=prev;
            prev = curr;
            curr = post;
        }
        return prev;
    }
    bool isPalindrome(linked_list* &left, linked_list* right){
        if(right == NULL){
            return true; //coz best case mein true hona chahiye
        }
        bool first = isPalindrome(left,right->next);
        bool second = (left->data == right->data);
        left=left->next;
        return second;
    }
    auto removeDuplicatesSorted(linked_list *head){
        linked_list *curr = head;
        while(curr->next != NULL){
            if(curr->data == curr->next->data){
                linked_list *temp = curr->next;
                curr->next = temp->next;
                delete temp;
            } else{
                curr = curr->next;
            }
        }
        return head;
    }
    auto removeDuplicateUnsorted(linked_list *head){
        unordered_set<int> visited;
        auto curr = head;
        auto prev = head;
        visited.insert(curr->data);
        curr = curr->next;
        while(curr){
            if(visited.count(curr->data)){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else{
                visited.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
    bool detectLoop(linked_list *head){
        auto fastptr = head;
        auto slowptr = head;
        while(fastptr!=NULL && fastptr->next!=NULL){
            fastptr=fastptr->next->next;
            slowptr=slowptr->next;
            if(fastptr == slowptr){
                return true;
            }
        }
        return false;
    }
    linked_list *deleteLoop(linked_list *head){
        auto fastptr = head;
        auto slowptr = head;
        while(fastptr!=NULL && fastptr->next!=NULL){
            fastptr=fastptr->next->next;
            slowptr=slowptr->next;
            if(fastptr == slowptr){
                break;
            }
        }
        if(slowptr == fastptr){
            slowptr = head;
            while(slowptr->next != fastptr->next){
                slowptr=slowptr->next;
                fastptr=fastptr->next;
            }
            fastptr->next=NULL;
        }
        return head;
    }
    ll intersectionPoint(linked_list *head1, linked_list *head2){
        auto curr1 = head1;
        auto curr2 = head2;
        while(curr1 != curr2){
            if(curr1 != NULL){
                curr1 = curr1->next;
            }
            if(curr1 == NULL){
                curr1 = head2;
            }
            if(curr2 != NULL){
                curr2 = curr2->next;
            }
            if(curr2 == NULL){
                curr2 = head1;
            }
        }
        return curr1->data;
    }
};
int main(){
    linked_list *head = NULL;
    head = head->add(1,head);
    head = head->add(2,head);
    head = head->add(3,head);
    head = head->add(4,head);
    head = head->add(5,head);
    auto curr = head;
    auto temp = head;
    while(curr->next){
        curr=curr->next;
    }
    while(temp->data != 2){
        temp = temp->next;
    }
    curr->next = temp;
    cout<<head->detectLoop(head)<<endl;
    head = head->deleteLoop(head);
    cout<<head->detectLoop(head)<<endl;
}