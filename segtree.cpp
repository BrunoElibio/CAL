#include<iostream>
#include<stdio.h>

using namespace std;
#define maxsize 10000

int treeNode[4*maxsize];
int arr[maxsize];

void TreeNode(int nodeNumber,int start,int end){
    int mid,left,right;
    if(start==end){
        treeNode[nodeNumber] = arr[start];
        return;
    }

    mid = (start + end) / 2;
    left = 2*nodeNumber;
    right = 2*nodeNumber + 1;
    cout << mid << " " << left << " " << right<<endl;
    TreeNode(left,start,mid);
    TreeNode(right,mid+1,end);

    treeNode[nodeNumber] = treeNode[left] + treeNode[right] ;
    return;
}


int soma(int nodeNumber,int start,int end,int posStart,int posEnd){

    int mid,left,right;
    if(posEnd < start || posStart > end)
        return 0;
    if (posStart <= start && posEnd >= end)
        return treeNode[nodeNumber];

    mid = (start + end) / 2;
    left = 2*nodeNumber;
    right = 2*nodeNumber + 1;

    return soma(left,start,mid,posStart,posEnd) + soma(right,mid+1,end,posStart,posEnd);
}

int main (){

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
      arr[i] = i;
    }

    TreeNode(1,1,n);
    cout << soma(1,1,n,1,n) << endl;
return 0;
}
