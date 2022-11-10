#include <vector>

using namespace std;

template <typename elemType>
elemType* find (vector<elemType> &, const elemType &);

int main(){
    const int seq_size = 5;
    int vec_arr[seq_size] = {1, 2, 3, 4, 5};

    vector<int> vec(vec_arr, vec_arr + seq_size);
    int * max_name = find(vec, 3);
}

template <typename elemType>
elemType* find (vector<elemType> &vec, const elemType &value){
    for (int ix = 0; ix < vec.size(); ++ix){
        if (vec[ix] == value)
            return &vec[ix];
        return 0;
    }
}