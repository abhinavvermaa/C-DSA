#include <iostream>
using namespace std;

void search(int l)
{
    int arr[50], i, n;
    for (i = 0; i < l; i++)
    {
        cin >> arr[i];
    };
    cout << "enter the no. you want to find - ";
    cin >> n;
    for (i = 0; i < l; i++)
    {
        if (arr[i] == n)
        {
            cout << "found at index - " << i << " \n";
            break;
        }
    };
    if (i == l)
    {
        cout << "not found"
             << "\n";
    }
}
int main()
{
    int l;
    cout << "enter the length of the array - " << endl;
    cin >> l;
    cout << "enter the " << l << " numbers -" << endl;
    search(l);
    return 0;
}
