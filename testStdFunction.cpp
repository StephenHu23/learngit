#include <iostream>
#include <functional>
//#include "Student.h"
class A
{
public:
	A() = default;
	void registerHandler(const std::function<int(int)> &f) { handler = f; };
	int funA(int a) { return handler(a); };
private:
	std::function<int(int)> handler;
};

class B
{
public:
	B(A a) :a(a) { 
		std::function<int(int)> f = [this](int x) {return funB(x); };
		a.registerHandler(f);
		std::cout << a.funA(3) << std::endl;
	};
	int funB(int b) { return 2 * b; };
private:
	A a;
};

int main()
{
	A a;
	B b(a);
	return 0;
}