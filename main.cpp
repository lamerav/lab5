#include <iostream>
#include <vector>
#include <random>

using namespace std;


void oddEvensort(vector<int> &m, char s = ' ')
{
    if (s == '-')
    {
        for (int i = 0; i < m.size(); i++) {
            if (i % 2 == 0) {
                for (int j = 2; j < m.size(); j += 2) {
                    if (m[j] > m[j - 1]) {
                        swap(m[j - 1], m[j]);
                    }
                }
            } else {
                for (int j = 1; j < m.size(); j += 2) {
                    if (m[j] > m[j - 1]) {
                        swap(m[j - 1], m[j]);
                    }

                }
            }
        }
    }
    else
    {
        for (int i = 0; i < m.size(); i++) {
            if (i % 2 == 0) {
                for (int j = 2; j < m.size(); j += 2) {
                    if (m[j] < m[j - 1]) {
                        swap(m[j - 1], m[j]);
                    }
                }
            } else {
                for (int j = 1; j < m.size(); j += 2) {
                    if (m[j] < m[j - 1]) {
                        swap(m[j - 1], m[j]);
                    }

                }
            }
        }
    }

}


void print(vector<int> const& vec){
    for (int const& v: vec)
        cout << v << " ";
    cout << endl;
}

ostream &operator <<(ostream &os, const vector<int> &c)
{
    for (int i = 0; i < c.size(); i++)
    {
        os << c[i];
        os << " ";
    }
    return os;
}

vector<int> operator + (vector<int> &vec1,vector<int> &vec2){
    if (vec1.size() < vec2.size()){
        for (int i = vec1.size() - 1 ; i < vec2.size(); i++){
            vec1.push_back(0);
        }
    }
    else if (vec1.size() > vec2.size()){
        for (int i = vec2.size() - 1 ; i < vec1.size(); i++){
            vec2.push_back(0);
        }
    }
    vector<int> tmpvec;
    for (int i = 0; i < vec1.size(); i++){
        tmpvec.push_back(vec1[i] + vec2[i]);
    }
    return tmpvec;
}


int main(int argc, char* argv[])
{
    random_device rd;
    cout << "Task 1" << endl;

    int len;
    char s;
    cout << "Enter length of vec: " << endl;
    cin >> len;
    cout << endl;
    vector<int> vec(len);
    for (int i = 0; i < len; i++){
        vec[i] = rd() % 1000;
    }
    oddEvensort(vec);
    cout << vec;
    cout << endl;

    cout << "Task 2" << endl;

    int len1, len2;

    cout << "Enter length of first vec" << endl;
    cin >> len1;
    cout << endl;
    vector<int> vec1(len1);
    for (int i = 0; i < len1; i++){
        vec1[i] = rd() % 1000;
    }

    cout << "Enter length of second vec" << endl;
    cin >> len2;
    cout << endl;
    vector<int> vec2(len2);
    for (int i = 0; i < len2; i++){
        vec2[i] = rd() % 1000;
    }
    cout << vec1;
    cout << vec2;
    vector<int> anotherVec(vec1 + vec2);
    anotherVec.erase(anotherVec.end() - 1);
    cout << anotherVec;


    cout << "Task 3" << endl;

    int len3, a;
    cout << "Enter length vector: " << endl;
    cin >> len3;
    cout << endl;
    vector<int> vec3;
    cout << "Enter values of vector:" << endl;
    for (int i = 0; i < len3; i++){
        cin >> a;
        vec3.push_back(a);
    }
    cout << "Your vec before sort: " << endl;
    cout << vec3;
    cout << "Enter - if vector of youe vec is minus" << endl;
    char qs;
    cin >> qs;
    oddEvensort(vec3, qs);
    cout << "Your vec after sort: " << endl;
    cout << vec3;
    cout << "Enter length of your vectors:" << endl;
    int len4, c, b;
    cin >> len4;
    cout << "Enter your first vector:" << endl;
    vector<int> vec4;
    for (int i = 0; i < len4; i++) {
        cin >> c;
        vec4.push_back(c);
    }
    cout << "Enter your second vector:" << endl;
    vector<int> vec5;
    for (int i = 0; i < len4; i++) {
        cin >> c;
        vec5.push_back(c);
    }
    cout << "Sum elements of yours vectors is vector: " << endl;
    cout << vec4 + vec5;

    return 0;
}
