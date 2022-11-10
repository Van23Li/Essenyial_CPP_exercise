#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Stack{
    public:
        bool push(const string&);
        bool pop(string &elem);
        bool peek(string &elem);

        bool empty();
        bool full();

        bool find(const string&) const;
        int count(const string&) const;

        int size(){return _stack.size();}
    
    private:
        vector<string> _stack;
};

// 检测是否为空
inline bool Stack::empty(){
    return _stack.empty();
}

// 询问空间是否已满
inline bool Stack::full(){
    return _stack.size() == _stack.max_size();
}

// 查看最后被pushed的数值
bool Stack::peek(string &elem){
    if (empty())    return false;

    elem = _stack.back();
    return true;
}

// push一个数值进去
bool Stack::push (const string &elem){
    if (full())     return false;

    _stack.push_back(elem);
    return true;
}

// 取出最后被pushed的数值
bool Stack::pop(string &elem){
    if (empty()){
        return false;
    }
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

// 查看某值是否存在
bool  Stack::find(const string &elem) const{
    return std::find(_stack.begin(), _stack.end(), elem) != _stack.end();
}

// 统计某值出现的次数
int Stack::count(const string &elem) const{
    return std::count(_stack.begin(), _stack.end(), elem);
}