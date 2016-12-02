#include <iostream>

//Nodes and lists use public data members for convenience
//This may make some software engineers froth at the mouth

class Node
{
public:
  int value; //This could really be any type
  Node* next;
  Node* prev;
  Node(int val){
    std::cout << "Node constructor!" << std::endl;
    this->value=val;
    this->next=(Node*)0;
    this->prev=(Node*)0;
  }
  ~Node(){
    std::cout << "Node destructor" << std::endl;
    std::cout << "I had the value "<<this->value << std::endl;
  }
};

class List
{

public:
  Node* head;
  Node* tail;

  List(){
    std::cout << "List Constructor!" << std::endl;
    this->head=0;
    this->tail=0;
  }
  ~List(){
    std::cout << "List destructor!" << std::endl;
  }
  void insert(Node* n, Node* x){
    //Not actually perfect: how do we prepend to an existing list?
    if (n!=0){
      x->next=n->next;
      n->next=x;
      x->prev=n;
      if (x->next!=0)
        x->next->prev=x;
    }
    if (this->head==0){
      this->head=x;
      this->tail=x;
      x->prev=0;
      x->next=0;
    }else if (this->tail==n){
      this->tail=x;
    }
  }
  // My added node delete method
  void remove(Node* n)
  {
      /*
      Method to remove a node from the list.
      Uses pointers to find where the next and previous nodes are addressed
      Complexity: O(1) no loops, extra functions or recursion used.
      */

      // -> is used as a dereference the pointer and use the member variable

      //if the node is not the first node
      if (n->prev != 0)
      {
          //change the previous nodes next pointer to the next nodes address
          n->prev->next = n->next;
      }
      else
      {
          //make the next node the first node in the list
          this->head = n->next;
      }

      //if the node is not the last node
      if (n->next != 0)
      {
          //change the next nodes previous pointer to the previous nodes address
          n->next->prev = n->prev;
      }
      else
      {
          //make the previous node the last node in the list
          this->tail = n->prev;
      }
      delete n;
  }

  void display(){
    Node* i=this->head;
    std::cout << "List: " ;
    while(i!=0){
      std::cout << i->value << ",";
      i=i->next;
    }
    std::cout << std::endl;
  }
};

void task2()
{
  List* l=new List();
  l->insert(0,new Node(4));
  l->insert(l->head,new Node(6));
  l->insert(l->head,new Node(8));
  l->display();
  //Added to test deletion of a node
  l->remove(l->tail);
  l->display();
  l->remove(l->tail);
  l->display();
  delete l;
}
