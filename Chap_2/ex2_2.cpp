#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

const vector<int>* pent_seq(int);
template <typename elemType>
void print_seq(const vector<elemType> &, string);

int main(){
    const vector<int>* seq;
    string msg = "int";

    seq = pent_seq(4);
    print_seq(*seq, msg);

    return 0;
}

const vector<int>* pent_seq(int size){
    if (size <= 0 || size > 1024){
        cerr << "Warning: pent_seq(): "
                    << size << "not support -- resetting to 8\n";
        size = 8;
    }

    static vector<int> elems;
    for (int ix = 0; ix < size; ++ ix){
        elems.push_back((ix + 1) * (3 * ix + 2)/2);
    }

    return &elems;
}

template <typename elemType>
void print_seq(const vector<elemType> &elems, string msg){
    cout << endl << "The Pentagonal Sequence is: ";
    for (int ix = 0; ix < elems.size(); ++ix){
        elemType t = elems[ix];
        cout << t << ' ';
    } 

    cout << endl << "The type of numeric series the vector represents is: " << msg << endl;
}