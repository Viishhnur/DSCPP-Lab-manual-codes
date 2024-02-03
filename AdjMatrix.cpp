#include<iostream>
#include<map>
#include<vector>
using namespace std;

void getAdjMatrix(int n , map<int,int>mp){
    
    // Created a nxn matrix with all zeros 
    vector<vector<int>> adjMatrix(n,vector<int>(n,0));


    for(const auto& pair : mp){
        adjMatrix[pair.first][pair.second] = 1;
    }

    cout << "Adjancency matrix representation of given graph is : \n\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << adjMatrix[i][j] << " " ;
        }cout << endl;
    }
    
    return;

}
int main(){

    map<int,int>mp;
    // Take Input from user number of nodes and number of edges

    int N;
    cout << "Enter number of nodes: " ;
    cin >> N ;

    int E;
    cout << "Enter number of edges : " ;
    cin >> E ;

    cout << "Enter connections to be made : \n" ;
    
    for(int i=1;i<=E;i++){
        int firstNode,secondNode;
        cout << "Enter connection "  << i << " : ";
        cin >> firstNode >> secondNode;
        mp[firstNode] = secondNode;

    }

    getAdjMatrix(N,mp);
    cout << endl;

    return 0;
}
