#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int ex1_5_cstyle(){
        const int num_size = 12;
        char user_name[num_size];

        cout << "Paease enter your name: ";
        cin >> setw(num_size) >> user_name;

        switch (strlen(user_name)){
                case 11:
                        cout << "That is a very big name, indeed -- "
				 << "we may have needed to shorten it!\n"
				 << "In any case,\n";
                default:
                        cout << "Hello, " << user_name
                                 << " -- happy to make your acquaintance!\n";
			break;
        }
        return 0;
}


#include <iostream>
#include <string>
using namespace std;

int ex1_5_string(){
        string user_name;

        cout << "Paease enter your name: ";
        cin >> user_name;

        switch (user_name.size()){
                case 0:
                        cout << "Ah, the user with no name. "
                                << "Well, ok, hi, user with no name\n";
                        break;

                case 1:
                        cout << "A 1-character name? Hmm, have you read Kafka?: "
                                << "hello, " << user_name << endl;
                        break;

                default:
                        cout << "Hello, " << user_name
                                 << " -- happy to make your acquaintance!\n";
			break;
        }
        return 0;
}


#include <iostream>
#include <vector>
using namespace std;

int ex1_6_vector(){
        vector <int> ivec;
        int ival;

        while(cin >> ival)
                ivec.push_back(ival);  //将一个新的元素加到vector的最后面，
                                                                //位置为当前最后一个元素的下一个元素

        int sum = 0;
        for(int ix = 0; ix < ivec.size(); ++ix){
                cout << endl << ix << ")" << ivec[ix];
                sum += ivec[ix];
        }


        int average = sum / ivec.size();
        cout << endl << "Sum of " << ivec.size()
                << " elements: " << sum
                << ". Average: " << average << endl;
}


void ex1_6_array() {
        const int arr_size = 128;
        int iarr[arr_size];
        int ival, icnt = 0;

        while (cin >> ival && icnt <= arr_size){
                ia[icnt++] = ival;
        }

        int sum = 0;
        for (int ix = 0; ix < icnt; ++ix){
                sum +=ia[ix];
        }

        int average = sum / icnt;
        cout << endl << "Sum of " << icnt
                << " elements: " << sum
                << ". Average: " << average << endl;
}


int main() {

	// ex1_5_string();
	// ex1_5_cstyle();
	// ex1_6_vector();
	// ex1_6_array();
	int rev_val = ex1_7();

	
	// ex1_xtra1();
	// ex1_xtra2();	
	return 0; // quiets vc++
}