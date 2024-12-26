#include <iostream>
using namespace std;

void input(int *&a, int &n, int &x){
    cin >> n;
    if (n > 0){
        a = new int[n];
    }
    else{
        a = NULL;
    }
    for (int i = 0; i < n; i++){
        cin >> *(a+i);
    }
    cin >> x;
}

int Linear_Search_FirstToLast(int *a, int n, int x){
    int count = 0;
    for (int i = 0; i < n; i++){
        count++;
        if ( x == *(a+i)){
            cout << i << endl;
            cout << count << endl;
            return i;
        }
    }
    return -1;
}

int Linear_Search_LastToFirst(int *a, int n, int x){
    if (Linear_Search_FirstToLast(a, n, x) == -1){
        cout << -1;
    }
    else{
        int count = 0;
        for (int i = n - 1; i > 0; i--){
            count++;
            if (x == *(a+i)){
                cout << n - 1 - i << endl;
                cout << count << endl;
                return n - 1 - i;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    int *a;
    int x;
    input(a, n, x);
    Linear_Search_LastToFirst(a, n, x);
    delete[] a;
    return 0;
}