#include <iostream>
#include <algorithm>
#include <forward_list>

using namespace std;
/**
 * @brief forward_list
 * �� ó�� ���ҿ� �����ϴ� front() �Լ��� ���� but, �ݴ� ������ ���ҷ� �̵��ϴ� back()�� ���� x 
 * ������ ����, ����, ���� ������, ������ ���� ��� ����
 */

template <typename T>
void print(forward_list<T> fwd_list){
    
    for(auto it = fwd_list.begin(); it != fwd_list.end(); it++){ 
        // it�� Ÿ���� int�� �ƴ�. �����Ѱ���
      cout << *it << " ";  
    }
    cout << endl;
    return;
}


int main(){


    /**
     * push_front : ���� ����Ʈ �� �տ� ���ο� ���Ҹ� ����
     * insert_after : Ư�� ��ġ�� ���Ҹ� ����
     *      - ���� ����Ʈ���� ���ο� ���Ҹ� ������ ��, �ش� ��ġ �տ� �ִ� ������ next �����͸� �����ؾ� �ϱ� �����̴�.
     *      - �ݴ� �������� �̵��ϴ� ���� ���x ���� Ư�� ���� �ڿ� ���ο� ���� ���� ��, �ش� ������ next �����͸� �����ϴ� ���� Ÿ���ϴ�.
     * ���� ����Ʈ���� ���� ���� �� �ٸ� ���Ҹ� �̵��� �ʿ䰡 ����.
     * ���� �Լ��� ����Ʈ�� ���� ũ�⿡ ������ ���� �ʴ´�.
     */

    // ���� ����Ʈ�� ���Ҹ� �����ϴ� �پ��� �ڵ� ����
    forward_list<int> fwd_list = {1, 2, 3};
    print(fwd_list);
    fwd_list.push_front(0); // �� �տ� 0 �߰� : {0, 1, 2, 3}
    print(fwd_list);
    auto it = fwd_list.begin();
    fwd_list.insert_after(it, 5); // �� ó�� ���� �ڿ� 5 �߰� : {0, 5, 1, 2, 3}
    print(fwd_list);
    fwd_list.insert_after(it, 6); // �� ó�� ���� �ڿ� 6 �߰� : {0, 6, 5, 1, 2, 3}
    print(fwd_list);

    cout << endl << endl;
    /**
     * pop_front() : ����Ʈ�� �� ó�� ���Ҹ� ����. ���� �̵��� �ʿ� x 
     * erase_after() : �� ���� ���·� ����
     *      1. Ư�� ���Ҹ� ����Ű�� �ݺ��ڸ� ���ڷ� �޾Ƽ� �ٷ� ���� ��ġ�� ���Ҹ� ����
     *      2. ���� ������ ��� : ������ ������ ���� ���� '��'�� ����Ű�� �ݺ��ڿ� ������ ���� �� ���Ҹ� ����Ű�� �ݺ��ڸ� ���ڷ� ����
     */

    forward_list<int> fwd_list2 = {1, 2, 3, 4, 5};
    print(fwd_list2);
    fwd_list2.pop_front(); // �� �� ���Ҹ� ���� {2, 3, 4, 5}
    print(fwd_list2);
    auto it2 = fwd_list2.begin();
    cout << "it�� type : " << typeid(it2).name() << endl; // it2�� Ÿ���� int�� �ƴ�
    fwd_list2.erase_after(it2); // �� ���� ���� ���Ҹ� ���� : {2, 4, 5}
    print(fwd_list2);
    fwd_list2.erase_after(it2, fwd_list2.end()); // �� �� ���� �������� ������ ���� : {2}
    print(fwd_list2);

    /**
     * remove() : ������ ���� �� �ϳ��� �Ű������� �޴´�.
     *      - ����� ������ Ÿ�Կ� ���ǵ� ��ȣ �����ڸ� ����Ͽ� ���޵� ���� ��ġ�ϴ� ��� ���Ҹ� ã�� �����Ѵ�.
     *      - ����� ������ Ÿ�Կ��� ��ȣ ������ �������� ������ remove()�Լ� ��� �Ұ�. ���� �߻�
     *      - ���� ��ȣ ���꿡 �ٰ��Ͽ� ���Ҹ� ����.
     * remove_if() : ������ ���� �� �ϳ��� ���ڷ� �޴´�.
     *      - bool ���� ��ȯ�ϴ� ������ �Լ��� ���ڷ� �޴´�.
     *      - �����ڰ� true�� ��ȯ�ϴ� ��� ������ ���Ҹ� ����Ʈ���� ����.
     *      - ������ �ڸ��� ���� ǥ������ ��� ����
     * 
     */
    return 0;
}