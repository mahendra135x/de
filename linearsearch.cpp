#include <iostream>
using namespace std;
int main(){
    int n, key;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";

    for(int i = 0; i < n; i++){
        cout << "Element " << i+1 << ": ";
        cin >> arr[i];
    }

    cout << "Enter the element to be found: ";
    cin >> key;

    for(int i = 0; i < n; i++){
        if(key == arr[i]){
            cout << "Element is found at " << i+1 << " position";
            break;
        }
    }
    return 0;
}