//
//  main.cpp
//  MiddleOfTheLinkedList
//
//  Created by Aj Gill on 8/2/19.
//  Copyright © 2019 Aj Gill. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

class LList{
private:
    //Represents each node in the LL
    struct ListNode{
        int data;
        ListNode* next;
    };
    typedef struct ListNode* nodePtr;
    nodePtr head, current, temp;
    
public:
    LList(){
        head = NULL;
        current = NULL;
        temp = NULL;
    };
    void Insert(int addData) {
        nodePtr n = new ListNode;
        n->next = NULL;
        n->data = addData;
        if(head != NULL){
            current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = n;
        }
        else{
            head = n;
        }
    };
    
    void Remove(int removeData) {
        nodePtr delPtr = NULL;
        temp = head;
        current = head;
        while(current != NULL && current->data != removeData){
            temp = current;
            current = current->next;
        }
        if(current == NULL){
            cout << removeData << " was not in the list\n";
            delete delPtr;
        }
        else{
            delPtr = current;
            current = current->next;
            temp->next = current;
            if(delPtr == head){
                head = head->next;
                temp = NULL;
            }
            delete delPtr;
            cout << "The value " << removeData << " was deleted\n";
        }
    };
    
    void PrintList() {
        current = head;
        while(current != NULL){
            cout << current->data << " - ";
            current = current->next;
        }
        cout << "\n";
    };
    
    void PrintMiddle() {
        int middle = middleNode(head)->data;
        cout << "Middle node is " << middle << "\n";
    }
    
    LList::ListNode* middleNode(LList::ListNode* head) {
        LList::ListNode* fastPtr = head;
        LList::ListNode* slowPtr = head;
        while(fastPtr->next != NULL){
            fastPtr = fastPtr->next;
            if(fastPtr->next != NULL){
                fastPtr = fastPtr->next;
            }
            slowPtr = slowPtr->next;
        }
        return slowPtr;
    };
};


int main() {
    LList Aj;
    Aj.Insert(1);
    Aj.Insert(2);
    Aj.Insert(3);
    Aj.Insert(4);
    Aj.Insert(5);
    Aj.Insert(6);
    Aj.Insert(7);
    Aj.Insert(8);
    Aj.Insert(9);
    Aj.Insert(10);
    Aj.PrintList();
    Aj.PrintMiddle();
}
