#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int x)
{
	if (high >= low) {
		int mid = (high + low) / 2;
		if (arr[mid] == x)
			return mid;
		if (x < arr[mid])
		return binarySearch(arr, low, mid - 1, x);
		return binarySearch(arr, mid + 1, high, x);
	}
	return -1;
}

int main(void)
{
	int arr[5];
	int x,n=5;
	cout<<"enter the 5 value in ascending order \n";
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"enter the value of to be searched \n";
	cin>>x;
	int result = binarySearch(arr, 0, n, x);
	if(result == -1){
		 cout << "Element is not present in array";
	}
	else{
		 cout << "Element is present at index - " << result;
	}
	return 0;
}