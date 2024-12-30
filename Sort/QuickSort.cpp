// INPUT:  5 6 4 1 8 4 3
// OUTPUT: 1 3 4 4 5 6 8

#include <iostream>
using namespace std;

void input(int *&a, int &n){
    cin >> n;
    if(n <= 0){
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

int partition(int *a, int l, int r){ 
    int pivot = *(a + l);
    int i = l - 1;
    int j = r + 1;
    while (true){
        // output(a, 7); // OUtPUT để xem từng vòng lập nó làm cái gì!
        do{
            i++;
        }while (*(a + i) < pivot);
        do{
            j--;
        }while (*(a + j) > pivot);
        // Sau 2 vòng lập trên, chúng ta đã có cặp số so sánh với Pivot, Bên trái Pivot thì nhỏ hơn Pivot, Bên phải Pivot thì lớn hơn Pivot
        if (i < j){
            swap(*(a + i), *(a + j));
        }
        else{
            return j; // Sau khi return thì chúng ta có: Từ j trở về bên trái là các số nhỏ hơn Pivot, Bên phải j là các số lớn hơn Pivot
        }
    }
}

void QuickSort(int *a, int l, int r){
    if(l >= r){
        return;
    }
    int p = partition(a, l, r); 
    QuickSort(a, l, p);
    QuickSort(a, p + 1, r);
}

int main(){
    int n;
    int *a;

    input(a, n);
    // output(a, n);
    QuickSort(a, 0, n - 1);
    // output(a, n);
    
    delete []a;
    return 0;
}