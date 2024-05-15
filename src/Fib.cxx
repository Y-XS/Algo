#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

long long fib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fib(n-1)+fib(n-2);
}
long long fibR(int n){
    int result[2] = {0,1};
    if(n<2)
        return result[n];
    long long fib_2 = 0;
    long long fib_1 = 1;
    long long fib_n = 0;
    for(int i=2;i<=n;i++){
        fib_n = fib_1 + fib_2;
        fib_2 = fib_1;
        fib_1 = fib_n;
    }
    return fib_n;
}

int main()
{
    // cout<<fib(100)<<endl;
    cout<<fibR(50)<<endl;
}
