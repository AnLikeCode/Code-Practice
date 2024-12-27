/*
Yêu cầu: Hãy cài đặt thuật toán sắp xếp chèn để sắp xếp lại mảng có N phần tử. Trong lúc chạy thuật toán, nếu xảy ra hành động swap, hãy in ra mảng sau hành động swap đó. Bằng cách này, các bạn có thể hình dung được cách hoạt động của thuật toán sắp xếp.

Input:

Dòng đầu tiên là số nguyên N dương (0 < N < 200)

Dòng tiếp theo chứa N số nguyên Ai là các phần tử của mảng

Output:

Các dòng tiếp theo in ra cấu hình của mảng A mỗi lần mảng A xảy ra hành động swap.
*/

#include <iostream>
using namespace std;

void input(int *&a, int &n){
    cin >> n;
    if (n <= 0){
        a = NULL;
    }
    else{
        a = new int[n];
    }
    for (int i = 0; i < n; i++){
        cin >> *(a + i);
    }
}

void output(int *a, int n){
    for (int i = 0; i < n; i++){
        cout << *(a + i) << " ";
    }
    cout << endl;
}

void InsertionSort2(int *&a, int n){
    int i = 1;
    int k;
    int tmp;
    while (i < n){
        k = i - 1;
        tmp = *(a + i);
        while (k >= 0){
            if (*(a + k) < tmp){
                break;
            }
            else{
                *(a + k + 1) = *(a + k);
                k--;
                output(a, n);
            }
        }
        *(a + k + 1) = tmp;
        i++;
        output(a, n);
    }
}

int main(){
    int n;
    int *a;
    input(a, n);
    InsertionSort2(a, n);
    return 0;
}