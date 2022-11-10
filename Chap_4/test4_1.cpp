#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

void prog_1();
void prog_2();

void prog_1(){
    Stack st;
    string str;

	cout << "Please enter a series of strings.\n";
    while ( cin >> str && ! st.full() )
            st.push( str );
            
    if ( st.empty() ) {
         cout << '\n' << "Oops: no strings were read -- bailing out\n ";
         return;
	 }

    st.peek( str );
    if ( st.size() == 1 && str.empty() ) {
         cout << '\n' << "Oops: no strings were read -- bailing out\n ";
         return;
	 }

    cout << '\n' << "Read in " << st.size() << " strings!\n"
		   << "The strings, in reverse order: \n";

    while ( st.size() ) 
		 if ( st.pop( str ))
	         cout << str << ' ';
	
	cout << '\n' << "There are now " << st.size() 
		  << " elements in the stack!\n";
}

void prog_2(){
    Stack st;
    string str;
    string find_str;

	cout << "Please enter a series of strings.\n";
    while ( cin >> str && ! st.full() )
            st.push( str );
    
    cout << '\n'
	     << "Read in " << st.size() << " strings!\n";

	cin.clear();

    cout << "What word to search for?\n";
    cin >> find_str;

    if (st.find(find_str))       cout << "Element found: " << find_str << "\n";
    else        cout << "Didn't find it!\n" ;
    
    cout << find_str << " appears " << st.count(find_str) << " times\n";

}

using namespace std;

int main(){
    // prog_1();
    prog_2();
}
