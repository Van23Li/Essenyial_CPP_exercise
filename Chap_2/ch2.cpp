#include <iostream>
#include <vector>
using namespace std;

bool fibon_elem(int, int &);

bool fibon_elem( int pos, int &elem){
    if (pos <=0 || pos > 1024){
        elem = 0;
        return false;
    }

    elem = 1;
    int n_2 = 1, n_1 = 1;

    for (int ix = 3; ix <= pos; ++ix){
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
    }

    return true;
}

void prog1(){
    cout << "Please enter a position: ";

    vector <int> pos;
    int ival;
    while(cin >> ival)
        pos.push_back(ival);

    for (int ix = 0; ix < pos.size(); ++ix){
        int elem;
        if (fibon_elem(pos[ix], elem))
            cout <<endl << "element # " << pos[ix]
                    << " is " << elem << endl;
        else cout << "Sorry. Could not calculate element # "
                            << pos[ix] << endl;
    } 
}


int main()
{
	prog1();
	// prog2();
	// prog2a();
	// prog2b();
	// prog2c();
	// prog3();
	// prog4();

	return 0; // to quiet vc6++
}