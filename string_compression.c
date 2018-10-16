//String Compression : Implement a method to perform basic string compression using the counts of repeated characters.
//For example, the string "aabcccccaaa" would become "a2b1c5a3".
//If the "compressed" string would not become smaller than the original string,
//your method should return the original string.
//You can assume the string has only uppercase and lowercase letters(a - z, A - Z).

//The code includes a simole check ti ensure that the users entry are all alphabets

#include<iostream>
#include<string>
using namespace std;
//--------------------------------------------
string compress(string word);
bool check(string word);
//------------------------------------
int main()
{
	bool valid;
	string word;
	cin >> word;
	if ((valid = check(word))== true)
	{
		string answer = compress(word);
		if (word.size() > answer.size()) cout << answer;
		else
			cout << word << endl;
	}
	else
		cout << "error, only alphabets wanted" << endl;

}
// The check function ensures that there are no non-alphabets in the input
bool check(string word) {
	for (int i = 0; i < word.size(); i++)
	{
		if (!isalpha(word[i])) return false;
	}
	return true;
}
// This is the compression function
string compress(string word) {
	string answer;
	int i = 0;
	while (i < word.size()) {
		int j = i, count = 0;
		do {
			count++;
		} while (word[++j] == word[i]);
		answer += word[i];
		answer += (to_string(count));
		i = j;
	}
	
	return answer;
}
