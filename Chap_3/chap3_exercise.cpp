#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

const int * find (const vector<int> &vec, int value){
    
    for (int ix = 0; ix < vec.size(); ++ ix){
        if (vec[ix] == value){
            //cout<<endl<<vec[ix]<<endl<<&vec[ix]<<endl<<typeid(vec[ix]).name()<<endl;
            return &(vec[ix]);
        }
    }
    return 0;
}

template <typename elemType>
const elemType * find_tem (const vector<elemType> &vec, elemType value){
    for (int ix = 0; ix < vec.size(); ++ ix){
        if (vec[ix] == value){
            //cout<<endl<<vec[ix]<<endl<<&vec[ix]<<endl<<typeid(vec[ix]).name()<<endl;
            return &(vec[ix]);
        }
    }
    return 0;
}

int main(){
    cout << endl <<"Please enter a value: ";
    float pos;
    cin >> pos;

    cout << "Please enter a vector: ";
    vector<float> vec;
    float ival;
    while(cin >> ival)
    vec.push_back(ival);

    const float* result;
    result = find_tem(vec, pos);
    cout << "The point of the " << pos << " is " << result <<endl<< " and " <<endl<< *result << endl;
	return 0; 
}