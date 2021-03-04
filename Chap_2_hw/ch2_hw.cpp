#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
using namespace std;

bool fibon_elem(int, int &);
void prog1();

void prog2();
bool prog2_is_size_ok (int );
const vector<int>* prog2_penta_seq (int );
bool prog2_penta_elem (int , int &, vector <int> &);
bool prog2_pring_seq (int , int , vector <int> , const string );

void prog5();
int prog5_max(int, int);
float prog5_max(float, float);
string prog5_max(string, string);
int prog5_max(vector <int>);
float prog5_max(vector<float> );
string prog5_max(vector <string>);
int prog5_max(int *, int);
float prog5_max(float*, int);
string prog5_max(string*, int);

void prog6();
template <typename Type>
Type prog6_max( Type , Type  );
template <typename elemType>
elemType prog6_max( const vector<elemType>  );
template <typename arrayType>
arrayType prog6_max( const arrayType *, int  );

int main()
{
	prog1();
	// prog2(); //2~4
	// prog5();
    //prog6();

	return 0; // to quiet vc6++
}

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

void prog2(){
    int num_elem;
    string greet("Please enter the number of elements : ");
    //cout << "Please enter the number of elements : ";
    cout << greet;
    cin >> num_elem;
    int elem;
    vector <int> elems;
    prog2_penta_elem (num_elem, elem,elems);
    prog2_pring_seq (num_elem, elem, elems, "int");
}

inline bool prog2_is_size_ok (int size){
    const int max_size = 1024;
    if (size <=0 || size > max_size){
        cerr << "Oops: requested size is not supported: "
                << size << " -- can't fullfill request .\n";
                return false;
    }
    return true;
}

//计算Pentagonal数列中的size个元素，并返回持有这些元素的静态容器的地址
const vector<int>* prog2_penta_seq (int size){
    static vector<int> elems_seq;
    if (! prog2_is_size_ok(size)){
        return 0;
    }
    for (int ix = elems_seq.size(); ix < size; ++ix){
        elems_seq.push_back((ix + 1)*(3 * (ix + 1)-1)/2);
    }
    return &elems_seq;
}

//返回Pentagonal数列中位置为pos的元素，如果无法支持该位置上的元素，返回false
bool prog2_penta_elem (int pos, int &elem, vector <int> &elems){
    const vector<int>* pseq = prog2_penta_seq(pos);
    if (!pseq){
        elem = 0;
        return false;
    }
    elem = (*pseq)[pos - 1];
    elems = *pseq;
    return true;
}

//打印文字
void prog2_print_msg (const string &msg, ostream &os = cout){
    if (msg.empty())
        return;
    os << msg;
}

//打印数列
bool prog2_pring_seq (int pos, int elem, vector <int> elems, const string msg){
    if (pos <= 0 || pos > 1024){// 
        cerr << "invalid position: " << pos
                << " -- cannot handle request !\n";
        return false;
    }

    cout << "The " << pos << "th Element of the Pentagonal Sequence is "
            << elem <<endl;

    cout << "The Pentagonal Sequence for "
            << pos << " positions: \n\t";
    for (int ix = 0; ix < elems.size(); ++ix){
         cout << elems[ix] << (!((ix+1)%10)?"\n\t": " ");
    }
    cout << endl;    

    cout << "The type of numeric series the vector represents is: " << msg << endl;
    return true;
}

void prog5(){
    int inum_a = 5, inum_b = 8;
    float fnum_a = 5.34, fnum_b = 5.53;
    string string_a = "adrea", string_b = "rwefadva";

    int iarray[]={ 12, 70, 2, 169, 1, 5, 29 };
    vector<int> ivec( iarray, iarray+7 );

    float farray[]={ 2.5, 24.8, 18.7, 4.1, 23.9 };
    vector<float> fvec( farray, farray+5 );
    
    string sarray[]={ "we", "were", "her", "pride", "of", "ten" };
    vector<string> svec( sarray, sarray+6 );

    int max_a = prog5_max(inum_a, inum_b);
    cout << "max_a is: " << max_a << endl;
    float max_b = prog5_max(fnum_a, fnum_b);
    cout << "max_b is: " << max_b << endl;
    string max_c = prog5_max(string_a, string_b);
    cout << "max_c is: " << max_c << endl;
    
    int max_d = prog5_max(ivec);
    cout << "max_d is: " << max_d << endl;
    float max_e = prog5_max(fvec);
    cout << "max_e is: " << max_e << endl;
    string max_f = prog5_max(svec);
    cout << "max_f is: " << max_f << endl;

    int max_g = prog5_max(iarray, 7);
    cout << "max_g is: " << max_g<< endl;
    float max_h = prog5_max(farray, 5);
    cout << "max_h is: " << max_h<< endl;
    string max_i = prog5_max(sarray, 6);
    cout << "max_i is: " << max_i<< endl;
}

inline int prog5_max( int t1, int t2 )
       { return t1 > t2 ? t1 : t2; }
inline float prog5_max( float t1, float t2 )
       { return t1 > t2 ? t1 : t2; }
inline string prog5_max(  string t1,  string t2 )
       { return t1 > t2 ? t1 : t2; }

inline int prog5_max(  vector<int> vec )
       { return *max_element( vec.begin(), vec.end() ); }
inline float prog5_max(  vector<float> vec )
       { return *max_element( vec.begin(), vec.end() ); }
inline string prog5_max(  vector<string> vec )
       { return *max_element( vec.begin(), vec.end() ); }

inline int prog5_max(  int *parray, int size )
       { return *max_element( parray, parray+size ); }
inline float prog5_max(  float *parray, int size )
       { return *max_element( parray, parray+size ); }
inline string prog5_max(  string *parray, int size )
       { return *max_element( parray, parray+size ); }

void prog6(){
    int inum_a = 5, inum_b = 8;
    float fnum_a = 5.34, fnum_b = 5.53;
    string string_a = "adrea", string_b = "rwefadva";

    int iarray[]={ 12, 70, 2, 169, 1, 5, 29 };
    vector<int> ivec( iarray, iarray+7 );

    float farray[]={ 2.5, 24.8, 18.7, 4.1, 23.9 };
    vector<float> fvec( farray, farray+5 );
    
    string sarray[]={ "we", "were", "her", "pride", "of", "ten" };
    vector<string> svec( sarray, sarray+6 );

    int max_a = prog5_max(inum_a, inum_b);
    cout << "max_a is: " << max_a << endl;
    float max_b = prog5_max(fnum_a, fnum_b);
    cout << "max_b is: " << max_b << endl;
    string max_c = prog5_max(string_a, string_b);
    cout << "max_c is: " << max_c << endl;
    
    int max_d = prog5_max(ivec);
    cout << "max_d is: " << max_d << endl;
    float max_e = prog5_max(fvec);
    cout << "max_e is: " << max_e << endl;
    string max_f = prog5_max(svec);
    cout << "max_f is: " << max_f << endl;

    int max_g = prog5_max(iarray, 7);
    cout << "max_g is: " << max_g<< endl;
    float max_h = prog5_max(farray, 5);
    cout << "max_h is: " << max_h<< endl;
    string max_i = prog5_max(sarray, 6);
    cout << "max_i is: " << max_i<< endl;
}

template <typename Type>
inline Type prog6_max( Type t1, Type t2 )
       { return t1 > t2 ? t1 : t2; }

template <typename elemType>
inline elemType prog6_max( const vector<elemType> vec )
       { return *max_element( vec.begin(), vec.end() ); }

template <typename arrayType>
inline arrayType prog6_max( const arrayType *parray, int size )
       { return *max_element( parray, parray+size ); }