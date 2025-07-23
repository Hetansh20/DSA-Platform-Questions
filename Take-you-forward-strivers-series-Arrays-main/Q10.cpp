#include <iostream>
using namespace std;

int main(){
	int arr[]={1,2,4,5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum=0;
	int total = (n*(n+1))/2;
	
	for(int i=0;i<n-1;i++){
		sum+=arr[i];
	}
	int missing_num= total-sum;
	
	cout<< "The missing number is:" << missing_num << endl;
	return 0;
}
