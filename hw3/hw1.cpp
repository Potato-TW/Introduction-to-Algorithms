#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer
to left   child and a pointer to right
child */
struct Node
{
  int data;
  Node *left, *right;
  Node(int x)
  {
    data = x;
    left = right = NULL;
  }
};
 
/*Tree building function*/
Node *buildTree(int in[], int post[], int n)
{
 
  // Create Stack of type Node*
  stack<Node*> st;
 
  // Create Set of type Node*
  set<Node*> s;
 
  // Initialise postIndex with n - 1
  int postIndex = n - 1;
 
  // Initialise root with NULL
  Node* root = NULL;
 
  for (int p = n - 1, i = n - 1; p>=0;) 
  {
 
    // Initialise node with NULL
    Node* node = NULL;
     
    // Run do-while loop
    do
    {
 
      // Initialise node with
      // new Node(post[p]);
      node = new Node(post[p]);
 
      // Check is root is
      // equal to NULL
      if (root == NULL)
      {
        root = node;
      }
       
      // If size of set
      // is greater than 0
      if (st.size() > 0) 
      {
         
        // If st.top() is present in the
        // set s
        if (s.find(st.top()) != s.end())
        {
          s.erase(st.top());
          st.top()->left = node;
          st.pop();
        }
        else
        {
          st.top()->right = node;
        }
      }
       
      st.push(node);
       
    } while (post[p--] != in[i] && p >=0);
 
    node = NULL;
     
    // If the stack is not empty and
    // st.top()->data is equal to in[i]
    while (st.size() > 0 && i>=0 && 
           st.top()->data == in[i]) 
    {
      node = st.top();
       
      // Pop elements from stack
      st.pop();
      i--;
    }
     
    // if node not equal to NULL
    if (node != NULL) 
    {
      s.insert(node);
      st.push(node);
    }
  }
   
  // Return root
  return root;
 
}

// Driver Code
int main()
{
 
  int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
  int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
  int n = sizeof(in) / sizeof(in[0]);
 
  // Function Call
  Node* root = buildTree(in, post, n);
 
  cout << "Preorder of the constructed tree : \n";
 
  // Function Call for preOrder
  preOrder(root);
  return 0;
}