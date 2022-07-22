#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief std::array의 단점 
 * std::array의 크기는 컴파일 시간에 결정되는 상수여야 한다. -> 따라서 프로그램 실행 중에는 변경 x 
 * 크기가 고정되어 있어서 원소를 추가하거나 삭제할 수 없다.
 * 메모리 할당 방법을 변경할 수 없다. 항상 스택 메모리를 사용한다.
 * 
 * 이게 왜 큰 단점? 
 * 대부분의 실제 응용 프로그램에서 데이터의 크기를 미리 알고 있기가 쉽지 않다. 
 * 따라서 가변 크기의 데이터를 처리할 수 없는 컨테이너인 array를 사용하는 것은 항상 좋은 것은 아니다.
 */

/**
 * @brief std:vector - 가변 크기 배열
 * std:array가 가지고 있는 특징인 '고정 크기' 문제를 해결한다.
 * std:vector는 초기화 과정에 데이터의 크기를 제공하지 않아도 된다.
 * 벡터의 크기는 벡터에 실제로 저장된 원소 개수. 용량과는 다른 의미이다.
 */

template <typename T>
void print(vector<T> v){
    vector<int>::iterator iter;
    if(v.size() == 0){
        cout << "벡터가 비어 있습니다." << endl;
        return;
    } 
    for(iter = v.begin(); iter != v.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
    return;
}


int main(){

        // 벡터를 초기화하는 몇 가지 방법들
    vector<int> vec_dec1; // 크기가 0인 벡터 선언 : 크기는 0이지만 용량은 0 || 작은 양수.
    vector<int> vec_dec2 = {1, 2, 3, 4, 5}; // 지정한 초깃값으로 이루어진 크기가 5인 벡터 선언
    vector<int> vec_dec3(10); //크기가 10인 벡터 선언
    vector<int> vec_dec4(10, 5); // 크기가 10이고, 모든 원소가 5로 초기화된 벡터 선언
    /**
     * push_back() || insert() : 벡터에 새로운 원소 추가
     * push_back() : 벡터의 맨 마지막에 새로운 원소를 추가
     * insert() : 삽입할 위치를 나타내는 반복자를 첫 번째 인자로 받고 원하는 위치에 원소 추가
     * 벡터는 push_front() 함수를 지원하지 않는다. 맨 앞에 추가하고 싶으면 insert() 활용해야 한다.
     */

    vector<int> v1; // 비어 있는 벡터 생성 : {}
    print(v1);
    v1.push_back(1); // 맨 뒤에 1 추가 : {1}
    print(v1);
    v1.push_back(2); // 맨 뒤에 2 추가 : {1, 2}
    print(v1);
    v1.insert(v1.begin(), 0); // 맨 앞에 0 추가 : {0, 1, 2}
    print(v1);
    v1.insert(find(v1.begin(), v1.end(), 1), 4); // 1 앞에 4 추가 : {0, 4, 1, 2}  @ find 함수를 쓰기 위해서는 algorithm 라이브러리 추가
    print(v1);

    /**
     * pop_back() || erase() : 원소 제거
     * pop_back() : 벡터에서 맨 마지막 원소 제거. 벡터 크기는 1만큼 줄어든다.
     * erase() : 두 가지 형태로 오버로딩 되어 있다.
     *      1. 반복자 하나를 인자로 받아 해당 위치 원소를 제거
     *      2. 범위의 시작과 끝을 나타내는 반복자를 받아 시작부터 끝 바로 앞 원소까지 제거.
     */

    vector<int> v2 = {0,1,2,3,4,5,6,7,8,9};
    print(v2);
    v2.pop_back(); // 맨 마지막 원소를 제거
    print(v2);
    v2.erase(v2.begin()); // 맨 처음 원소를 제거
    print(v2);
    v2.erase(v2.begin() + 1, v2.begin() + 4); // 1번째 원소부터 4번째 앞 원소까지 제거
    print(v2);
    v2.clear(); // 모든 원소를 제거하여 완전히 비어 있는 벡터로 만든다.
    print(v2);
    
    cout << "벡터 v2의 크기(size) : " << v2.size() << endl;
    cout << "벡터 v2의 용량(capacity) : " << v2.capacity() << endl;
    v2.reserve(100); // reserve를 쓰는 이유는 vector를 추가할 때 기존 용량 초과이면 할당->복사->해제 작업순서 진행. 즉 미리 용량 확보해 이 작업 안하게 하는거
    cout << "v2.reserve(100)한 뒤 v2의 크기(size) : " << v2.size() << endl;
    cout << "v2.reserve(100)한 뒤 v2의 용량(capacity) : " << v2.capacity() << endl;
    return 0;
}