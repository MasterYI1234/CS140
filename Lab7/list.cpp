#include <iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
#include <cstring>
#include <stdio.h>
#include <string.h>


#include "list.h"

using namespace std;


List::List(){
carry = 0;
    l1= new node;
    l1->next = NULL;
    l2 = new node;
    l2->next = NULL;
}

void List::makelistl1(int c){
   node *newNode, *i;
i = l1;

while(i->next != NULL)
        i = i->next;
        newNode = new node;
        newNode->data = c;
        newNode->next = NULL;
        i->next = newNode;

}

void List::makelistl2(int c){
   node *newNode, *i;
i = l2;

while(i->next != NULL)
        i = i->next;
        newNode = new node;
        newNode->data = c;
        newNode->next = NULL;
        i->next = newNode;

}


void List::getsum(){
     node * head = NULL;
      head = new node();
       node * newhead;
       node * savehead = head;
  // Make a loop, ending with the two linked list pointers p and q coming to the end
  while (l1->next != NULL || l2->next != NULL) {
    int x = l1->data;
    int y = l2->data;
    // calculate the sum
    int sum = carry + x + y;
    // Calculate carry
    carry = sum / 10;
    // Construct a new node to store the calculated digit value
    newhead = new node();
    newhead->data = sum % 10;
    head->next = newhead;
    head = head->next;
    if (l1->next != NULL)
      l1 = l1->next;
    if (l2->next != NULL)
      l2 = l2->next;
  }
  // Handle the carry case at the end of the most significant bit of the number
  if (carry > 0) {
    newhead = new node();
    head->next = newhead;
    newhead->data = carry;
    newhead->next = NULL;
  }

node * ptr = savehead;
while(ptr != NULL){
    cout<<ptr->data<<endl;
     ptr = ptr->next;
}

}
