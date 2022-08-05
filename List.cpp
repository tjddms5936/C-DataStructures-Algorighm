#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

void print(const list<int>& list){
    for(auto it = list.begin(); it != list.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    return;
}

int main(){
    list<int> list1 = {1, 2, 3, 4, 5};
    print(list1);
    list1.push_back(6);
    print(list1);
    list1.insert(next(list1.begin()), 0);
    print(list1);
    list1.insert(list1.end(), 7);
    print(list1);

    list1.pop_back();
    print(list1);


    return 0;
}