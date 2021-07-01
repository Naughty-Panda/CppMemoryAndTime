//////////////////////////////////////////
//	C++ Memory and Time
//	Naughty Panda @ 2021
//////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>

#include "Timer.h"

template <typename T>
void Print(const std::vector<T>& vec, const std::string& name = "") {

	if (!name.empty()) std::cout << name << ": ";

	for (const auto& i : vec) {
		std::cout << i << ' ';
	}

	std::cout << '\n';
}

template <typename T>
void PrintPtr(const std::vector<T>& vec, const std::string& name = "") {

	if (!name.empty()) std::cout << name << ": ";

	for (const auto& i : vec) {
		std::cout << *i << ' ';
	}

	std::cout << '\n';
}

//////////////////////////////////////////
//	2.1
//////////////////////////////////////////

template <typename T>
void Swap(T& t1, T& t2) {

	T temp = std::move(t1);
	t1 = std::move(t2);
	t2 = std::move(temp);
}

//////////////////////////////////////////
//	2.2
//////////////////////////////////////////

template <typename T>
void SortPointers(std::vector<T>& vec) {

	auto pointer_sort = [](auto& t1, auto& t2) -> bool {
		return *t1 < *t2;
	};

	std::sort(std::begin(vec), std::end(vec), pointer_sort);
}

int main() {

	//////////////////////////////////////////
	//	2.1
	//////////////////////////////////////////

	// Vector swapping
	std::vector<int> vec1{ 1,3,5 };
	std::vector<int> vec2{ 2,4,6,8 };

	std::cout << "Vector before swap:\n";
	Print(vec1, "vec1");
	Print(vec2, "vec2");

	Swap(vec1, vec2);
	std::cout << "\nVector after swap:\n";

	Print(vec1, "vec1");
	Print(vec2, "vec2");

	// String swapping
	std::string str1{ "Hello" };
	std::string str2{ "world!" };

	std::cout << "\nString before swap:\n";
	std::cout << str1 << ' ' << str2 << '\n';

	Swap(str1, str2);

	std::cout << "\nString after swap:\n";
	std::cout << str1 << ' ' << str2 << '\n';

	//////////////////////////////////////////
	//	2.2
	//////////////////////////////////////////

	// Int pointer sorting
	std::vector<int*> vecptr;
	int a(1), b(2), c(3), d(4), e(5);
	vecptr.push_back(&b);
	vecptr.push_back(&e);
	vecptr.push_back(&d);
	vecptr.push_back(&a);
	vecptr.push_back(&c);

	std::cout << "\nInt* vector before sorting:\n";
	PrintPtr(vecptr, "VecPtr");
	Print(vecptr, "VecPtr &");

	SortPointers(vecptr);

	std::cout << "\nInt* vector after sorting:\n";
	PrintPtr(vecptr, "VecPtr");
	Print(vecptr, "VecPtr &");

	// Char pointer sorting
	std::vector<char*> charptr;
	char ch1('a'), ch2('b'), ch3('c'), ch4('d'), ch5('e');
	charptr.push_back(&ch4);
	charptr.push_back(&ch1);
	charptr.push_back(&ch5);
	charptr.push_back(&ch3);
	charptr.push_back(&ch2);

	std::cout << "\nChar* vector before sorting:\n";
	PrintPtr(charptr, "CharPtr");
	Print(charptr, "CharPtr &");

	SortPointers(charptr);

	std::cout << "\nChar* vector after sorting:\n";
	PrintPtr(charptr, "CharPtr");
	Print(charptr, "CharPtr &");
}
