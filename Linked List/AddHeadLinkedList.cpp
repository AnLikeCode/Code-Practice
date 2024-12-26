//------------------------------------- ĐỀ BÀI
// Thêm một phần tử vào đầu danh sách liên kết đơn Cho một danh sách liên kết đơn, hãy cài đặt hàm SinglyLinkedListNode* insertNodeAtHead(int )  
// để thêm một nút có thuộc tính data có giá trị _data vào đầu danh sách liên kết đơn. 
// Chú ý hàm  insertNodeAtHead(int ) thuộc lớp SinglyLinkedList có thuộc tính head là con trỏ trỏ đến nút đầu của danh sách liên kết.

#include <iostream>
using namespace std;

class SinglyLinkedListNode { // Khởi tạo Node

    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) { // Hàm khởi tạo
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList { // Khởi tạo List
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() { // Hàm khởi tạo
            this->head = nullptr;
            this->tail = nullptr;
        }

        // Hàm này tạo các phần tử cho List
        void insert_node(int node_data) {

            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) { //Check list rỗng
                this->head = node;
            } else {
                this->tail->next = node;
            }
            this->tail = node;
        }


        void printLinkedList() {
            SinglyLinkedListNode* p;
            p = head;
            while (p != NULL){
                cout<<p->data<<endl;
                p = p->next;
            }
        }

//-------------------------
	SinglyLinkedListNode* insertNodeAtHead(int _data) {
        SinglyLinkedListNode* newnode = new SinglyLinkedListNode(_data);
        newnode->next = this->head;
        this->head = newnode;
        return newnode;
	}
//-------------------------
};


void free_singly_linked_list(SinglyLinkedListNode* node) { // Giải phóng vùng nhớ các phần tử trong List
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}



int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    int x;

    cin >> llist_count; // Số phần tử của List

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        llist->insert_node(llist_item);
    }

    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        llist->insertNodeAtHead(llist_item);
    }
    cout << endl;

    llist->printLinkedList();
    free_singly_linked_list(llist->head);

    return 0;
}