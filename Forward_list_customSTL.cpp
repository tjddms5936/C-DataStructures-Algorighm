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


// singly_ll 클래스의 기본 반복자를 구현합니다. 이 반복자는 생성자(constructor)와 접근자(accessor)를 가집니다.
struct singly_ll_iterator
{
    /* data */
    private:
        node_ptr ptr;

    public:
        singly_ll_iterator(node_ptr p) : ptr(p) {}

        int& operator*() {return ptr->data;}

        node_ptr get() {return ptr;}

        // 선행 증가와 후행 증가를 위한 ++연산자 함수를 구현합니다.
        singly_ll_iterator& operator++(){
            // 선행 증가
            ptr = ptr->next;
            return *this;
        }
        singly_ll_iterator& operator++(int){
            // 후행 증가
            singly_ll_iterator result = *this;
            ++(*this);
            return result;
        }
        
        // 두 연산자가 같은지를 판단하는 관계 연산자 함수를 friend로 정의합니다.
        friend bool operator==(const singly_ll_iterator& left, const singly_ll_iterator& right){
            cout << endl;
            cout << "Custom 두 연산자가 같은지(==) 판단하는 friend로 구현 한 함수입니다." << endl;
            return left.ptr == right.ptr;
        }
        friend bool operator!=(const singly_ll_iterator& left, const singly_ll_iterator& right){
            cout << endl;
            cout << "Custom 두 연산자가 다른지(!=) 판단하는 friend로 구현 한 함수입니다." << endl;
            return left.ptr != right.ptr;
        }
};
    // 다시 singly_ll 클래스 구현으로 돌아와서, 앞에서 반복자 정의했으므로 begin()과 end()함수를 추가 두 함수의 const 버전도 함께 추가
    singly_ll_iterator begin() {return singly_ll_iterator(head);}
    singly_ll_iterator end() {return singly_ll_iterator(NULL);}
    singly_ll_iterator begin() const { return singly_ll_iterator(head);}
    singly_ll_iterator end() const {return singly_ll_iterator(NULL);}

    // 기본 생성자, 깊은 복사를 위한 복사 생성자, 초기화 리스트를 사용하는 생성자를 추가합니다.
    singly_ll() = default;
    singly_ll(const singly_ll& other) : head(NULL){
        cout << endl;
        cout << "Custom 복사 생성자입니다." << endl;
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
        cout << "Custom 초기화 리스트를 사용하는 생성자입니다." << endl;
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

    cout << "첫 번째 리스트: ";
    for(auto i : sll){
        cout << i << " "; 
    } 
    cout << endl;

    auto sll2 = sll;
    sll2.push_front(-1);
    cout << "첫 번째 리스트를 복사한 후, 맨 앞에 -1을 추가: ";
    for(auto i : sll2){
        cout << i << ' ';
    }
    cout << endl;

    cout << "깊은 복사 후 첫 번째 리스트: ";
    for(auto i : sll){
        cout << i << ' ';
    }
    cout << endl;


    return 0;
}