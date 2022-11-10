#include <iostream>
#include <vector>

using namespace std;

void ex2_1 ();
bool fibon_elem (int, int &);

int main(){
    ex2_1();
    return 0;
}

void ex2_1(){
    vector<int> pos;
    int val;
    cout << "Please enter the number of elements : ";

    while(cin >> val)
        pos.push_back(val);

    for(int i = 0; i < pos.size(); ++i){
        int elem;
        if (fibon_elem(pos[i], elem))
            cout << endl << "element #" << pos[i] << "is" << elem << endl;
        else
            cout << "Sorry. Could not calculate element # " << pos[i] << endl;
    }


}

bool fibon_elem (int pos, int & elem){
    if (pos <=0 || pos > 1024){elem = 0; return false;}

    elem = 1;
    int n_2 = 1, n_1 = 1;

    for (int i = 3; i <= pos; ++i){
        elem = n_2 + n_1;
        n_2 = n_1; n_1 = elem;
    }

    return true;
}