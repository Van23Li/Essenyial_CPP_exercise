#include <iostream>
#include <vector>
using namespace std;

template <typename elemType>
const elemType* find (const elemType* first, const elemType* last, const elemType &value){
    if (! first || ! last){
        return 0;
    }

    for (; first != last; ++ first){
        if (*first == value){
            return first;
        }
    }

    return 0;
}

template <typename elemType>
inline const elemType* begin(const vector<elemType> &vec){
    return vec.empty() ? 0 : &vec[0];
}

template <typename elemType>
inline const elemType* end(const vector<elemType> &vec){
    return vec.empty() ? 0 : &vec[vec.size()];
}

int main(){
    const int                                 ia[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    const vector<int>               iv(ia, ia + 8);
    const double                        da[6] = {1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
    const vector<double>      dv(da, da + 6);
    const string                           sa[4] = {"pooh", "piglet", "eeyore", "tigger"};
    const vector<string>         sv(sa, sa + 4);

    const int                                 *pi = find(ia, ia + 8, ia[3]);
    const int                                 *piv = find(begin(iv), end(iv), iv[3]);
    const double                        *pd = find(da, da + 6, da[3]);
    const double                        *pdv = find(begin(dv), end(dv), dv[3]);
    const string                           *ps = find(sa, sa + 4, sa[3]);
    const string                           *psv = find(begin(sv), end(sv), sv[3]);

    cout << "pi = "<< pi << endl << "pd = "<< pd << endl << "ps = "<< ps << endl;
    cout << "*pi = "<< *pi << endl << "*pd = "<< *pd << endl << "*ps = "<< *ps << endl;
    cout << "piv = "<< piv << endl << "pdv = "<< pdv << endl << "psv = "<< psv << endl;
    cout << "*piv = "<< *piv << endl << "*pdv = "<< *pdv << endl << "*psv = "<< *psv << endl;

    return 0;
}








/*
#include <iostream>
#include <vector>
using namespace std;

template <typename elemType>
 elemType* find ( elemType* first,  elemType* last,  elemType &value){
    if (! first || ! last){
        return 0;
    }

    for (; first != last; ++ first){
        if (*first == value){
            return first;
        }
    }

    return 0;
}

template <typename elemType>
inline  elemType* begin( vector<elemType> &vec){
    return vec.empty() ? 0 : &vec[0];
}

template <typename elemType>
inline  elemType* end( vector<elemType> &vec){
    return vec.empty() ? 0 : &vec[vec.size()];
}

int main(){
     int                                 ia[8] = {1, 1, 2, 3, 5, 8, 13, 21};
     vector<int>               iv(ia, ia + 8);
     double                        da[6] = {1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
     vector<double>      dv(da, da + 6);
     string                           sa[4] = {"pooh", "piglet", "eeyore", "tigger"};
     vector<string>         sv(sa, sa + 4);

     int                                 *pi = find(ia, ia + 8, ia[3]);
     vector<int>               *piv = find(begin(iv), end(iv), iv[3]);
     double                        *pd = find(da, da + 6, da[3]);
     vector<int>               *piv = find(begin(dv), end(dv), dv[3]);
     string                           *ps = find(sa, sa + 4, sa[3]);
     vector<int>               *piv = find(begin(sv), end(sv), sv[3]);

    cout << "pi = "<< pi << endl << "pd = "<< pd << endl << "ps = "<< ps << endl;
    cout << "*pi = "<< *pi << endl << "*pd = "<< *pd << endl << "*ps = "<< *ps << endl;

    return 0;
}
*/