#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

void print(deque<int> deque_){
    for(auto it=deque_.begin(); it != deque_.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    return;
}

int main(){
    deque<int> deq = {1,2,3,4,5};
    print(deq);

    deq.push_front(0);
    deq.push_back(6);
    print(deq);

    deq.insert(deq.begin()+2, 10); // 맨 앞에서 2칸 뒤에 10 추가
    print(deq);

    deq.pop_back();
    print(deq);
    deq.pop_front();
    print(deq);

    deq.erase(deq.begin() + 1); // 맨 앞에서 1칸 뒤의 원소 삭제
    print(deq);

    deq.erase(deq.begin()+3, deq.end()); // 맨앞에서 3칸 뒤의 원소부터 끝까지 삭제
    print(deq);
    
    return 0;
}