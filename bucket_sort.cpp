#include<iostream>
#include<vector>
#include<algorithm>
//bucket sort applied for the number in range 0.0 - 1.0
void bucket_sort(float arr[],int n){
	std::vector<float>b[n];//create n buckets
	for(int i = 0; i<n;i++)
		b[(int)(arr[i]*n)].push_back(arr[i]);
	for(int i = 0; i<n;i++){
		std::sort(b[i].begin(),b[i].end());
	}
	//collect them all
	int index = 0;
	for(int i = 0; i<n; i++)
		for(auto&a:b[i])
			arr[index++] = a;
}
template<class T>
void printArray(T arr[], int n)
{
    for (int i=0; i<n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}
int main(){
	float arr[] = {0.01,0.14,0.15,0.36,0.58,0.35,0.27};
	int n = sizeof(arr)/sizeof(arr[0]);
	bucket_sort(arr,n);
 	std::cout << "Sorted array is \n";
	printArray(arr, n);
	return 0;
}