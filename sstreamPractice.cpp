#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){

    // ���� ��� ����ϱ�
    istringstream is("test 123 aaa 456");
    ostringstream os;
    // stringstream ss; ����Ҷ� stringstream ss(���ڿ�)  ������� ���

    // ===================================== istringstream ======================================

    // istringstream�� string�� �Է¹޾� �ٸ� �������� �ٲ��ִ� ����� �Ѵ�. 
    // is  << "test 123 aaa 456"; ������  
    string s1, s2;
    int i1, i2;

    // cout << "is �״�� ��� : " << is << endl;  << ������
    // is >> i1 >> s1 >> i2 >> s2; << ������ �ȳ����� ������ �ȸ¾� ���ϴ� ����� �ȵ�
    is >> s1 >> i1 >> s2 >> i2; 
    cout << s1 << endl;
    cout << i1 << endl;
    cout << s2 << endl;
    cout << i2 << endl;

    // ==========================================================================================
    cout << endl << endl;
    // ===================================== ostringstream�� ======================================

    // ostringstream�� string�� �����ϰų�, Ư�� ��ġ�� ���ڿ��� ��ȯ�ϱ� ���� ����Ѵ�.
    // ostringstream�� ���ڿ��� ���̴� �� �ܿ��� int�� double���� ���� ��ġ���� �����ϰ� string���� �ٲ� �� �ִ�.
    string s11 = "first string", s22 = "second string";
    int i11 = 1010;
    double d1 = 900.5;
    os << s11 <<  " " << i11 << endl << s22 << " " << d1; // ���ڿ� ���̱�
    cout << os.str() << endl; // str() : ostringstream ��ü���� ������ ���ڿ��� ������.

    // ==========================================================================================
    cout << endl << endl;
    // ===================================== stringstream ======================================

    // stringstream�� ������ �ִ� string���� ����� \n�� ������ ���ڿ��� ���ʴ�� ������ ������ �����Ѵ�.

    string str = "123 456 abc \n100 \npppp";
    string token;
    stringstream ss(str);
    cout << "�⺻���� ������ν� ����� \\n�� �������� ����" << endl;
    while (ss >> token){
        cout << token << "  ";
    }
    cout << endl << endl;
    // ���� �����̳� \n�� �ƴ� �ٸ� ���ڸ� �������� ���ڿ��� �и��ϰ� �ʹٸ� ��� �ؾ��ұ�? �̷� ���� std::getline() �Լ��� ����ϸ� �ȴ�.

    str = "123:asc15:v6s:b15:8fq";
    stringstream ss2(str);
    cout << ":�� �������� ���ڿ� ������ ����" << endl;
    while (getline(ss2, token, ':')){
        cout << token << "  ";
    }

    // ==========================================================================================
    return 0;
}