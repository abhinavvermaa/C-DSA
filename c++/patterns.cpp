#include <iostream>
using namespace std;

void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j<<" ";
        }
        cout << endl;
    }
}
void print4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i<<" ";
        }
        cout << endl;
    }
}
void print5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i+1; j++)
        {
            cout <<"*";
        }
        cout << endl;
    }
}
void print6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <n-i-1; j++)
        {
            cout <<" ";
        }
        for (int j = 0; j < 2*i+1; j++)
        {
            cout <<"*";
        }
        for (int j = 0; j < n-i-1; j++)
        {
            cout <<" ";
        }
        cout << endl;
    }
}
void print7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <i; j++)
        {
            cout <<" ";
        }
        for (int j = 0; j < 2*n-(2*i+1); j++)
        {
            cout <<"*";
        }
        for (int j = 0; j < i; j++)
        {
            cout <<" ";
        }
        cout << endl;
    }
}
void print8(int n)
{
    for (int i = 1; i <= n; i++)
    {
        
        for (int j = 1; j <=i; j++)
        {
            cout <<j;
        }
        for (int j = 0; j < 2*n-(2*i); j++)
        {
            cout <<" ";
        }
        for (int j = i; j > 0; j--)
        {
            cout <<j;
        }
        cout << endl;
    }
}
void print13(int n)
{
    int num =1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout <<num<<" " ;
            num = num+1;
        }
        cout << endl;
    }
}
void print14(int n)
{
    char ch = 'A';
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout <<ch<<" " ;
    //         ch++;
    //     }
    //     cout << endl;
    //     ch='A';
    // }
    for (int i = 0; i < n; i++)
    {
        for (char c='A';c<='A'+i;c++){
            cout<<c<<" ";
        }
        cout<<endl;
    }
}
void print15(int n)
{
    // char ch = 'A';
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n-i+1; j++)
    //     {
    //         cout <<ch<<" " ;
    //         ch++;
    //     }
    //     cout << endl;
    //     ch='A';
    // }
    for (int i = 0; i <n; i++)
    {
        for (char c='A';c<='A'+(n-i-1);c++){
            cout<<c<<" ";
        }
        cout<<endl;
    }
}
void print16(int n)
{
    char ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout <<ch<<" " ;
        }
        cout << endl;
        ch++;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (char c='A';c<='A'+i;c++){
    //         cout<<c<<" ";
    //     }
    //     cout<<endl;
    // }
}
void print17(int n)
{
    char ch='A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <n-i-1; j++)
        {
            cout <<" ";
        }
        int breakpoint = (2*i+1)/2;
        for (int j = 1; j <= 2*i+1; j++)
        {
            cout <<ch;
            if(j<=breakpoint) ch++;
            else ch--;
            
            
        }
        for (int j = 0; j < n-i-1; j++)
        {
            cout <<" ";
        }
        cout << endl;
        ch='A';
    }
}
void print18(int n){
    for(int i =0;i<n ; i++){
        for(char ch = 'E'-i;ch<='E';ch++){
            cout<<ch;
        }
        cout<<endl;
    }
}
void print19(int n)
{
    
                int space=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <n-i; j++)
        {
            cout <<"*";
        }
        for (int j = 0; j < space; j++)
        {
            cout <<" ";
        }
        for (int j = 0; j < n-i; j++)
        {
            cout <<"*";
        }
        cout << endl;
        space +=2;
    }
}
int main()
{
    int t;
    int n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
         print19(n);
    }
    return 0;
}
