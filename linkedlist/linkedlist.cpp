#include "linkedlist.h"
#include <iostream>

void Print(){
    list_node *head = NULL;
    list_node *cur = NULL;
    for(cur = head; cur != NULL; cur = cur-> link){
        cout << cur->data << end;
    }
}

bool Retrieve(char data){
    list_node *head = NULL;
    list_node *cur = NULL;
    for(cur = head; cur != NULL; cur = cur->link){
        if(cur -> data == data)
            break; //found
    }
    // if cur != NULL, found!
}

list_node* Retrieve(int index){
    list_node *head = NULL;
    int i;
    list_node *cur = NULL;
    for(cur = head, i=0; cur != NULL, i<index; cur = cur->link, i++),
    //for loop안에 종료조건과 내용까지 포함되어서 for(),형태로 마무리
    //if cur != NULL, n-th node is found
    //index가 node의 개수보다 많을 경우 더 찾을 수 없기에 cur!=NULL이 종료조건으로 &&같이 묶여 있어야 함    
}
