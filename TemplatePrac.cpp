#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 함수 템플릿의 특수화
template <typename T>
T Max(T a, T b){
    cout << "T Max()" << endl;
    return a > b ? a : b;
}

// 위와 같이 구현하고 끝내면 문자열 비교에서 문제생김
template <>
char* Max(char* a, char* b){
    cout << "문자열 처리를 위한 특수화 작업 1" << endl;
    return strlen(a) > strlen(b) ? a : b;
}

template <>
const char* Max(const char* a, const char* b){
    cout << "문자열 처리를 위한 툭수화 작업 2" << endl;
    return strcmp(a,b) > 0 ? a : b;
}


// 클래스 템플릿 연습
template <typename T>
class Point
{
private:
    T xpos, ypos;
public:
    Point(T x = 0, T y = 0);
    /*
    위의 선언 및 클래스 아래 구현은 다음과 같음
    Point(T x = 0, T y = 0) : xpos(x), ypos(y){} 
     */
    void ShowPosition() const;
    /*
    위의 함수 선언 및 클래스 아래 구현은 다음과 같음
    void ShowPosition() const{
        cout << "[ " << xpos << ", " << ypos << " ]" << endl;
    }
    */
};

template <typename T>
Point<T>::Point(T x, T y){
    xpos = x;
    ypos = y;
}

template <typename T>
void Point<T>::ShowPosition() const{
    cout << "[ " << xpos << ", " << ypos << " ]" << endl;
}

// 클래스 템플릿의 특수화
template <typename T>
class SimpleDataWrapper
{
private:
    T mData;
public:
    SimpleDataWrapper(T data) : mData(data){}
    void ShowDataInfo(void){
        cout << "class SimpleDataWrapper에서" << endl;
        cout << "Data: " << mData << endl;
    }
};

template<>
class SimpleDataWrapper<char *>
{
private:
    char* mData;
public:
    SimpleDataWrapper(char* data){
        mData = new char[strlen(data) + 1];
        // data에 있는 문자열 전체를 mData로 복사
        // mData = data가 안돼서 그런듯
        strcpy(mData, data);
    }
    void ShowDataInfo(void){
        cout << "class SimpleDataWrapper<char *>에서" << endl;
        cout << "String: " << mData << endl;
        cout << "Length: " << strlen(mData) << endl;
    }
    ~SimpleDataWrapper() {delete []mData;}
};

template<>
class SimpleDataWrapper<Point<int>>
{
private:
    Point<int> mData;
public:
    SimpleDataWrapper(int x, int y) : mData(x,y){}
    void ShowDataInfo(void){
        cout << "class SimpleDataWrapper<Point<int>>에서" << endl;
        mData.ShowPosition(); 
    }
};



int main(){

    cout << Max(11, 15) << endl;
    cout << Max('T', 'Q') << endl;
    cout << Max(3.5, 6.1) << endl << endl;
    cout << "Max(\"Simple\",\"Best\") 결과" << endl << Max("Simple", "Best") << endl << endl;

    char str1[] = "Simple";
    char str2[] = "Best";
    cout << "char str1[], char str2[] 선언 및 초기 화 후 사용" << endl << "Max(str1, str2) 결과는" << endl << Max(str1, str2) << endl;


    Point<int> pos1(3,4);
    pos1.ShowPosition();

    SimpleDataWrapper<int> iwrap(180);
    iwrap.ShowDataInfo();
    SimpleDataWrapper<char*> swrap("클래스 템플릿 특수화");
    swrap.ShowDataInfo();
    SimpleDataWrapper<Point<int>> poswrap(3,6);
    poswrap.ShowDataInfo();
    return 0;
}