#include<iostream>
#include<queue>
using namespace std;

class Node{
    
    public:
        int val;
        Node* left;
        Node* right;
        Node(int val){
            this->val = val;
            left = right = nullptr;
        } 


};

class BinaryTree{
    int numberOfNodes;
    public:
        BinaryTree(){
            numberOfNodes = 0;

        }
        Node* buildTree(Node*&);
        void preOrder(Node*);
        void inOrder(Node*);
        void postOrder(Node*);
        void levelOrder(Node*);
        int getNoOfNodes(Node*);
        int maxHeight(Node*);


};

int BinaryTree :: getNoOfNodes(Node*root){
    return numberOfNodes;
}
Node* BinaryTree :: buildTree(Node* &root){
    
    cout << "\nEnter the data : ";
    int data;
    cin >> data;
    // Create a root node or initalise it
    root = new Node(data);
    

    if(data==-1) return NULL;

    cout << "Enter data to be inserted to the left of " << data << " " ;
    root->left = buildTree(root->left);
    cout << "Enter data to be inserted to the right of " << data << " " ;
    root->right = buildTree(root->right);
    return root;
}

void BinaryTree :: preOrder(Node* root){

    if(!root) return;
    // Preorder=> (Root , Left , Right)
    cout << root->val << " " ;
    preOrder(root->left);
    preOrder(root->right);
}

void BinaryTree :: inOrder(Node* root){
    if(!root) return ;
    // Inorder => (Left Root Right)
    inOrder(root->left);
    cout << root->val << " " ;
    inOrder(root->right);
}

void BinaryTree :: postOrder(Node* root){
    if(!root) return;

    // PostOrderr => (Left , Right , Root)
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " " ;
    numberOfNodes++;
}


void BinaryTree :: levelOrder(Node* root){

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

int BinaryTree :: maxHeight(Node* root){
    if(!root) return 0;

    int lh = maxHeight(root->left);
    int rh = maxHeight(root->right);
    return 1+max(lh,rh) ;
}
int main(){

    BinaryTree bt;
    Node* root = NULL;
    bt.buildTree(root);

    cout << "\nPre-order traversal : " ;
    bt.preOrder(root);

    cout << "\nIn-order traversal : " ;
    bt.inOrder(root);

    cout << "\nPost-order traversal : " ;
    bt.postOrder(root);

    cout << "\n\nLevel order traversal : \n";
    bt.levelOrder(root);

    cout << "\nNumber of nodes in tree : " << bt.getNoOfNodes(root) << endl;
    
    cout << "height of binary tree is " << bt.maxHeight(root) << endl;

    return 0;
}

       
        



    
