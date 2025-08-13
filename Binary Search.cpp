//Binary search

#include<stdio.h>

int binary_search(int arr[], int size, int target){
	int low = 0;
	int high = size - 1;
	
	while(low <= high){
		int mid = (low + high)/2;
		
		if(arr[mid] == target){
			return mid;
		}
		
		if(arr[mid] < target){
			low = mid + 1;
		}
		
		if(arr[mid] > target){
			high = mid - 1;
		}
	}
	
	return -1;
}

int main(){
	int n;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	int arr[n], key;
	printf("Enter the elements of array:\n");
	
	for(int i=0;i<n;i++){
		printf("Element - %d: ", i);
		scanf("%d", &arr[i]);
	}
	
	printf("Enter the element to be found: ");
	scanf("%d", &key);
	int result = binary_search(arr, n, key);
	
	if(result == -1){
		printf("Element not found.");
	}
	else{
		printf("Element found at %d position", result);
	}
	
	return 0;
}