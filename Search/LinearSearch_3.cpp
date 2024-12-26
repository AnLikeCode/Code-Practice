/* Cho cấu trúc điểm trong mặt phẳng như sau:
struct Point {
    float x, y;
}; hoặc class Point
Viết hàm tìm kiếm điểm q(xq,yq) trong danh sách các điểm A (A được lưu trữ trên mảng) sao cho
khoảng cách giữa q và p(xp,yp) là nhỏ nhất. Trong đó p là một điểm cho trước (tham số của hàm tìm
kiếm). Kết quả trả về là chỉ số của q trong A
*/

#include <iostream>
using namespace std;

class point{
    public:
        int x;
        int y;
    point(){ // Constructor
        x = 0;
        y = 0;
    }
    void inputPoint(){ // Nhập thông tin cho Point
        cin >> x;
        cin >> y;
    }
    void outputPoint(){
        cout << "(" << x << "," << y << ")" << endl;
    }
    float lenght(point tmp){ // Hàm tính khoảng cách giữa hai điểm
        return sqrt(((tmp.x - this->x) * (tmp.x - this->x)) + ((tmp.y - this->y) * (tmp.y - this->y)));
    }
};

void inputList(point *&list, int &n, point &x){ // Nhập thông tin cho List
    cin >> n;
    if (n <= 0){
        list = NULL;
    }
    else{
        list = new point[n];
    }
    for (int i = 0; i < n; i++){
        (*(list + i)).inputPoint();
    }
    x.inputPoint();
}

void outputList(point *list, int n, point x){
    for (int i = 0; i < n; i++){
        (*(list + i)).outputPoint();
    }
    x.outputPoint();
}

int MinLenght(point *list, int n, point x){
    float min = (*(list + 0)).lenght(x);
    int tmp = 0;
    for (int i = 1; i < n; i++){
        if (min >= (*(list + i)).lenght(x)){
            min = (*(list + i)).lenght(x);
            tmp = i;
        }
    }
    return tmp;
}
    
int main(){
    int n;
    point* list; // Tạo mảng chứa các phần tử point
    point x;
    inputList(list, n, x);
    outputList(list, n, x);
    cout << MinLenght(list, n, x);
    delete []list;
    return 0;
}