#include <iostream>
using namespace std;

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
    };

    MyLinkedList() {
        _size = 0;
        _dummyHead = new ListNode();
    }
    
    int get(int index) {
        if (index < 0 || index >= _size) {
            return -1;
        }
        ListNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        return cur->next->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > _size) {
            return ;
        }
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= _size) {
            return ;
        }
        ListNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        ListNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp; //删除节点，手动释放内存
        //delete命令指示释放了tmp指针原本所指的那部分内存，
        //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
        //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
        //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
        temp=nullptr;
        _size--;
    }

    void print() {
        ListNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << ' ';
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int _size;
    ListNode* _dummyHead;
};

int main() {
    MyLinkedList linkedList = MyLinkedList();
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2);
    linkedList.print();
    cout << linkedList.get(1) << endl;
    linkedList.deleteAtIndex(1);
    linkedList.print();
    cout << linkedList.get(1) << endl;
    return 0;
}