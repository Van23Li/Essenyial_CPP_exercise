#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<int>* pent_seq(int);
template <typename elemType>
void print_seq(int, int, const vector<elemType> &, string);
bool is_size_ok(int);
bool pent_elem(int,  int &, vector <int> &);

int main(){
    int num_seq;
    cout << "Please enter the number of elements : ";
    cin >> num_seq;
    int elem;
    vector <int> elems;
    string msg = "int";

    pent_elem (num_seq, elem, elems);
    print_seq(num_seq, elem, elems, msg);

    return 0;
}

bool pent_elem(int pos,  int &elem, vector <int> &elems){
    if (! is_size_ok(pos)) return 0;

    const vector<int>* seq = pent_seq(pos);
    elem = (*seq)[pos -1];
    elems = *seq;
    return true;
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
void print_seq(int pos, int elem, const vector<elemType> &elems, string msg){
    cout << endl << "The " << pos << "th element of Pentagonal Sequence is: " << elem << endl;

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