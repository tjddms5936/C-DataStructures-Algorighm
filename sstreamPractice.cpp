#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){

    // 선언 방식 기억하기
    istringstream is("test 123 aaa 456");
    ostringstream os;
    // stringstream ss; 사용할때 stringstream ss(문자열)  방식으로 사용

    // ===================================== istringstream ======================================

    // istringstream은 string을 입력받아 다른 형식으로 바꿔주는 기능을 한다. 
    // is  << "test 123 aaa 456"; 오류남  
    string s1, s2;
    int i1, i2;

    // cout << "is 그대로 출력 : " << is << endl;  << 오류남
    // is >> i1 >> s1 >> i2 >> s2; << 오류는 안나지만 순서가 안맞아 원하는 출력이 안됨
    is >> s1 >> i1 >> s2 >> i2; 
    cout << s1 << endl;
    cout << i1 << endl;
    cout << s2 << endl;
    cout << i2 << endl;

    // ==========================================================================================
    cout << endl << endl;
    // ===================================== ostringstream은 ======================================

    // ostringstream은 string을 조립하거나, 특정 수치를 문자열로 변환하기 위해 사용한다.
    // ostringstream은 문자열을 붙이는 것 외에도 int나 double형과 같은 수치값을 간단하게 string으로 바꿀 수 있다.
    string s11 = "first string", s22 = "second string";
    int i11 = 1010;
    double d1 = 900.5;
    os << s11 <<  " " << i11 << endl << s22 << " " << d1; // 문자열 붙이기
    cout << os.str() << endl; // str() : ostringstream 객체에서 조립된 문자열을 꺼낸다.

    // ==========================================================================================
    cout << endl << endl;
    // ===================================== stringstream ======================================

    // stringstream은 가지고 있는 string에서 공백과 \n을 제외한 문자열을 차례대로 빼내는 역할을 수행한다.

    string str = "123 456 abc \n100 \npppp";
    string token;
    stringstream ss(str);
    cout << "기본적인 방식으로써 공백과 \\n을 기준으로 나눔" << endl;
    while (ss >> token){
        cout << token << "  ";
    }
    cout << endl << endl;
    // 만약 공백이나 \n이 아닌 다른 문자를 기준으로 문자열을 분리하고 싶다면 어떻게 해야할까? 이럴 때는 std::getline() 함수를 사용하면 된다.

    str = "123:asc15:v6s:b15:8fq";
    stringstream ss2(str);
    cout << ":를 기준으로 문자열 나누고 싶음" << endl;
    while (getline(ss2, token, ':')){
        cout << token << "  ";
    }

    // ==========================================================================================
    return 0;
}