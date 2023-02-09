#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int arr[10];
    int arr_r[10] = { -1,-1, -1, -1, -1, -1, -1, -1, -1, -1 };
    int j = 0;
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
        auto it = std::find(std::begin(arr_r), std::end(arr_r), arr[i] % 42);
        if (it == std::end(arr_r)) {
            arr_r[j] = arr[i] % 42;
            j++;
        }
    }
    cout << j;
}