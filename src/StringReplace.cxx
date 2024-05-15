#include <iostream>
#include<string.h>
using namespace std;

void replaceBlank(char* str,int length)
{
    if(str == nullptr || length<0){
        return;
    }
    int oldLen = 0;
    int blankCnt = 0;
    while(str[oldLen] != '\0'){
        if(str[oldLen] == ' '){
            blankCnt++;
        }
        oldLen++;
    }
    cout<<oldLen<<" "<<blankCnt<<endl;
    int oldP = oldLen;
    int newP = oldLen+2*blankCnt;
    if(newP > length){
        return;
    }
    while(oldP<newP && oldP>=0){
        if(str[oldP]==' '){
            str[newP--] = '0';
            str[newP--] = '2';
            str[newP--] = '%';
        }
        else{
            str[newP--] = str[oldP];
        }
        oldP--;
    }
}
int main()
{
    char* str = new char[18];
    strcpy(str,"we are happy.");
    cout<<str<<endl;
    replaceBlank(str,18);
    cout<<str<<endl;
    return 0;
}

