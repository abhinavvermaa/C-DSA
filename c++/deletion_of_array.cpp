#include <iostream>
using namespace std;
int main()
{
    int a[100], i, v, n = 5;
    cout << "enter the 5 values to be stored in array - \n";
    for (i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    cout << "enter the value to be deleted - \n";
    cin >> v;
    cout << "the orignal array is - \n";
    for (i = 0; i < n; i++)
    {
        cout << a[i];
    }
    cout << endl;
    n--;
    for (i = v - 1; i <= n; i++)
    {
        a[i] = a[i + 1];
    }
    cout << "the array after deletion is -";
    cout << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i];
    }
    return 0;
}
