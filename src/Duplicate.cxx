#include <iostream>
using namespace std;

bool duplicate(int nums[], int length, int *dups)
{
    if(nums == nullptr || length <= 0){
        return false;
    }
    for(int i=0;i<length;i++){
        while(nums[i] != i){
            if(nums[i] == nums[nums[i]]){
                *dups = nums[i];
                dups++;
                // return true;
                break;
            }
            int tmp = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = tmp;
        }
    }
    if(*dups != -1){
        return true;
    }
    return false;
}

void print(const int* data,int len){
    for(int i=0;i<len;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int dups[5] = {-1,-1,-1,-1,-1};
    int nums[] = {2, 3, 1, 0, 2, 1, 3};
    print(nums,7);
    bool isDup = duplicate(nums, 7, dups);
    cout << "isDup " << isDup<<endl;
    print(dups,5);
    return 0;
}

