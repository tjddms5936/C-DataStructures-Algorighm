#include <iostream>
#include <forward_list>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    // vector�� ����Ͽ� �ֱ� ��� ����� ����� �ۼ�

    vector<string> vec = {
        "��õ��", "���ֿ�", "�����", "������", 
        "������", "������", "Ȳ����", "Ȳ����",
        "ȣ����", "�޽�"
    };
    auto it = vec.begin(); // ��� �ð�. but, intŸ���� �ƴ�
    cout << "iterator type name : " << typeid(it).name() << endl;
    int test_it = 3;
    cout << "int type name" << typeid(test_it).name() << endl;

    cout << "(Vector)���� �ֱ� �����: " << *it << endl;

    it += 8; // ��� �ð�
    cout << "(Vector)8�� �� �����: " << *it << endl;

    advance(it, -3); // ��� �ð�
    cout << "(Vector)�� �� 3�� �� �����: " << *it << endl;

    forward_list<string> fwd(vec.begin(), vec.end());

    auto it1 = fwd.begin();
    cout << "(forward_list)���� �ֱ� �����: " << *it1 << endl;

    advance(it1, 5); // ���� �ð�
    cout << "(forward_list)5�� �� �����: " << *it1 << endl;
    // forward_list�� ���������θ� �̵��� �� �����Ƿ� 
    // �Ʒ� �ڵ�� ������ �߻�
    // advance(it1, -2);  : ���� �ڵ�� �ȶߴµ� ����� �ȵ�
    
    // it1 += 2;
    // ���� ���� �߻�
    // no match for 'operator+=' (operand types are 'std::_Fwd_list_iterator<std::__cxx11::basic_string<char> >' and 'int')
    
    
    
    return 0;
}