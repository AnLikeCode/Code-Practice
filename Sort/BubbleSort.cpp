/*
Yêu cầu: Hãy cài đặt thuật toán tìm kiếm nổi bọt để sắp xếp lại mảng có N phần tử. Trong lúc chạy thuật toán, nếu xảy ra hành động swap, hãy in ra mảng sau hành động swap đó. Bằng cách này, các bạn có thể hình dung được cách hoạt động của thuật toán sắp xếp.

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

void BubbleSort(int *&a, int n){
    int tmp = n;
    while (tmp > 0){
        for (int i = 1; i < n; i++){
            if(*(a + i - 1) > *(a + i)){
                swap(*(a + i - 1), *(a + i));
                output(a, n);
            }
        }
        tmp--;
    }
}

int main(){
    int n;
    int *a;

    input(a, n);
    BubbleSort(a, n);

    return 0;
}

/* CẢI TIẾN THUẬT TOÁN SẮP XẾP NỔI BỌT
Ý TƯỞNG: Rõ ràng sau các vòng lặp thì giá trị lớn nhất được đẩy về cuối mảng
-> Vậy thì khi xét vòng lập tiếp theo không cần xét nữa
void BubbleSort(int *&a, int n){
    while (n > 0){
        for (int i = 1; i < n; i++){
            if(*(a + i - 1) > *(a + i)){
                swap(*(a + i - 1), *(a + i));
                output(a, n);
            }
        }
        n--;
    }
}

Input:
4
499 158 144 36
Output:
158 499 144 36 
158 144 499 36 
158 144 36 499 
144 158 36 
144 36 158 
36 144 
*/