#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void L(const char* Y, int n, int *l)
{
	int i = 1,j; 
	l[0] = 0;
	while (i < n)
	{
		j = l[i-1];
		while ((Y[i] != Y[j]) && (j > 0)) j = l[j];
		if (Y[i] == Y[j]) l[i] = j + 1;
		else l[i] = 0;
		i += 1;
	}
}


void searchTheWord(const char* X, const char* Y, int mm, int nn, int *f) // можно передавать размер строк?
{
	int s;
	int m = mm - 1;
	int n = nn - 1;
	for (int i = 0; i < n ; i++)
	{
		f[i] = 0;
		cout << "f[" << i << "] = 0" << endl;
	}
	for (int i = n ; i <= m ; i++)
	{
		s = 0;
		while (( Y[s] == X[i - (n - s)]) && ( s < n )) s += 1;
		if (( Y[s] == X[i] ) && ( s == n )) f[i] = nn;
		else f[i] = 0;
		cout << "f[" << i << "] = " << f[i] << endl;
	}
	//cout << "LOOK!: it's result : " << endl;	
}


void main()
{
	//setlocale(LC_ALL, "rus");

	string s1, s2;
	
	//
	cout << "enter the world in which we are looking for first world" << endl;
	cin >> s1;
	const char *X = s1.c_str();
	//
	cout << "enter the world which we are looking for:" << endl;
	cin >> s2;
	const char *Y = s2.c_str();

	int n = s2.length();
	int m = s1.length();
	int *f = new int[m];

	cout << X << " size = " << m << endl << Y << " size = " << n << endl;

	//searchTheWord(X, Y, m, n, f);

	int *l = new int[n];
	L(Y, n, l);
	for (int i = 0; i < n; i++)
		cout << l[i] << " ";


}