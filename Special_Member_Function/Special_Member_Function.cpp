#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class _SMF
{
public:
	_SMF() : p(nullptr) {
		cout << "Default constructor" << endl;
	}													// default ctor
	_SMF(string _str) :
		p(new string(_str)) {
		cout << "Constructor with parameters" << endl;
	}													// ctor with params	
	_SMF(const _SMF& _obj) : p(new string(*_obj.p)) {
		cout << "Copy constructor" << endl;
	}													// copy ctor
	_SMF& operator=(const _SMF& _obj) {
		cout << "Copy assignment" << endl;
		delete p;
		p = new string(*_obj.p);
		return *this;
	}													// copy assign
	_SMF(_SMF&& _obj): p(_obj.p) {
		cout << "Move constructor" << endl;
		_obj.p = nullptr;
	}													// move ctor
	_SMF& operator=(_SMF&& _obj) {
		cout << "Move assignment" << endl;
		delete p;
		p = _obj.p;
		_obj.p = nullptr;
		return *this;
	}													// move assign
	~_SMF()
	{
		cout << "Destructor" << endl;
		delete p;
		p = nullptr;
	}													// destructor

	_SMF operator+(const _SMF& _right_operand) {
		return _SMF(*p + *_right_operand.p);
	}
private:
	string* p;
};

_SMF _createObj() {
//	return _SMF("Hello ");
	_SMF _obj("Hello ");
	return _obj;
}


int main()
{
	setlocale(LC_ALL, "");
	_SMF defCtor;
	_SMF paramCtor("Test");
	_SMF copyCtor = paramCtor;
	_SMF copyAssign;
	copyAssign = paramCtor;
	_SMF moveConst = _createObj();
	moveConst = moveConst + _SMF("World!");
	return 0;
}