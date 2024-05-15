#include <iostream>
using namespace std;

bool find(const int matrix[][4], int rows,int cols,int number)
{
    if(matrix==nullptr){
        return false;
    }
    bool found = false;
    int row = 0;
    int col = cols-1;
    while(row<rows && col>0){
        if(matrix[row][col] == number){
            cout<<row<<","<<col<<endl;
            found = true;
            break;
        }
        else if(matrix[row][col]>number){
            col--;
        }
        else{
            row++;
        }
    }

    return found;
}
int main()
{
    int matrix[4][4] = {
        {1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15},
    };
    find(matrix,4,4,7);
    return 0;
}

