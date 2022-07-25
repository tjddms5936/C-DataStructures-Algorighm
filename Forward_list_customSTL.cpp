#include <iostream>
#include <algorithm>

using namespace std;

struct singly_ll_node
{
    /* data */
    int data;
    singly_ll_node* next;
};

class singly_ll{
public:
    using node = singly_ll_node;
    using node_ptr = node*;

private:
    node_ptr head;

public:
    void push_front(int val){
        auto new_node = new node {val, NULL};
        if(head != NULL){
            new_node->next = head;
        }
        head = new_node;
    }
    void pop_front(){
        auto first = head;
        if(head){
            head = head->next;
            delete first;
        }
    }


// singly_ll Ŭ������ �⺻ �ݺ��ڸ� �����մϴ�. �� �ݺ��ڴ� ������(constructor)�� ������(accessor)�� �����ϴ�.
struct singly_ll_iterator
{
    /* data */
    private:
        node_ptr ptr;

    public:
        singly_ll_iterator(node_ptr p) : ptr(p) {}

        int& operator*() {return ptr->data;}

        node_ptr get() {return ptr;}

        // ���� ������ ���� ������ ���� ++������ �Լ��� �����մϴ�.
        singly_ll_iterator& operator++(){
            // ���� ����
            ptr = ptr->next;
            return *this;
        }
        singly_ll_iterator& operator++(int){
            // ���� ����
            singly_ll_iterator result = *this;
            ++(*this);
            return result;
        }
        
        // �� �����ڰ� �������� �Ǵ��ϴ� ���� ������ �Լ��� friend�� �����մϴ�.
        friend bool operator==(const singly_ll_iterator& left, const singly_ll_iterator& right){
            cout << endl;
            cout << "Custom �� �����ڰ� ������(==) �Ǵ��ϴ� friend�� ���� �� �Լ��Դϴ�." << endl;
            return left.ptr == right.ptr;
        }
        friend bool operator!=(const singly_ll_iterator& left, const singly_ll_iterator& right){
            cout << endl;
            cout << "Custom �� �����ڰ� �ٸ���(!=) �Ǵ��ϴ� friend�� ���� �� �Լ��Դϴ�." << endl;
            return left.ptr != right.ptr;
        }
};
    // �ٽ� singly_ll Ŭ���� �������� ���ƿͼ�, �տ��� �ݺ��� ���������Ƿ� begin()�� end()�Լ��� �߰� �� �Լ��� const ������ �Բ� �߰�
    singly_ll_iterator begin() {return singly_ll_iterator(head);}
    singly_ll_iterator end() {return singly_ll_iterator(NULL);}
    singly_ll_iterator begin() const { return singly_ll_iterator(head);}
    singly_ll_iterator end() const {return singly_ll_iterator(NULL);}

    // �⺻ ������, ���� ���縦 ���� ���� ������, �ʱ�ȭ ����Ʈ�� ����ϴ� �����ڸ� �߰��մϴ�.
    singly_ll() = default;
    singly_ll(const singly_ll& other) : head(NULL){
        cout << endl;
        cout << "Custom ���� �������Դϴ�." << endl;
        if(other.head){
            head = new node{0, NULL};
            auto cur = head;
            auto it = other.begin();
            while (true)
            {
                /* code */
                cur->data = *it;

                auto tmp = it;
                ++tmp;
                if(tmp == other.end()){
                    break;
                }
                cur->next = new node{0,NULL};
                cur = cur->next;
                it = tmp;
            }
        }
    }
    singly_ll(const initializer_list<int>& ilist) : head(NULL){
        cout << endl;
        cout << "Custom �ʱ�ȭ ����Ʈ�� ����ϴ� �������Դϴ�." << endl;
        for(auto it = rbegin(ilist); it != rend(ilist); it++){
            push_front(*it);
        }
    }
};

// void singly_ll::push_front(int val){
//     auto new_node = new node {val, NULL};
//     if(this->head != NULL){
//         new_node->next = head;
//     }
//     head = new_node;
//     return;
// }
// void singly_ll::pop_front(){
//     auto first = head;
//     if(head){
//         head = head->next;
//         delete first;
//     }
//     return;
// }



int main(){
    singly_ll sll = {1, 2, 3};
    sll.push_front(0);

    cout << "ù ��° ����Ʈ: ";
    for(auto i : sll){
        cout << i << " "; 
    } 
    cout << endl;

    auto sll2 = sll;
    sll2.push_front(-1);
    cout << "ù ��° ����Ʈ�� ������ ��, �� �տ� -1�� �߰�: ";
    for(auto i : sll2){
        cout << i << ' ';
    }
    cout << endl;

    cout << "���� ���� �� ù ��° ����Ʈ: ";
    for(auto i : sll){
        cout << i << ' ';
    }
    cout << endl;


    return 0;
}