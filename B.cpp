#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x7fffffff;
const int maxn = 2e5+7;
int a[maxn];

typedef struct Node
{
    int data;
    struct Node* pNext;
}NODE;


NODE* Create()
{
    NODE* head;
    head=(NODE*)malloc(1*sizeof(int));
    head->pNext=NULL;
    return head;
}

NODE* Add_Node(NODE* head,int power)
{
    NODE* ptr=head;
    NODE* node;
    while(ptr->pNext!=NULL)
        {
            ptr=ptr->pNext;
        }
    node=(NODE*)malloc(1*sizeof(int));
    node->data=power;
    node->pNext=NULL;
    ptr->pNext=node;
}

void Print_LinkList(NODE* head)
{
    NODE* ptr=head;
    while(ptr->pNext!=NULL)
    {
        ptr=ptr->pNext;
        cout<<ptr->data<<" ";
    }
}


int Length_LinkList(NODE* head)
{
    int length=0;
    NODE* ptr=head;
    while(ptr->pNext!=NULL)
    {
        ptr=ptr->pNext;
        length++;
    }
    return length;
}

int Is_Winner(NODE* head,int time,int length)
{
    int count=0;
    NODE* ptr=head->pNext;
    NODE* tail=head;
    NODE* ptrNext;
    while(tail->pNext!=NULL)
    {
        tail=tail->pNext;
    }
    while(count<time)
    {
        ptrNext=ptr->pNext;
        if(ptr->data>=ptrNext->data)
        {
            count++;
            if(count>=length)
            {
                break;
            }
            if(ptrNext->pNext!=NULL)
            {
                ptr->pNext=ptrNext->pNext;
                ptrNext->pNext=NULL;
                tail->pNext=ptrNext;
                tail=ptrNext;
            }

        }
        else
        {
            count=0;
            head->pNext=ptrNext;
            ptr->pNext=NULL;
            tail->pNext=ptr;
            tail=ptr;
            ptr=ptrNext;
        }
    }
    return ptr->data;
}


int main()
{
    int num_person;
    ll win_time;
    int power;
    int winner;
    NODE* head=Create();
    cin>>num_person;
    cin>>win_time;
    for(int i=1;i<=num_person;i++)
    {
            cin>>power;
            Add_Node(head,power);
    }
    int length=Length_LinkList(head);
    winner=Is_Winner(head,win_time,length);
    cout<<winner;
    return 0;
}
