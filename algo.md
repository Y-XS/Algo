# 基础

数组名为指针，指向第一个元素

```c++
int data[] = {1,2,3,4,5}
sizeof(data)//20
int *data2 = data;
sizeof(data2)//4
getSize(data1);
int getSize(int data[]);//退化为指针
```

## 运算符重载

# 思路



## 逆向思维

```c++
//字符串替换空格为%20
void replaceBlank(char* str,int length){}
```

# 原题

## 1.赋值运算符

```c++
//注意指针
class CMyString
{
    friend ostream& operator<<(ostream& os,const CMyString& str)
    {
        os<< str.m_data;
        return os;
    }
public:
    CMyString(char *data = nullptr)
    {
        m_data = new char[strlen(data)+1];
        strcpy(m_data,data);
    }
    CMyString(const CMyString &str)
    {
        m_data = new char[strlen(str.m_data)+1];
        strcpy(m_data,str.m_data);
    }
    ~CMyString()
    {
        delete[] m_data;
    }
    CMyString& operator=(const CMyString& str){
        //高级
        if(&str != this){
            CMyString tmp(str);
            char* cTmp = tmp.m_data;
            tmp.m_data = m_data;
            m_data = cTmp;
        }
        return *this;
        //基础
        // delete[] m_data;
        // m_data = nullptr;
        // m_data = new char[strlen(str.m_data)+1];
        // strcpy(m_data,str.m_data);
        // return *this;
    }
private:
    char *m_data = nullptr;
};
int main()
{
    CMyString mStr1("hello mystr1");
    CMyString mStr2("hello mystr2");
    CMyString mStr3("hello mystr3");
    cout<< mStr1<<endl;
    cout<< mStr2<<endl;
    cout<< mStr3<<endl;
    mStr1 = mStr2 = mStr3;
    cout<< mStr1<<endl;
    cout<< mStr2<<endl;
    cout<< mStr3<<endl;
    return 0;
}
```

## 2.单例模式

## 3.数组重复数字

```c++
bool duplicate(int nums[], int length, int *dups){
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
int main(){
    int dups[5] = {-1,-1,-1,-1,-1};
    int nums[] = {2, 3, 1, 0, 2, 1, 3};
    print(nums,7);
    bool isDup = duplicate(nums, 7, dups);
    cout << "isDup " << isDup<<endl;
    print(dups,5);
    return 0;
}
```

## 4.二维数组查找

```c++
bool find(const int matrix[][4], int rows,int cols,int number){
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
int main(){
    int matrix[4][4] = {
        {1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15},
    };
    find(matrix,4,4,7);
    return 0;
}
```

## 5.字符串替换

```c++
void replaceBlank(char* str,int length){
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
int main(){
    char* str = new char[18];
    strcpy(str,"we are happy.");
    cout<<str<<endl;
    replaceBlank(str,18);
    cout<<str<<endl;
    return 0;
}
```

## 6.逆向打印链表

```c++
struct ListNode{
    int m_value;
    ListNode* m_next;
};
ListNode* creat(int n){
    ListNode* head = nullptr;
    ListNode* senti = nullptr;
    for(int i=0;i<n;i++){
        ListNode* node = new ListNode;
        node->m_value = i;
        node->m_next = nullptr;
        if(i==0){
            head = node;
            senti = head;
        }else{
            senti->m_next = node;
            senti = senti->m_next;
        }
    }
    return head;
}
void print(ListNode* head){
    if(head == nullptr){
        return;
    }
    ListNode* node = head;
    while(node){
        cout<<node->m_value<<" ";
        node = node->m_next;
    }
    cout<<endl;
}
void rPrint(ListNode* head){
    if(head == nullptr){
        return;
    }
    ListNode* node = head;
    stack<int> stk;
    while(node){
        stk.push(node->m_value);
        node = node->m_next;
    }
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
}
int main()
{
    ListNode* head = nullptr;
    head = creat(10);
    print(head);
    rPrint(head);
    return 0;
}
```

## 7.重建二叉树

## 8.二叉树的下一个节点

## 9.两个栈实现队列

## 10.斐波那契数列

```c++
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
//青蛙跳台阶问题
```



