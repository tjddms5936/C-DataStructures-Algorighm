#include <iostream>
#include <algorithm>
#include <forward_list>

using namespace std;
/**
 * @brief forward_list
 * 맨 처음 원소에 접근하는 front() 함수를 제공 but, 반대 방향의 원소로 이동하는 back()은 제공 x 
 * 원소의 삽입, 삭제, 순서 뒤집기, 분할을 위한 기능 제공
 */

template <typename T>
void print(forward_list<T> fwd_list){
    
    for(auto it = fwd_list.begin(); it != fwd_list.end(); it++){ 
        // it의 타입은 int가 아님. 괴상한거임
      cout << *it << " ";  
    }
    cout << endl;
    return;
}


int main(){


    /**
     * push_front : 연결 리스트 맨 앞에 새로운 원소를 삽입
     * insert_after : 특정 위치에 원소를 삽입
     *      - 연결 리스트에서 새로운 원소를 삽입한 후, 해당 위치 앞에 있는 원소의 next 포인터를 수정해야 하기 때문이다.
     *      - 반대 방향으로 이동하는 것이 허용x 따라서 특정 원소 뒤에 새로운 원소 삽입 후, 해당 원소의 next 포인터를 수정하는 것이 타당하다.
     * 연결 리스트에서 원소 삽입 후 다른 원소를 이동할 필요가 없다.
     * 삽입 함수는 리스트의 원소 크기에 영향을 받지 않는다.
     */

    // 연결 리스트에 원소를 삽입하는 다양한 코드 예제
    forward_list<int> fwd_list = {1, 2, 3};
    print(fwd_list);
    fwd_list.push_front(0); // 맨 앞에 0 추가 : {0, 1, 2, 3}
    print(fwd_list);
    auto it = fwd_list.begin();
    fwd_list.insert_after(it, 5); // 맨 처음 원소 뒤에 5 추가 : {0, 5, 1, 2, 3}
    print(fwd_list);
    fwd_list.insert_after(it, 6); // 맨 처음 원소 뒤에 6 추가 : {0, 6, 5, 1, 2, 3}
    print(fwd_list);

    cout << endl << endl;
    /**
     * pop_front() : 리스트의 맨 처음 원소를 제거. 원소 이동이 필요 x 
     * erase_after() : 두 가지 형태로 제공
     *      1. 특정 원소를 가리키는 반복자를 인자로 받아서 바로 다음 위치의 원소를 삭제
     *      2. 범위 삭제의 경우 : 삭제할 범위의 시작 원소 '앞'을 가리키는 반복자와 삭제할 범위 끝 원소를 가리키는 반복자를 인자로 받음
     */

    forward_list<int> fwd_list2 = {1, 2, 3, 4, 5};
    print(fwd_list2);
    fwd_list2.pop_front(); // 맨 앞 원소를 삭제 {2, 3, 4, 5}
    print(fwd_list2);
    auto it2 = fwd_list2.begin();
    cout << "it의 type : " << typeid(it2).name() << endl; // it2의 타입은 int가 아님
    fwd_list2.erase_after(it2); // 맨 앞의 다음 원소를 삭제 : {2, 4, 5}
    print(fwd_list2);
    fwd_list2.erase_after(it2, fwd_list2.end()); // 맨 앞 원소 다음부터 끝까지 삭제 : {2}
    print(fwd_list2);

    /**
     * remove() : 삭제할 원소 값 하나를 매개변수로 받는다.
     *      - 저장된 데이터 타입에 정의된 등호 연산자를 사용하여 전달된 값과 일치하는 모든 원소를 찾아 삭제한다.
     *      - 저장된 데이터 타입에서 등호 연산이 지원되지 않으면 remove()함수 사용 불가. 에러 발생
     *      - 오직 등호 연산에 근거하여 원소를 삭제.
     * remove_if() : 데이터 원소 값 하나를 인자로 받는다.
     *      - bool 값을 반환하는 조건자 함수를 인자로 받는다.
     *      - 조건자가 true를 반환하는 모든 데이터 원소를 리스트에서 삭제.
     *      - 조건자 자리에 람다 표현식을 사용 가능
     * 
     */
    cout << endl << endl;

    /**
     * 두 가지 형태의 sort() 함수
     * 1. std::less<value_type>을 비교자로 사용하여 오름차순
     * 2. std::greater<value_type>을 비교자로서 매개변수로 넣어주면 내림차순
     */
    forward_list<int> list1 = {23, 0, 1, -2, 52, 34};
    print(list1);
    list1.sort();
    print(list1);
    list1.sort(greater<int>());
    print(list1);
    cout << endl << endl;

    /**
     * reverse() : 저장된 원소의 순서를 역순으로 변경
     * unique() : 리스트에서 홀로 나타나는 원소는 놔두고, 인접하여 중복되는 원소에 대해서는 첫 번째만 남겨두고 나머지는 제거
     *      - 각각의 원소를 나머지 원소 전체와 비교하는 것이 아니기 때문에 유일한 원소만 남게 하려면 정렬 먼저 해줘야 함
     *      - 이 함수는 두 원소가 같은지를 판단하는 방식에 따라 두 가지 형태로 제공
     *          1. 인자가 없는 형태 : 이때는 원소 타입의 등호 연산자를 사용하여 같은지를 판단.
     *          2. bool값을 반환하는 이항 조건자를 인자로 받는 형태 : 이 조건자는 리스트 원소 타입의 인자를 두 개 받는다.
     * 
     */

    forward_list<int> list2 = {2, 53, 1, 0, 4, 10};
    print(list2);
    list2.reverse();
    print(list2);
    
    list2 = {0, 1, 0, 1, -1, 10, 5, 5, 10, 0};
    print(list2);
    list2.unique();
    print(list2);
 
    list2 = {0, 1, 0, 1, -1, 10, 5, 5, 10, 0};
    print(list2);
    list2.sort();
    print(list2);
    list2.unique();
    print(list2);

    list2.unique([](int a, int b){
        return (b-a) < 2; // 리스트에서 특정 원소가 바로 앞 원소보다 2 이상 크지 않으면 삭제
    });
    print(list2);
 
    return 0;
}