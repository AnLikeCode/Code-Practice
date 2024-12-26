// Cải tiến ở chổ: Thay vì check mỗi mid trong mỗi vòng lặp, tiến hành check cả left, right
#include <iostream>
using namespace std;

void input(int *&a, int &n, int &x){
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
    cin >> x;
}

int BinarySearch(int *a, int n, int x){
    int left = 0;
    int right = n - 1;
    int mid = 0;
    int count = 0; // Cái này đang đếm số lần nó chia đôi
    
    while (left <= right){
        count++;
        mid = (left + right) / 2;

        if (*(a + mid) == x){
            cout << mid << endl;
            cout << count;
            return mid;
        }
        else if (*(a + left) == x){
            cout << left << endl;
            cout << count;
            return left;
        }
        else if (*(a + right) == x){
            cout << right << endl;
            cout << count;
            return right;
        }
        else if (*(a + mid) <= x){
            left = mid + 1;
            right -= 1;
        }
        else{
            right = mid - 1;
            left += 1;
        }
    }
    cout << -1;
    return -1;
}

int main(){
    int n;
    int *a;
    int x;
    input(a, n, x);
    BinarySearch(a, n, x);
    delete []a;
    return 0;
}