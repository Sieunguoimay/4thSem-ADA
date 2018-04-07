#include<iostream>
#include<algorithm>
struct Item{
	float value;
	float weight;
};
bool greater(Item a, Item b){
	if(a.value/a.weight>b.value/b.weight)
		return true;
	return false;
}
float fractional_knapsack(Item item[],int n, float capacity){
	std::sort(item, item+n,greater);
	float final_value = 0;
	float currentW = 0;
	for(int i = 0; i<n; i++){
		if(item[i].weight+currentW<=capacity){
			currentW += item[i].weight;
			final_value += item[i].value;
		}else{
			final_value+=item[i].value*(capacity-currentW)/item[i].weight;
		}
	}
	return final_value;
}
int main(){
	Item arr[] = {{60,10},{100,20},{120,30}};
	int n = sizeof(arr)/sizeof(arr[0]);
	std::cout<<"maximum value can take: "<<fractional_knapsack(arr,n,50);
	return 0;
}