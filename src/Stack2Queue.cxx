#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

class MyQueue
{
public:
    void appendTail(int num)
    {
        stack1.push(num);
    }
    int deleteHead()
    {
        if (stack2.size() <= 0)
        {
            cout<<"stack1.size()="<<stack1.size()<<endl;
            int n = stack1.size();
            for (int i = 0; i < n; i++)
            {
                int num = stack1.top();
                stack1.pop();
                stack2.push(num);
            }
            // while (stack1.size()>0)
            // {
            //     int num = stack1.top();
            //     stack1.pop();
            //     stack2.push(num);
            // }
        }
        int top = stack2.top();
        stack2.pop();
        return top;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    MyQueue mQueue;
    for (int i = 0; i < 10; i++)
    {
        mQueue.appendTail(data[i]);
        // cout<<num<<" ";
    }
    // cout<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout << mQueue.deleteHead() << " ";
    }
    cout << endl;
}
