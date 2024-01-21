#include <iostream>
using namespace std;

int binarySearch(int a[], int key, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (a[mid] == key)
    {
        return mid;
    }
    if (key > a[mid])
    {
        return binarySearch(a, key, mid + 1, high);
    }
    if (key < a[mid])
    {
        return binarySearch(a, key, low ,mid - 1);
    }
}
int main(void)
{
    int a[5], s, key, low, high,n=5;
    cout << "enter the 5 array elements \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout<<"enter the key :";
    cin>>key;
    s = binarySearch(a, key, 0,n);
    if(s == -1){
        cout<<"not found";
    }
    else{
        cout<<"found at :"<<s;
    }
}
// C++ program to implement recursive Binary Search