/*
Yêu cầu: Hãy cài đặt thuật toán sắp selection sort để sắp xếp lại mảng có N phần tử. Trong lúc chạy thuật toán, nếu xảy ra hành động swap, hãy in ra mảng sau hành động swap đó. Bằng cách này, các bạn có thể hình dung được cách hoạt động của thuật toán sắp xếp.

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
    else {
        a = new int[n];
    }
    int i = 0;
    while (i < n){
        cin >> *(a + i);
        i++;
    }
}

void output(int *a, int n){
    int i = 0;
    while (i < n){
        cout << *(a + i) << " ";
        i++;
    }
    cout << endl;
}

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void SelectionSort(int *a, int n){
    int i = 0;
    while (i < n - 1){
        int j = i + 1;
        int min = i;
        while (j < n){
            if (*(a + j) <= *(a + min)){
                min = j;
            }
            j++;
        }
        if (min != i){ // Min đã thay đổi -> Có nghĩa là có phần tử trong list con nhỏ hơn giá trị min (mà Min đang gán bằng i)
            swap(*(a + i),*(a + min)); // Do đó tiến hành swap vị trí chổ i và min
            output(a, n);
            i++;
        }
        else{
            i++;
        }
    }
}

int main(){
    int n;
    int *a;
    input(a, n);
    SelectionSort(a, n);
    return 0;
}