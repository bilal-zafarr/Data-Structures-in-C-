#include<iostream>
#include<string>
using namespace std;

double power(double base, double exponent) {
	bool isNegative = false;

	if (exponent < 0) {
		isNegative = true;
		exponent *= -1;
	}

	if (exponent == 0)
		return 1;
	else {
		if (isNegative)
			return 1 / (base * power(base, exponent - 1));
		else
			return base * power(base, exponent - 1);
	}
}


int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}


string* GeneratePerm(string s) {

    if (s.length() == 1)
        return new string(s);

    else if (s == "")
        return nullptr;

    string* prev = GeneratePerm(s.substr(1, s.length() - 1));
    int prevSize = factorial(prev[0].length());

    string* curr = new string[prevSize * s.length()];

    int j = 0;
    int k = s.length() - 1;
    int l = 0;
    for (int i = 0; i < prevSize * s.length(); i++)
    {
        curr[i] = prev[l].substr(0, j) + s[0] + prev[l].substr(j, k);
        j++;
        k--;

        if (j > s.length()-1)
            j = 0;
        if (k < 0)
            k = s.length()-1;

        if ((i + 1) % s.length() == 0)
            l++;
    }
    return curr;
}


int main() {	


    cout << "5^3  = " << power(5, 3) << '\n';
    cout << "5^-3 = " << power(5,-3) << "\n\n";

    cout << "--------------------------------\n";
	
    string s = "ABCD";

    string* p = GeneratePerm(s);

    int totalPermutations = factorial(s.length());

    for (int i = 0; i < totalPermutations; i++)
        cout << i+1 << '\t' << p[i] << '\n';


	return 0;
}