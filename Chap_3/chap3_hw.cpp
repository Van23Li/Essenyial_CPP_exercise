#include <iostream>
#include <map>
#include <fstream>
#include <set>
using namespace std;

void initialize_exclusion_set( set<string>& );
void process_file( map<string,int>&, const set<string>&, ifstream& );
void user_query( const map<string,int> );
void display_word_count( const map<string,int>&, ofstream& );

void ex3_1(){
    ifstream ifile( "chap3.txt" );
	ofstream ofile( "chap3.map" );

    if ( !  ifile || ! ofile ){
         cerr << "Unable to open file -- bailing out!\n";
         return;
    }
    else{
        set<string> word_exclusion;
        initialize_exclusion_set( word_exclusion );         //初始化set

        map<string, int> word_count;
        process_file( word_count, word_exclusion, ifile );
        user_query( word_count );
        display_word_count( word_count, ofile );
    }
}

void initialize_exclusion_set (set<string> &exs){
    static string excluded_words[6] = {"a","an","or","the","and","but",};
    exs.insert( excluded_words, excluded_words + 6 );
}

void process_file(map<string,int> &word_count, const set<string> &word_exclusion, ifstream &ifile ){
    string word;

    while ( ifile >> word ){
       // if word is within set, skip
       if ( word_exclusion.count( word ))
            continue; 

       word_count[ word ]++;
    }
}

void user_query( map<string,int> word_map ){
    string search_word;
    cout << "Please enter a word to search: q to quit ";
    cin >> search_word;
    while ( search_word.size() && search_word != "q" ){
        map<string,int>::const_iterator it;
            if (( it = word_map.find( search_word )) != word_map.end() )
                 cout << "Found! "  << it->first
                      << " occurs " << it->second
                      << " times.\n";
              else cout << search_word 
                        << " was not found in text.\n";
              cout << "\nAnother search? (q to quit) ";
              cin >> search_word;
    }

}

void display_word_count(const map<string,int> &word_map, ofstream &os ){
    map<string,int>::const_iterator iter = word_map.begin(),  end_it = word_map.end();
    while ( iter != end_it ) {
            os << iter->first  << " ( "
               << iter->second << " )" << endl;
			++iter;
	 }
     os << endl;
}
int main(){
    ex3_1();

}
