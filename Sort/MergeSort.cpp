#include <iostream>
using namespace std;

void input(int *a, int &n){
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

void Merge(int *a, int l, int m, int r){
    // Tạo 2 cái mảng tạm
    int nb = m - l + 1;
    int nc = r - m;
    int *b = new int[nb];
    int *c = new int[nc];

    // Sao chép vào 2 cái mảng tạm
    for (int i = 0; i < nb; i++){
        *(b + i) = *(a + l + i);
    }
    for (int j = 0; j < nc; j++){
        *(c + j) = *(a + m + 1 + j);
    }

    // Logic Merge
    int i = 0; // Biến chạy của mảng động b
    int j = 0; // Biến chạy của mảng động c
    while (i < nb && j < nc){
        if (*(b + i) <= *(c + j)){
            *(a + l) = *(b + i);
            l++;
            i++;
        }
        else{
            *(a + l) = *(c + j);
            l++;
            j++;
        }
    }
    while (i < nb){
        *(a + l) = *(b + i);
        l++;
        i++; 
    }
    while (j < nc){
        *(a + l) = *(c + j);
        l++;
        j++;
    }

    delete []b;
    delete []c;
}

void MergeSort(int *a, int l, int r){
    if (l >= r){
        return;
    }
    int m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, m, r);
}

int main(){
    int n;
    int *a;
    input(a, n);
    output(a, n);
    MergeSort(a, 0, n - 1);
    output(a, n);

    return 0;
}