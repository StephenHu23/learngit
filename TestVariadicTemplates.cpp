#include <iostream>

template<class T>
void print_list(T value)
{
	std::cout << value << std::endl;
}
template<class First, class ...Rest>
void print_list(First first, Rest ...rest)
{
	std::cout << first << ","; 
	print_list(rest...);
}

int main()
{
	print_list(42, "hello", 2.3, 'a');
	return 0;
}