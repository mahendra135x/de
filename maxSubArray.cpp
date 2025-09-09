#include <iostream> 
#include <vector> 
#include <climits> 
using namespace std; 
 
int maxSubarray(vector<int>& nums) { 
    int currSum = 0, maxSum = INT_MIN; 
 
    for (int i = 0; i < nums.size(); i++) { 
        currSum += nums[i]; 
        maxSum = max(currSum, maxSum); 
        if (currSum < 0) { 
            currSum = 0; 
        } 
    } 
    return maxSum; 
} 
 
int main() { 
    int n; 
    cout << "Enter the size of array:"; 
    cin >> n; 
 
    vector<int> nums(n); 
    cout << "Enter elements in the array: " << endl; 
    for (int i = 0; i < n; i++) { 
        cout << "Element - " << i+1 << ": ";
        cin >> nums[i]; 
    } 
 
    cout << "Max Subarray Sum of the array is: " << maxSubarray(nums) << endl; 
    return 0; 
} 