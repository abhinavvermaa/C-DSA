#include <iostream>
using namespace std;

int main()
{
    int a[100][100],b[100][100],c[100][100],i,j,rows,columns;
    cout<<"enter the rows and columns of matrix a and b (*size will be similar of both)"<<endl;
    cin>>rows;
    cin>>columns;
    cout<<"enter the value of matrix a - "<<endl;
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            cin>>a[i][j];
        }
    }
    cout<<"enter the value of matrix b - "<<endl;
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            cin>>b[i][j];
        }
    }
    cout<<" The matrix a is - "<<endl;
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            cout<<"\t"<<a[i][j];
        }cout<<"\n";
    }
    cout<<" The matrix b is - "<<endl;
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            cout<<"\t"<<b[i][j];
        }cout<<"\n";
    }
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            c[i][j] += a[i][j];
            c[i][j] += b[i][j];
        }
    }
    cout<<" The matrix c (*sum matrix) is - "<<endl;
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            cout<<"\t"<<c[i][j];
        }cout<<"\n";
    }
    return 0;
}


