#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool less_than (int v1, int v2){
    return v1 < v2 ? true : false;
}

bool greater_than (int v1, int v2){
    return v1 > v2 ? true : false;
}

vector<int> filter(const vector<int> &vec, int filter_value, bool (*pred)(int, int))){
    vector <int> nvec;

    for (int ix = 0; ix < vec.size(), ++ix){
        if (pred(vec[ix], filter_value)){
            nvec.push_back(vec[ix]);
        }
    }
    return nvec;
}