#include <iostream>
#include <vector>

using namespace std;


float sum(vector<float> v); // return the summation of the vector
vector<float> power(vector<float> v, int p); // multiply each element p times
vector<float> multiply(vector<float> v1, vector<float> v2); // multiply two vectors

void main()
{
	
	int m; // degree

	int n; // number of data
	cout << "Number of Data: "; cin >> n;

	// Data
	vector<float> x(n);
	vector<float> y(n);
	vector<float> w(n);

	// taking data
	cout << "x[i]: ";
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	cout << "y[i]: ";
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}

	cout << "w[i]: ";
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}

	// print points
	for (int i = 0; i < x.size(); i++) {
		cout << "(" << x[i] << ", " << y[i] << ")\n";
	}

	// calculating
	cout << "Degree: ";
	while (cin >> m) // to allow user to change the degree for the same data
	{
		for (int k = 0; k <= m; k++) 
		{
			for (int j = 0; j <= m; j++)
			{
				cout << sum(multiply(w, power(x, j + k)));
				if (j != m)
					cout << "  ";
			}
			cout << "  " << sum(multiply(multiply(w, power(x, k)), y));
			cout << endl;
		}
		cout << "Degree: ";
	}
}

vector<float> multiply(vector<float> v1, vector<float> v2)
{
	vector<float> result(v1.size(), 0);

	for (int i = 0; i < v1.size(); i++) {
		result[i] = v1[i] * v2[i];
	}

	return result;
}

vector<float> power(vector<float> v, int p)
{
	vector<float> result(v.size(), 0);
	for (int i = 0; i < v.size(); i++) {
		result[i] = pow(v[i], p);
	}
	return result;
}


float sum(vector<float> v)
{
	float result = 0;
	for (int i = 0; i < v.size(); i++)
		result += v[i];
	return result;
}