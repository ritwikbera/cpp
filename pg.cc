#include <bits/stdc++.h>
using namespace std;


class Base {
public:
    int f = 2;
    Base(){

        int a=2;
    }
    virtual void increment(int& a){
        a++;
    }

};

class Child : public Base{
public:
    int f = 3;
    virtual void increment(int& a){
        a = a+2;
    }
};

namespace utility {

    template <typename T>
    void compare(T a, T b){
        cout << "Same" << endl;
    }

    template <typename T, typename S>
    void compare(T a, S b){
        cout << "different" << endl;
    }
};

template<typename T>
string in_(vector<T> v, T x){
    auto ans = find(v.begin(), v.end(), x) != v.end() ? "true" : "false";
    return ans;
}

template <typename K, typename V>
void update_map(map<K,V>& m, initializer_list<pair<K, V>> l)
{
  for (const auto& p : l){
        m[p.first] = p.second;
  }
}




int main(int argc, char const *argv[])
{   
    int a, b;
    tie(a,b) = make_pair<int>(2,3);
    cout << a << b << endl;
    const auto c = make_shared<int>(4);
    cout << *c << endl;
    auto d = c;
    if(true){
        auto a = d;
        cout << a.use_count() << endl;
    }
    (*d)++;
    cout << *c << endl;
    cout << d.use_count() << endl;
    cout << typeid(d).name() << endl;

    int* k = new int(3);
    int* j = k;

    Base* base = new Child();
    // (*base).increment(*j);
    base -> increment(*j);
    cout << *j << endl;

    vector<Base> list;
    for (int i=0; i<10; i++){
        list.emplace_back(Child());
    }

    for (auto& it : list){
        cout << it.f << ' ';
    }

    cout << endl;
    vector<pair<int, int>> v = {{3,4},{4,4}};
    cout << v[0].first << endl;

    utility::compare(2, 3);
    utility::compare(2, 'a');

    pair<int, int> x(3, 4);

    cout << in_(v,x) << endl;

    map<int, int> m { {1, 10}, {2, 20} };
    update_map(m, {{1, 150}, {5, 500}});

    for (const auto& p : m){
        std::cout  << "{" << p.first << ", " << p.second << "}\n";
    }


    return 0;
}