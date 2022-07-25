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
    // ��� �Լ� ����
    return (os << "[" << c.name << ", " << c.age << "]");
}

int main(){
    forward_list<citizen> citizens = {
        {"Kim", 22}, {"Lee", 25}, {"Park", 18}, {"Jin", 16}
    };

    auto citizens_copy = citizens; // ���� ����

    cout << "��ü �ùε�: ";
    for (const auto &c : citizens){
        cout << c << " "; // ����Լ��� ���Ͽ� ���ϴ� ��� ��µ�
    }
    cout << endl;

    // ���� ������ �̿��Ͽ� ��ǥ���� ���� �ù��� ����Ʈ���� ����
    citizens.remove_if([](const citizen &c){
        return (c.age < 19);  // ������ �����̹Ƿ� ��ٽ� ����Ͽ���.
    });

    cout << "��ǥ���� �ִ� �����: ";
    for(const auto &c : citizens){
        cout << c << " ";
    }
    cout << endl;

    // ���⿡ ���� ��ǥ���� ����� ����� �˾ƺ���
    citizens_copy.remove_if([](const citizen &c){
        return (c.age != 18);
    });

    cout << "���⿡ ���� ��ǥ���� ����� �ùε�: ";
    for(const auto &c : citizens_copy){
        cout << c << " ";
    }
    cout << endl;


    return 0;
}
