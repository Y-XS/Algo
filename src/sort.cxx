#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

void swap(int* a,int* b){
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(int data[],int start,int end){
    int idx = start-1;
    for(int i=start;i!=end;i++){
        if(data[i]<data[idx]){
            idx++;
            if(i!=idx){
                swap(&data[i],&data[idx]);
            }
        }
    }

    return idx;
}
int part(int data[],int left,int right){
    int key = left;
    while(left<right){
        while(left<right && data[right]>=data[key]){
            right--;
        }
        while(data[left]<=data[key]){
            left++;
        }
        swap(&data[left],&data[right]);
    }
    swap(&data[right],&data[key]);
    return right;
}
void quickSort(int data[],int begin,int end){
    if(begin>=end){
        return;
    }
    int key = part(data,begin,end);
    quickSort(data,begin,key-1);
    quickSort(data,key+1,end);
}
void print(int data[],int length){
    for(int i=0;i<length;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int data[10] = {1,6,2,4,9,1,8,4,7,0};
    print(data,10);
    quickSort(data,0,9);
    print(data,10);
    cout<<endl;
    return 0;
}
