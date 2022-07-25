#include <iostream>
#include <forward_list>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    // vector를 사용하여 최근 경기 우승자 명단을 작성

    vector<string> vec = {
        "이천수", "박주영", "손흥민", "박지성", 
        "차범근", "이을용", "황의조", "황희찬",
        "호날두", "메시"
    };
    auto it = vec.begin(); // 상수 시간. but, int타입은 아님
    cout << "iterator type name : " << typeid(it).name() << endl;
    int test_it = 3;
    cout << "int type name" << typeid(test_it).name() << endl;

    cout << "(Vector)가장 최근 우승자: " << *it << endl;

    it += 8; // 상수 시간
    cout << "(Vector)8년 전 우승자: " << *it << endl;

    advance(it, -3); // 상수 시간
    cout << "(Vector)그 후 3년 뒤 우승자: " << *it << endl;

    forward_list<string> fwd(vec.begin(), vec.end());

    auto it1 = fwd.begin();
    cout << "(forward_list)가장 최근 우승자: " << *it1 << endl;

    advance(it1, 5); // 선형 시간
    cout << "(forward_list)5년 전 우승자: " << *it1 << endl;
    // forward_list는 순방향으로만 이동할 수 있으므로 
    // 아래 코드는 에러가 발생
    // advance(it1, -2);  : 에러 코드는 안뜨는데 출력은 안됨
    
    // it1 += 2;
    // 다음 에러 발생
    // no match for 'operator+=' (operand types are 'std::_Fwd_list_iterator<std::__cxx11::basic_string<char> >' and 'int')
    
    
    
    return 0;
}