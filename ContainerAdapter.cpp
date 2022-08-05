#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

void print_stack(stack<int> stk){
    stack<int> copy = stk;
    while (!copy.empty())
    {
        cout << copy.top() << " ";
        copy.pop();
    }
    cout << endl;
}

void print_queue(queue<int> q){
    queue<int> copy = q;
    while (!copy.empty())
    {
        cout << copy.front() << " ";
        copy.pop();
    }
    cout << "��" << endl;
    cout << endl;
    
}


int main(){
    // �����̳� ����Ͷ�? : �̹� �����ϴ� �����̳ʸ� ������� ������� �����̳�

    // deque�� ������� ������� stack(LIFO) : ���Լ���. �߰��� ���� ���� ���� �Ұ���
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    print_stack(stk);
    stk.pop();
    print_stack(stk);
    // stk.push_front(0); // ������ ����!

    // deque�� ������� ������� queue(FIFO) : ���Լ���. �߰��� ���� ���� ���� �Ұ���
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    print_queue(q);
    q.pop();
    print_queue(q);
    q.push(4);
    print_queue(q);

    return 0;
}