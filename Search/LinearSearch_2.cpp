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

int check(int *a, int n, int x){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (*(a + i) == x){
            count++;
        }
    }
    if (count != 0){
        cout << count << endl;
        return count;
    }
    cout << 0;
    return 0;
}

int LinearSearch(int *&a, int n, int x){
    if (check(a, n, x) == 0){ // Đường đéo nào cũng in count ra thôi :D
        return 0;
    }
    for (int i = 0; i < n; i++){
        if (*(a + i) == x){
            cout << i << " " << i + 1 << endl;
        }
    }
    return 0;
}

int main(){
    int n;
    int *a;
    int x;
    input(a, n, x);
    LinearSearch(a, n, x);
    delete []a;
    return 0;
}