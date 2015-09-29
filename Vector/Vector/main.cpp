/*#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7 };

	for( int n : numbers )
	{
		std::cout << n << ' ';
	}
}*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void outputVector (const vector<int> a);

int main(void)
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(9);
	v1.push_back(1);
	v1.push_back(2);
	for(int n : v1)
	{
		try
		{

			std::cout << n << std::endl;
		} catch (out_of_range ex)
		{
			std::cerr << "An exception occurred";
		}
	}
	getchar();
}