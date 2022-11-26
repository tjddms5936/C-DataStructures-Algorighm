#include <iostream>
#include <vector>

using namespace std;


int main(){
    vector<int> v;
    v.reserve(1000);

    for(const auto& e : v){
        cout << e << endl;
    }
    cout << "size : " << v.size() << endl;
    cout << "capacity : " << v.capacity() << endl;

    cout << "===================" << endl;

    // Initialization 방식
    vector<int> vec2(1000);
    vec2.emplace_back(44);

    for (const auto& elem : vec2){
        cout << elem << endl;
    }
    cout << vec2.size() << endl;
    cout << vec2.capacity() << endl;


    return 0;
}