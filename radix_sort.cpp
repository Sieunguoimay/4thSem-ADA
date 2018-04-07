#include<iostream>
#include<string.h>
#define SIZE 10

void counting_sort(int arr[],const int n,int exp){
	//statistic the arr for count[]
	int count[10];//assume that I know the maximum in arr is 50 OK
	memset(count,0,sizeof(count));
	for(int i = 0; i<n; i++)
		count[(arr[i]/exp)%10]++;
	for(int i = 1; i<10; i++)
		count[i]+=count[i-1];//current element is the sum of all the previous elements
	int output[n];
	for(int i = n-1; i>=0;i--){
		output[count[(arr[i]/exp)%10]-1] = arr[i];
		count[(arr[i]/exp)%10]--;
	}
	for(int i = 0; i<n; i++)
		arr[i] = output[i];
}
void radix_sort(int arr[], int n){
	int m = arr[0];
	for(int i = 0; i<n; i++)
		if(m<arr[i]) m = arr[i];

	//for each digit position
	for(int i = 1; m/i>0; i*=10)
		counting_sort(arr,n,i);
}
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}
int main(){
	int arr[] = {10,15,7,6,3,8,47,1,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	//counting_sort(arr,n);
	radix_sort(arr,n);
 	std::cout << "Sorted array is \n";
	printArray(arr, n);
}