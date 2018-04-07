//cut the rob problem is one of the Dynamic Programming Problem
//that can be solved by Recursion. Since the no of loop can increase dramatically.
#include<iostream>
#include<limits.h>
//this function is return the maximum value of the cut.
//which takes in the array of prices for each size.
//That is for each size of the rod there are different values.
//but as you can see, it propotional to the length of the cut.
//what you have to do is:
//find out the maximum values that can be obtained from the cut.
//since the length of the rod is constant, when you choose one size the left length 
//will be reduce by that amount of size. and you have to choose among that left length
//to find out the maximum values possible in that remaining length
int count_loop = 0;
int cut_rod(int *prices, int n){
	count_loop++;
	//the function returns 0 in case the length is 0
	if(n<=0) return 0;
	//at this point length of n is >= 1 

	//now we keep track of the maximum value returns in n case of the first cut
	//each time the recursion is called, the number of cutting increase by 1.
	int max_value = INT_MIN;//min integer is a constant in limits.h header file.
	for(int i = 0; i< n; i++){
		int temp = prices[i] + cut_rod(prices, n-i-1);//recusion here
		if(max_value < temp)
			max_value = temp;
	}
	return max_value;
}
//no recursion here
int cut_rod_reduce_overlapping(int* prices, int n){
	int max_value_array[n+1];
	max_value_array[0] = 0;
	for(int i = 1; i<= n; i++){
		int max_value = INT_MIN;
		for(int j = 0; j<i; j++){
			max_value = std::max(max_value, prices[j]+ max_value_array[i-j-1]);
			count_loop++;
		}
		max_value_array[i] = max_value;
	}
	return max_value_array[n];
}
int main(){
	int prices[]={1,5,8,9,10,17,17,20};
	int n = sizeof(prices)/sizeof(prices[0]);

	std::cout<<"Maximum value (by cut_rod()) is: "<<cut_rod(prices,n)<<"\n";
	std::cout<<"Number of loops: "<<count_loop;
	count_loop = 0;
	std::cout<<"\nMaximum value (by cut_rod_reduce_overlapping())is: "<<cut_rod_reduce_overlapping(prices,n)<<"\n";
	std::cout<<"Number of loops: "<<count_loop;
	return 0;
}