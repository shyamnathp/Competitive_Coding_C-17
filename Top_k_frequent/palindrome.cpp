#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string text = "malayalam";
	string reverseText = text;
	reverse(text.begin(), text.end());

	if (reverseText == text)
		cout << "palindrome";
}