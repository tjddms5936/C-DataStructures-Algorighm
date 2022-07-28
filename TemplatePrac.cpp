#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// �Լ� ���ø��� Ư��ȭ
template <typename T>
T Max(T a, T b){
    cout << "T Max()" << endl;
    return a > b ? a : b;
}

// ���� ���� �����ϰ� ������ ���ڿ� �񱳿��� ��������
template <>
char* Max(char* a, char* b){
    cout << "���ڿ� ó���� ���� Ư��ȭ �۾� 1" << endl;
    return strlen(a) > strlen(b) ? a : b;
}

template <>
const char* Max(const char* a, const char* b){
    cout << "���ڿ� ó���� ���� ����ȭ �۾� 2" << endl;
    return strcmp(a,b) > 0 ? a : b;
}


// Ŭ���� ���ø� ����
template <typename T>
class Point
{
private:
    T xpos, ypos;
public:
    Point(T x = 0, T y = 0);
    /*
    ���� ���� �� Ŭ���� �Ʒ� ������ ������ ����
    Point(T x = 0, T y = 0) : xpos(x), ypos(y){} 
     */
    void ShowPosition() const;
    /*
    ���� �Լ� ���� �� Ŭ���� �Ʒ� ������ ������ ����
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

// Ŭ���� ���ø��� Ư��ȭ
template <typename T>
class SimpleDataWrapper
{
private:
    T mData;
public:
    SimpleDataWrapper(T data) : mData(data){}
    void ShowDataInfo(void){
        cout << "class SimpleDataWrapper����" << endl;
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
        // data�� �ִ� ���ڿ� ��ü�� mData�� ����
        // mData = data�� �ȵż� �׷���
        strcpy(mData, data);
    }
    void ShowDataInfo(void){
        cout << "class SimpleDataWrapper<char *>����" << endl;
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
        cout << "class SimpleDataWrapper<Point<int>>����" << endl;
        mData.ShowPosition(); 
    }
};



int main(){

    cout << Max(11, 15) << endl;
    cout << Max('T', 'Q') << endl;
    cout << Max(3.5, 6.1) << endl << endl;
    cout << "Max(\"Simple\",\"Best\") ���" << endl << Max("Simple", "Best") << endl << endl;

    char str1[] = "Simple";
    char str2[] = "Best";
    cout << "char str1[], char str2[] ���� �� �ʱ� ȭ �� ���" << endl << "Max(str1, str2) �����" << endl << Max(str1, str2) << endl;


    Point<int> pos1(3,4);
    pos1.ShowPosition();

    SimpleDataWrapper<int> iwrap(180);
    iwrap.ShowDataInfo();
    SimpleDataWrapper<char*> swrap("Ŭ���� ���ø� Ư��ȭ");
    swrap.ShowDataInfo();
    SimpleDataWrapper<Point<int>> poswrap(3,6);
    poswrap.ShowDataInfo();
    return 0;
}