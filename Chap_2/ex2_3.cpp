#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

const vector<int>* pent_seq(int);
template <typename elemType>
void print_seq(const vector<elemType> &, string);
bool is_size_ok(int);

int main(){
    const vector<int>* seq;
    string msg = "int";

    cout << "Please enter the number of elements : ";
    int num_seq;
    cin >> num_seq;
    seq = pent_seq(num_seq);
    print_seq(*seq, msg);

    return 0;
}

const vector<int>* pent_seq(int size){
    if (! is_size_ok(size)){
        cout << " -- resetting to 8\n";
        size = 8;
    }

    static vector<int> elems;
    for (int ix = elems.size(); ix < size; ++ ix){
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

inline bool is_size_ok(int size){
    if (size <= 0 || size > 1024){
        cerr << "Warning: pent_seq(): "
                    << size << "not support\n";
        return false;
    }
    return true;
}