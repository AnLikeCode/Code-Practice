// Cải tiến ở chổ: Thay vì check mỗi mid trong mỗi vòng lặp, tiến hành check cả left, right

#include <iostream>
using namespace std;

void input(string *&a, int &n, string &x){
    cin >> n;
    if (n <= 0){
        a = NULL;
    }
    else{
        a = new string[n];
    }
    for (int i = 0; i < n; i++){
        cin >> *(a + i);
    }
    cin >> x;
}

int BinarySearch(string *a, int n, string x){
    int left = 0;
    int right = n - 1;
    int mid = 0;
    int count = 0; // Cái này đang đếm số lần nó chia đôi mảng ban đầu
    while (left <= right){
        count++;
        mid = (left + right) / 2;

        if (*(a + mid) == x){
            cout << mid << endl;
            cout << count;
            return mid;
        }
        else if (*(a + mid) <= x){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << -1;
    return -1;
}

// void output(string *a, int n, string x){
//     for(int i = 0; i < n; i++){
//         cout << *(a + i) << " ";
//     }
// }

int main(){
    int n;
    string *a;
    string x;
    input(a, n, x);
    BinarySearch(a, n, x);
    delete []a;
    return 0;
}

