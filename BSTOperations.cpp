#include<iostream>
#include<queue>
#include "TreeNode.cpp"
using namespace std;



Node*  insertToBST(Node* &root ,int data){
    // Insertion in a BST is  of :- O(logn) Time complexity
    if(root==NULL){
        root = new Node(data);
        return root;
    }

    if(data < root->val){
        // Go to left
        root->left = insertToBST(root->left,data);
        
    }

    else{
        // Go to left
        root->right = insertToBST(root->right,data);
    }

    return root;

}
void takeInput(Node* &root){
    int data;
    cout << "\nEnter data : \n" ;
    cin >> data;

    while(data!=-1){
        root = insertToBST(root,data);
        cin >> data;
    }

    
}

bool searchInBST(Node* root,int val){
    // Avg:- O(logn) worst case O(N) 
    // Space :- O(H)
    if(!root) return false;

    if(val == root->val) return true;

    if(val < root->val){
        // Go and search in left
        return searchInBST(root->left,val);
    }
    if(val > root->val){
        // Go and search in right
        return searchInBST(root->right,val);
    }

    return false;



    
}
void printBST(Node* root){


    if(root==nullptr) return ;

    // Level-Order means --> printing elements level wise 

    queue<Node*> qu;
    qu.push(root);

    while(!qu.empty()){
        
        int queue_Size = qu.size();
        for(int i=0;i<queue_Size;i++){
            Node* Front = qu.front();
            qu.pop();

            if(Front->left) qu.push(Front->left);
            if(Front->right) qu.push(Front->right);
            cout << (Front->val) << " ";

        }
        cout << endl;

    }

    return ;

}

void printInOrder(Node* root){
    if(!root) return;

    printInOrder(root->left);
    cout << root->val << " " ;
    printInOrder(root->right);
}

int getMin(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }

    return temp->val;
}

int getMax(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp->val;
}

int getMinValue(Node* root){
    Node* temp = root;
    int minValue = temp->val;
    while(temp->left!=NULL){
        minValue = temp->left->val;
        temp = temp->left;
    }
    return minValue;
}

Node* deleteNode(Node* &root,int key){
    if(!root) return root;
    if(key < root->val){
        root->left = deleteNode(root->left,key);
    }
    else if(key > root->val){
        root->right = deleteNode(root->right,key);
    }
    else{
        if(root->left==nullptr) return root->right;
        else if(root->right == nullptr) return root->left;
        // CHange root ka data with its inorder successor
        root->val = getMinValue(root->right);
        root->right = deleteNode(root->right,root->val);
    }
    return root;


}

int main(){

    Node* root = NULL;
    takeInput(root);
    printBST(root);

    cout << "\nInorder traversal in BST comes in a sorted manner :\n" ;
    printInOrder(root);
    cout << endl;
    
    int N;
    cout << "Enter number to be searched in BST : ";
    cin >> N;
    bool found = searchInBST(root,N);
    if(found) cout << N << " Found\n";
    else cout << N << " Not found\n";

    cout << "\nMinimum value in given BST is : " << getMin(root);
    cout << "\nMaximum value in given BST is : " << getMax(root) << endl;
    
    root = deleteNode(root,10);
    cout << "BST after deleting 10: " ;
    printInOrder(root);


    return 0;
}

