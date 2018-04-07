#include<iostream>
#include<string.h>
#define SIZE 10

void counting_sort(int arr[],const int n){
	//statistic the arr for count[]
	int count[50];//assume that I know the maximum in arr is 50 OK
	memset(count,0,sizeof(count));
	for(int i = 0; i<n; i++)
		count[arr[i]]++;
	for(int i = 1; i<50; i++)
		count[i]+=count[i-1];//current element is the sum of all the previous elements
	int output[n];
	for(int i = 0; i<n;i++){
		output[count[arr[i]]-1] = arr[i];
		count[arr[i]]--;
	}
	for(int i = 0; i<n; i++)
		arr[i] = output[i];
}
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}
int main(){
	int arr[] = {10,15,7,6,3,8,47};
	int n = sizeof(arr)/sizeof(arr[0]);
	counting_sort(arr,n);
 	std::cout << "Sorted array is \n";
	printArray(arr, n);
}