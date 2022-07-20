#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
class dynamic_array{
    T* data;
    size_t n;

public: 
    // �迭 ũ�⸦ ���ڷ� �޴� ������ �߰�
    dynamic_array(int n){
        this->n = n;
        data = new T[n];
    }

    // ���� ������ �߰�
    dynamic_array(const dynamic_array<T>& other){
        n = other.n;
        data = new T[n];

        for(int i = 0; i<n; i++){
            data[i] = other[i];
        }
    }

    // ��� �����Ϳ� ���� ������ ���� []�����ڿ� at() �Լ� �ۼ�. array�� ����� ������� �迭 ���ҿ� ���� ��������
    T& operator[](int index){
        return data[index];
    }

    const T& operator[](int index) const{
        return data[index];
    }

    T& at(int index){
        if(index < n){
            return data[index];
        }
        throw "Index out of range -SungEun-";
    }

    // �迭 ũ�⸦ ��ȯ�ϴ� size() ��� �Լ��� �Ҹ��ڸ� ����. 
    // �Ҹ��ڿ����� �޸� ���� �����ϱ� ���� �Ҵ�� �޷θ��� ����
    size_t size() const{
        return n;
    }

    ~dynamic_array(){
        delete[] data; // �޸� �� ����
    }

    // dynamic_array�� �迭 ���Ҹ� ��ȸ�� �� ����� �ݺ��� ���� �Լ��� ����
    T* begin() {return data;}
    const T* begin() const {return data;}
    T* end() {return data + n;}
    const T* end() const {return data + n;}

    // �� �迭�� �ϳ��� ��ġ�� ������ �����ϴ� +������ �Լ��� ����
    // �� �Լ��� friend�� ����
    friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2){
        dynamic_array<T> result(arr1.size() + arr2.size());
        copy(arr1.begin(), arr1.end(), result.begin()); // result.begin���� arr1�� �ϴ� ����
        copy(arr2.begin(), arr2.end(), result.begin() + arr1.size()); // result.begin���� ������ arr1 �ٷ� �ں��� arr2 ����

        return result;
    }

    // �迭�� ����� ��� �����͸� ���ڿ��� ��ȯ�ϴ� to_string() ��� �Լ� �ۼ�
    // �� �Լ��� ������ ������ ���� ���ڿ� sep�� ���ڷ� ������, sep�� �⺻���� ��ǥ(", ")�� ����
    string to_string(const string& sep = ", "){
        if(n == 0) return "";

        ostringstream os;
        os << data[0];

        for(int i = 1; i<n; i++){
            os << sep << data[i]; // �̶� os << data[i] �� �κ��� << ǥ�� ����� ������ �ؿ��� �׷��� ��¹���� ����.
        }
        return os.str();
    }
};

// �л� ������ ������ ����ü ����. << �����ڸ� �̿��� ǥ�� ����� ����
struct student
{
    /* data */
    string name;
    int standard;
};

ostream& operator<<(ostream& os, const student& s){
    return (os << "[" << s.name << ", " << s.standard << "]");
}

int main(){
    int nStudent;
    cout << "1�� �л� ���� �Է��ϼ���: ";
    cin >> nStudent;

    dynamic_array<student> class1(nStudent);
    for(int i = 0; i<nStudent; i++){
        string name;
        int standard;
        cout << i + 1 << "��° �л� �̸��� ���̸� �Է��ϼ���: ";
        cin >> name >> standard;
        class1[i] = student{name, standard};
    }

    // �迭 ũ�⺸�� ū �ε����� �л��� ����
    try{
        // �Ʒ� �ּ��� �����ϸ� ���α׷��� ������ �����մϴ�.
        // class1[nStudent] = student {"John", 8}; // ������ �� ���� ����

        class1.at(nStudent) = student{"John", 8}; // ���� �߻�
    }
    catch (...)
    {
        cout << "���� �߻�!" << endl;
    }

    // ���� ����
    auto class2 = class1;
    cout << "1���� �����Ͽ� 2�� ����: " << class2.to_string("�׸���") << endl;
    cout << class2[1] << endl;
    // �� �б��� ���ļ� ���ο� ū �б��� ����
    auto class3 = class1 + class2;
    cout << "1�ݰ� 2���� ���� 3�� ����: " << class3.to_string("�׸���") << endl; 

    return 0;
}



