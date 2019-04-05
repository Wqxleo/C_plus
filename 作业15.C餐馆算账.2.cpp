#include <iostream>
#include <map>
#include <iterator>
#include <iomanip>
using namespace std;
int main()
{
	int N, i, M, K, j, num;
	map<string, double> Menu;
	map<string, double> ::iterator itr;
	string name;
	double price;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> name >> price;
		Menu.insert(make_pair(name, price));
	}
	cin >> M;
	map<string, double> Spence;
	string gname;
	double tmp;
	int len = 0;
	for (i = 0; i < M; i++)
	{
		cin >> gname;
		if(len < gname.size())
        {
            len = gname.size();
        }
		cin >> K;
		tmp = 0;
		for (j = 0; j < K; j++)
		{
			cin >> name >> num;
			for (itr = Menu.begin(); itr != Menu.end(); itr++)
			{
				if (name == itr->first)
				{
//				    cout<<num<<" "<<itr->second<<endl;
					tmp += num*(itr->second);
				}
			}
		}
		Spence.insert(make_pair(gname, tmp));
	}
	cout << left<<setw(len+1)<<"Guest"<<"Price"<<endl;
	for (itr = Spence.begin(); itr != Spence.end(); itr++)
	{
		cout << left<<setw(len+1)<<itr->first<< setprecision(2) << fixed << itr->second << endl;
	}
	return 0;


}
