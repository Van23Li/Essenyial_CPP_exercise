#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename iteratorType, typename elemType>
iteratorType find (iteratorType first, iteratorType last, const elemType &value){
    for (; first != last; ++ first){
        if (*first == value){
            return first;
        }
    }
    return last;
}

int main(){
    const int asize = 8;
    int ia[asize] = {1, 1, 2, 3, 5, 8, 13, 21};

    vector<int> ivec(ia, ia + asize);
    list<int> ilist(ia, ia + asize);

    int *pia = find(ia, ia + asize, 1024);
    if (pia != ia + asize){
        //找到了
    }

    vector<int>::iterator it;
    it = find(ivec.begin(), ivec.end(), 1024);
    if (it != ivec.end()){
        //找到了
    }

    list<int>::iterator iter;
    iter  = find(ilist.begin(), ilist.end(), 1024);
    if (iter != ilist.end()){
        //找到了
    }
}