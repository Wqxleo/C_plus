#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class MaxValue
{
public:
	void append(int a)
	{
		elements.push_back(a);
	}
	int getMax()
	{

		int max = 0;
		for (itr = elements.begin(); itr != elements.end(); itr++)
		{
			if (*itr > max)
				max = *itr;
		}
		return max;
	}
private:
	vector<int> elements;
    vector<int>::iterator itr;
};
int main()
{
	int a;
	MaxValue test;
	cin >> a;
	while (a != 0)
	{
		test.append(a);
		cin >> a;
	}
	cout << test.getMax() << endl;
	return 0;
}
