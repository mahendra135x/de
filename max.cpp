#include <iostream> 
using namespace std; 
 
struct Pair { 
    int min; 
    int max; 
}; 
 
Pair findMinandMax(int arr[], int low, int high) { 
    Pair result, left, right; 
     
    if (low == high) { 
        result.min = result.max = arr[low]; 
        return result; 
    } 
 
    if (high == low + 1) { 
        if (arr[low] < arr[high]) { 
            result.min = arr[low]; 
            result.max = arr[high]; 
        } else { 
            result.min = arr[high]; 
            result.max = arr[low]; 
        } 
        return result; 
    } 
 
    int mid = (low + high) / 2; 
    left = findMinandMax(arr, low, mid); 
    right = findMinandMax(arr, mid + 1, high); 
 
    result.min = (left.min < right.min) ? left.min : right.min; 
    result.max = (left.max > right.max) ? left.max : right.max; 
 
    return result; 
} 
 
int main() { 
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements in the array: \n";
    for(int i = 0; i < n; i++){
        cout << "Element - " << i+1 << ": ";
        cin >> arr[i];
    }
 
    Pair ans = findMinandMax(arr, 0, n - 1); 
 
    cout << "Minimum element in the array is: " << ans.min << endl; 
    cout << "Maximum element in the array is: " << ans.max << endl; 
 
    return 0; 
}