#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
struct PlayList_node
{
    /* data */
    T* data;
    PlayList_node* next;
    PlayList_node* prev;

    ~PlayList_node(){
        delete data;
    }
};

template <typename T>
class PlayList
{
public:
    using node =  PlayList_node<T>;
    using node_ptr = node*;
private:
    /* data */
    node_ptr head;
    size_t n;
public:

    PlayList() : n(0){
        head = new node {NULL, NULL, NULL}; // ��� null�� ������ �⺻ ���
        head->next = head;
        head->prev = head;
    }

    size_t size() const{
        return n;
    }
    void insert(const T& value){
        node_ptr new_node = new node {new T(value), NULL, NULL};
        n++;
        auto dummy = head->prev;
        dummy->next = new_node;
        new_node->prev = dummy;
        
        if(head == dummy){
            dummy->prev = new_node;
            new_node->next = dummy;
            head = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void erase(const T& value){
        auto cur = head, dummy = head->prev;
        while (cur != dummy)
        {
            if(*(cur->data) == value){
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                if(cur == head){
                    head = head->next;
                }
                delete cur;
                n--;
                return;
            }
            cur = cur->next;
        }
    }

    struct PlayList_it
    {
    private:
        node_ptr ptr;
    public:
        // �Ʒ��� ���� : ptr(p)�� ���� ���� ���� const ������ �ʱ�ȭ ��Ű�� ���� �̴ϼȶ����� ����̴�. 
        PlayList_it(node_ptr p) : ptr(p) {}

        T& operator*(){
            return *(ptr->data);
        }

        node_ptr get(){
            return ptr;
        }

        PlayList_it& operator++(){
            ptr = ptr->next;
            return *this;
        }

        PlayList_it& operator++(int){
            PlayList_it it = *this;
            ++(*this);
            return it;
        }

        PlayList_it* operator--(){
            ptr = ptr->prev;
            return *this;
        }

        PlayList_it* operator--(int){
            PlayList_it it = *this;
            --(*this);
            return it;
        }

        friend bool operator==(const PlayList_it& it1, const PlayList_it& it2){
            return it1.ptr == it2.ptr;
        }

        friend bool operator!=(const PlayList_it& it1, const PlayList_it& it2){
            return it1.ptr != it2.ptr;
        }
    };
    
    PlayList_it begin(){ return PlayList_it {head}; }
    PlayList_it begin() const { return PlayList_it {head}; }
    PlayList_it end() { return PlayList_it {head->prev}; }
    PlayList_it end() const { return PlayList_it {head->prev}; }

    PlayList(const PlayList<T>& other) : PlayList(){
        // �Ʒ� �ڵ�� ���Ҹ� �������� ����������
        // ���� ����Ʈ�̱� ������ ���� �����ϴ�.
        for(const auto& i : other){
            insert(i);
        }
    }

    PlayList(const initializer_list<T>& il) : head(NULL), n(0){
        // �Ʒ� �ڵ�� ���Ҹ� �������� ����������
        // ���� ����Ʈ�̱� ������ ���� �����ϴ�.
        for(const auto& i : il){
            insert(i);
        }
    }

    ~PlayList(){
        while (this->size())
        {
            erase(*(head->data));
        }
        delete head;
    }
};

struct playlist
{
    PlayList<int> list;

    void insert(int song){
        list.insert(song);
    }

    void erase(int song){
        list.erase(song);
    }
    void loopOnce(){
        for(auto& song : list){
            cout << song << " ";
        }
        cout << endl;
    }
};




int main(){
    playlist p1;
    p1.insert(1);
    p1.insert(2);
    cout << "��� ��� : ";
    p1.loopOnce();

    playlist p2 = p1;
    p2.erase(2);
    p2.insert(3);
    cout << "�� ���� ���� ��� : ";
    p2.loopOnce();
    return 0;
}