#include <iostream>
using namespace std;
int main()
{
    int arr[100],i,n=5,v,pos;
    cout<<"enter the 5 values to be stored in array \n";
    for(i=0;i<5;i++){
        cin>>arr[i];
    }
    cout<<"enter the value and the index at which the value to be inserted \n";
    cin>>v;
    cin>>pos;
        cout<<"the original array is - \n";

    for(i=0;i<n;i++){
        cout<<arr[i];
    }
    n++;
    for(i=n;i>=pos;i--){
        arr[i] = arr[i-1] ;
    }
    cout<<endl;
    arr[pos-1]=v;
    cout<<"the array after insertion is -"<<endl;
    for(i = 0; i < n; i++){
        cout<<arr[i];
    }

    return 0;
}



