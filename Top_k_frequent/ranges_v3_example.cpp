// for_each with associative containers
// output
// set:           1 2 3 4 5 6
// map:           one:1 three:3 two:2
// unordered_map: three:3 one:1 two:2
// unordered_set: 6 5 4 3 2 1

#include <iostream>
#include <map>
#include <range/v3/algorithm/for_each.hpp>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
using std::cout;
using std::string;

auto print = [](int i) { cout << i << ' '; };
// must take a pair for map types
auto printm = [](std::pair<string, int> p) {
	cout << p.first << ":" << p.second << ' ';
};

int
main()
{
	cout << "set:           ";
	std::set<int> si{ 1, 2, 3, 4, 5, 6 };
	ranges::for_each(si, print);

	cout << "\nmap:           ";
	std::map<string, int> msi{ {"one", 1}, {"two", 2}, {"three", 3} };
	ranges::for_each(msi, printm);

	cout << "\nunordered map: ";
	std::unordered_map<string, int> umsi{ {"one", 1}, {"two", 2}, {"three", 3} };
	ranges::for_each(umsi, printm);

	cout << "\nunordered set: ";
	std::unordered_set<int> usi{ 1, 2, 3, 4, 5, 6 };
	ranges::for_each(usi, print);
	cout << '\n';
}

// Check if a container is sorted
// output
// vector:   true
// array:    false

#include <array>
#include <iostream>
#include <range/v3/algorithm/is_sorted.hpp> // specific includes
#include <vector>
using std::cout;

int
main()
{
	cout << std::boolalpha;
	std::vector<int> v{ 1, 2, 3, 4, 5, 6 };
	cout << "vector:   " << ranges::is_sorted(v) << '\n';

	std::array<int, 6> a{ 6, 2, 3, 4, 5, 6 };
	cout << "array:    " << ranges::is_sorted(a) << '\n';
}