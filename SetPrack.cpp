#include <iostream>
#include <set>
#include <queue>
#include <functional>

using namespace std;

template <typename T>
struct Label
{
    unsigned ID;
    T distancel

    inline bool operator>(const Label<T>& label2) const{
        return this->distance > 
    }
};


int main(){
    set<unsigned> testset;

    cout << *(testset.end()) << endl;

    priority_queue<int, vector<int>, greater<int>> pq; // 최대 힙...인데 오름차순...

    pq.push(5);
    pq.push(15);
    pq.push(4);
    pq.push(2);
    pq.push(59);

    cout << "우선순위 큐 사이즈 : " << pq.size() << endl;
    
    while (!pq.empty())
    {
        cout << pq.top() << "\t";
        pq.pop();
    }
    
    
    


    return 0;
}