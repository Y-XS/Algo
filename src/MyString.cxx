#include <iostream>
#include<string.h>
using namespace std;

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