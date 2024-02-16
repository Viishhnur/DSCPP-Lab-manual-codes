#include<iostream>
using namespace std;

class BinaryTree{
    int top;
    int arr[20];

    public:
        BinaryTree(int root){
            // arr = new int[maxsize];
            arr[0] = root;
            top = 0;
        }
        int size();
        void setLeft(int,int);
        void setRight(int,int);
        void printTree();
        int getParentIndex(int);
};

int BinaryTree :: size(){
    return top+1;
}

void BinaryTree :: setLeft(int rootIndex,int element){
    arr[(rootIndex*2)+1] = element;
}

void BinaryTree :: setRight(int rootIndex,int element){
    arr[(rootIndex*2)+2] = element;
}

void BinaryTree :: printTree(){
    for(int i=0;i<7;i++){
        cout << arr[i] << endl;
    }
    cout << endl;
}

int BinaryTree :: getParentIndex(int childIndex){
    int parent = (childIndex+1)/2;
    return parent;
}
int main(){
    BinaryTree* bt = new BinaryTree(45);
    bt->setLeft(0,34);
    bt->setRight(0,40);
    bt->setLeft(1,23);
    bt->setRight(1,16);
    bt->setLeft(2,22);
    bt->setRight(2,30);
    bt->printTree();

    return 0;
}
