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
    cout << "끝" << endl;
    cout << endl;
    
}


int main(){
    // 컨테이너 어댑터란? : 이미 존재하는 컨테이너를 기반으로 만들어진 컨테이너

    // deque을 기반으로 만들어진 stack(LIFO) : 후입선출. 중간에 원소 삽입 삭제 불가능
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    print_stack(stk);
    stk.pop();
    print_stack(stk);
    // stk.push_front(0); // 컴파일 에러!

    // deque을 기반으로 만들어진 queue(FIFO) : 선입선출. 중간에 원소 삽입 삭제 불가능
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