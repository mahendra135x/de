#include <iostream>
using namespace std;
int main(){
    int n, key, flag =0;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: \n";

    for(int i = 0; i < n; i++){
        cout << "Element " << i+1 << ": ";
        cin >> arr[i];
    }

    cout << "Enter the element to be found: ";
    cin >> key;

    for(int i = 0; i < n; i++){
        if(key == arr[i]){
            flag = i;
            break;
        }
    }
    if (flag == 0){
        cout << "Element not found!";
    }
    else{
        cout << "Element found at " << flag << " position";
    }
    return 0;
}
