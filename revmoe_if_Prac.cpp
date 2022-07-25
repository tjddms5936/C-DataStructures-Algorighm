#include <string>
#include <iostream>
#include <forward_list>
#include <sstream>

using namespace std;

struct citizen
{
    /* data */
    string name;
    int age;
};

ostream &operator<<(ostream &os, const citizen &c){
    // 출력 함수 생성
    return (os << "[" << c.name << ", " << c.age << "]");
}

int main(){
    forward_list<citizen> citizens = {
        {"Kim", 22}, {"Lee", 25}, {"Park", 18}, {"Jin", 16}
    };

    auto citizens_copy = citizens; // 깊은 복사

    cout << "전체 시민들: ";
    for (const auto &c : citizens){
        cout << c << " "; // 출력함수에 의하여 원하는 대로 출력됨
    }
    cout << endl;

    // 나이 정보를 이용하여 투표권이 없는 시민을 리스트에서 제거
    citizens.remove_if([](const citizen &c){
        return (c.age < 19);  // 간단한 조건이므로 담다식 사용하였음.
    });

    cout << "투표권이 있는 사람들: ";
    for(const auto &c : citizens){
        cout << c << " ";
    }
    cout << endl;

    // 내년에 새로 투표권이 생기는 사람을 알아보기
    citizens_copy.remove_if([](const citizen &c){
        return (c.age != 18);
    });

    cout << "내년에 새로 투표권이 생기는 시민들: ";
    for(const auto &c : citizens_copy){
        cout << c << " ";
    }
    cout << endl;


    return 0;
}
