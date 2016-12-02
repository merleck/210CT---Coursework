#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class BinTreeNode{
public:
  BinTreeNode(int value){
    this->value=value;
    this->left=NULL;
    this->right=NULL;
  }
  ~BinTreeNode()
  {
      //cout << "node deleted" << endl;
  }
  int value;
  BinTreeNode* left;
  BinTreeNode* right;

};

BinTreeNode* tree_insert(BinTreeNode* tree, int item){
  if(tree==NULL)
    tree=new BinTreeNode(item);
  else
    if(item < tree->value)
      if(tree->left==NULL)
        tree->left=new BinTreeNode(item);
      else
        tree_insert(tree->left,item);
    else
      if(tree->right==NULL)
        tree->right=new BinTreeNode(item);
      else
        tree_insert(tree->right,item);
  return tree;

}

void empty_tree(BinTreeNode* tree){

    /*
    Function to recursively delete all nodes in the tree
    */

    if (tree != NULL)
    {
        empty_tree(tree->left);
        empty_tree(tree->right);
        delete tree;
    }
}


// Original Iterative in_order function
//void in_order(BinTreeNode* tree){
//  if(tree->left!=NULL)
//    in_order(tree->left);
//  cout << tree->value << endl;
//  if(tree->right!=NULL)
//    in_order(tree->right);
//}


//My added Iterative in_order function
void in_order(BinTreeNode* tree)
{
    /*
    A function that takes in a root node of a tree and
    outputs the elements in the tree using the
    inOrder traversal order.
    Complexity: O(n) due to while loop
    */

    //keep track of current node
    BinTreeNode* current = tree;

    //start the stack we need to store the elements.
    stack<BinTreeNode> inOrderStack;

    //shows when tree is fully traversed
    bool done = false;

    //if tree is not finished
    while (!done) // O(n)
    {
        //if node is not empty
        if (current != NULL)
        {
            //store current in stack and move down left subtree
            inOrderStack.push(*current);
            current = current->left;
        }
        //if it is empty and there are elements in the stack left
        else if (!inOrderStack.empty())
        {
            //Store the top stack element and then remove it from stack
            //print the value of the stored node. Start moving down right
            //subtree
            current = &inOrderStack.top();
            inOrderStack.pop();
            cout << current->value << endl;
            current = current->right;
        }
        else //current is null and nothing is in the stack
        {
            //tree is finished
            done = true;
            delete current;
        }
    }
}

void tree_sort(vector<int> input)
{
    /*
    A function that takes in a vector sequence and inserts the elements
    into a tree structure and then outputs the sorted order of the elements.
    Complexity is O(n^2) in the worst case, O(n log n) in the average case.
    */

    //Initialise the root node with the first element
    BinTreeNode* t = tree_insert(0, input[0]);

    for(int i = 1; i<input.size(); i++) //O(n)
    {
        //insert every element into the tree
        tree_insert(t, input[i]); //O(n) worst case O(log n) average case
    }
    //print the sorted order
    in_order(t); //O(n)

    empty_tree(t); //delete all the node in the tree (deal with mem leaks)

    delete t;
}

int main()
{
    BinTreeNode* t=tree_insert(0,6);
    tree_insert(t,10);
    tree_insert(t,5);
    tree_insert(t,2);
    tree_insert(t,3);
    tree_insert(t,4);
    tree_insert(t,11);
    in_order(t);
    empty_tree(t);
    delete t;

    cout << endl;

    vector<int> unsortedVector;
    unsortedVector.push_back(6);
    unsortedVector.push_back(10);
    unsortedVector.push_back(5);
    unsortedVector.push_back(2);
    unsortedVector.push_back(3);
    unsortedVector.push_back(4);
    unsortedVector.push_back(11);

    tree_sort(unsortedVector);

    return 0;
}
