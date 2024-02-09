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


// int inOrderPredecessor(Node* root,Node* currNode){
//     // get parent node of currNode
//     // For that do inorder traversal , till u find current node
//     Node* temp = root;

//     while(temp!=currNode){
        
//     }

// }


Node* getLastRight(Node* root){
    if(!root->right) return root;

    return getLastRight(root->right);

}
Node* helper(Node* root){

    // This helper makes useful in giving proper connections
    if(!root->left) {
        // Left child is not there , so return right subtree
        return root->right;
    }
    else if(!root->right){
        // Right subtree is not there , so return left subtree
        return root->left;
    }

    // If both child are present i.e both left child are right child are there
    Node* rightChild = root->right;
    Node* lastRight = getLastRight(root->left);
    lastRight = rightChild;
    return root->left;


}
Node* DeleteNode(Node* root,int key){
    if(!root) return nullptr;
    if(root->val == key) return helper(root);

    Node* dummy = root;
    while(dummy){
        if(key < root->val){
            // So the key may be present in left most part
            if(root->val && root->left->val == key){
                root->left = helper(root->left);
                break;
            }else{
                root = root->left;
            }

        }

        else{

            if(root->right && root->right->val){
                root->right = helper(root->right);
                break;
            }else{
                root = root->right;
            }
        }
       


    }

    return dummy;

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
    root = DeleteNode(root,5);
    printInOrder(root);


    return 0;
}

