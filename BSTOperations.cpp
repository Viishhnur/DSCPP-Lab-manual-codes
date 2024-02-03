#include<iostream>
#include<queue>
using namespace std;
#include "Node.cpp"

Node* insertToBST(int data ,Node* &root){

    if(!root){

        // Now insert here 
        root = new Node(data);
        return root;

    }

    if(data < root->val){
        // Go left and insert 
        root->left = insertToBST(data,root->left);
    }

    else{
        // Go right and insert 
        root->right = insertToBST(data,root->right);
    }

    return root;



}
void takeInput(Node* &root){
    int data;
    cout << "Enter data : " ;
    cin >> data ;
    while(data!=-1){
        root = insertToBST(data,root);
        cin >> data;
    }
}

void printBST(Node* root){

    if(!root) return;
    queue<Node*>qu; 
    qu.push(root);

    while(!qu.empty()){
        int queueSize = qu.size();

        for(int i=0;i<queueSize;i++){
            Node* Front = qu.front();
            qu.pop();
            if(Front->left) qu.push(Front->left);
            if(Front->right) qu.push(Front->right);
            cout << Front->val << " " ;
        }
        cout << endl;
            
       
    }

}

bool searchInBST(Node* root,int data){

    while(!root){

        if(root->val == data) return true;

        if(data < root->val){
            // Go left and search
            root = root->left;
        }
        else{
            root = root->right;
        }


    }

    return false;
}

Node* Delete(Node *curr, int val)
{
    // The base case
    if (curr == NULL)
    {
        return curr;
    }
    // Left Child
    if (val < curr->val)
    {
        curr->left = Delete(curr->left, val);
        return curr;
    }
    // Right Child
    else if (val > curr->val)
    {
        curr->right = Delete(curr->right, val);
        return curr;
    }

    // Now, we've reached to the node which we want to delete.
    // Our task is to check whether it has 0 or 1 or 2 children.

    // If it has 0 or 1 child :

    if (curr->left == NULL)
    {
        Node *temp = curr->right;
        delete curr;
        return temp;
    }
    else if (curr->right == NULL)
    {
        Node *temp = curr->left;
        delete curr;
        return temp;
    }

    // Inorder Predecessor : Largest element in Left Subtree of the Current Node
    // Inorder Successor   : Smallest element in Right Subtree of the current Node
    // Or else if the node has 2 children :
    // Find its Inorder Successor
    // Copy the data of inorder successor and delete it
    // Replace the curr node's data with Inorder successor's data (that you've copied earlier)
    else
    {
        Node *tempParent = curr;
        Node *temp = curr->right;
        while (temp->left != NULL)
        {
            tempParent = temp;
            temp = temp->left;
        }
        int data = temp->val;
        delete temp;
        tempParent->left = NULL;
        curr->val = data;
        return curr;
    }
}
int main(){

    Node* root = NULL;
    takeInput(root);
    printBST(root);

    return 0;
}
