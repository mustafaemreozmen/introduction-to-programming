#include <iostream>
#include <string>

using namespace std;

struct WordProps
{
	string letter;
	int letterCount;
	string vowel;
	bool isItAPalindrome;
};

struct LineProps
{
	string punctuation;
	string enteredLine;
	int wordCount;
	WordProps words[255];
	int letterCount;
	int wordsVowelCount;
	int palindromeWordCount;
	bool isItAPalindrome;
};

LineProps line;

bool isPunctuationMark(char character);
bool isItVowel(char character);
bool lineIsItAPalindrome(string line);
WordProps wordPropsControl(WordProps word);
void structControl();

int main()
{
	cout << "enter a sentence:" << endl;
	getline(cin, line.enteredLine);

	for (int i = 0; i < line.enteredLine[i]; i++)
		line.enteredLine[i] = tolower(line.enteredLine[i]);
	structControl();

	system("@cls ||clear");

	cout << "Sentence Entered:.........................................: " << line.enteredLine << endl;
	cout << "Word Count?...............................................: " << line.wordCount << endl;
	cout << "Number of Letters.........................................: " << line.letterCount << endl;
	cout << "Punctuation...............................................: " << line.punctuation << endl;
	cout << "Is It a Palindrome?.......................................: ";

	if (line.isItAPalindrome == 1)
		cout << "Palindrome!" << endl; //Ekrana bool'un durumuna göre çıktı veriyor.
	else if (line.isItAPalindrome == 0)
		cout << "No, it is not a palindrome." << endl;

	cout << "Are there any palindrome words in the sentence?...........: " << line.palindromeWordCount << "\n";

	for (int i = 0; i < line.wordCount; i++)
	{
		if (line.words[i].isItAPalindrome)
			cout << line.words[i].letter << "\n";
	}
	cout << "\nLetter numbers of words in a sentence..................:\n\n";

	for (int i = 0; i < line.wordCount; i++)
	{
		cout << line.words[i].letter << " word letter count...........:";
		cout << line.words[i].letterCount;
		cout << endl;
	}

	cout << "\n\nTotal Vowel counts.................................: \n\n";

	for (int i = 0; i < line.wordCount; i++)
	{
		cout << line.words[i].letter << " word vowel count..........:" << line.words[i].vowel.length() << "\n";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}

bool isPunctuationMark(char character)
{
	switch (character)
	{
	case '.':
	case ':':
	case ',':
	case ';':
	case '-':
	case '\'':
	case '\"':
	case '_':
	case '?':
	case '^':
	case '!':
		return true;
		break;
	default:
		break;
	}

	return false;
}

bool isItVowel(char character)
{
	switch (character)
	{
	case 'a':
	case 'A':
	case 'e':
	case 'E':
	case 'i':
	case 'İ':
	case 'ı':
	case 'I':
	case 'o':
	case 'O':
	case 'ö':
	case 'Ö':
	case 'u':
	case 'U':
	case 'ü':
	case 'Ü':
		return true;
		break;
	default:
		break;
	}

	return false;
}

bool lineIsItAPalindrome(string line)
{
	bool donus = true;

	string temp = "";
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] != ' ' && line[i] != '.' && line[i] != ',' && line[i] != ';' && line[i] != ':' && line[i] != '?' && line[i] != '!' && line[i] != '\'' && line[i] != '-' && line[i] != '_')
			temp.append(1, line[i]);
	}

	int length = temp.length();
	for (int i = 0; i < length; i++)
	{
		if (temp[i] != temp[length - i - 1])
		{
			donus = false;
			break;
		}
	}
	return donus;
}

WordProps wordPropsControl(WordProps word)
{
	bool palindrom = true;
	word.letterCount = word.letter.length();
	for (int i = 0; i < word.letterCount; i++)
	{
		char ch = word.letter[i];
		if (ch != word.letter[word.letterCount - i - 1])
		{
			palindrom = false;
		}
		palindrom = palindrom & true;

		if (isItVowel(ch))
			word.vowel.append(1, ch);
	}
	word.isItAPalindrome = palindrom;
	return word;
}

void structControl()
{
	int wordCount = 0;
	int lastIndex = -1;
	for (int i = 0; i < line.enteredLine.length(); i++)
	{
		if (line.enteredLine[i] == ' ' || line.enteredLine[i] == '.' || line.enteredLine[i] == ',' || line.enteredLine[i] == ';' || line.enteredLine[i] == ':' || line.enteredLine[i] == '?' || line.enteredLine[i] == '!' || line.enteredLine[i] == '\'' || line.enteredLine[i] == '-' || line.enteredLine[i] == '_')
		{
			WordProps word;
			word.letter = line.enteredLine.substr(lastIndex + 1, i - lastIndex - 1);
			word = wordPropsControl(word);
			line.words[wordCount] = word;
			lastIndex = i;
			wordCount++;
		}
	}
	if (line.enteredLine.substr(lastIndex + 1).length() > 1)
	{
		WordProps word;
		word.letter = line.enteredLine.substr(lastIndex + 1);
		word = wordPropsControl(word);
		line.words[wordCount] = word;
		wordCount++;
	}

	line.wordCount = wordCount;
	line.isItAPalindrome = lineIsItAPalindrome(line.enteredLine);

	line.wordsVowelCount = 0;
	line.letterCount = 0;
	line.palindromeWordCount = 0;
	line.punctuation = "";
	for (int i = 0; i < line.wordCount; i++)
	{
		line.wordsVowelCount += line.words[i].vowel.length();
		line.letterCount += line.words[i].letterCount;
		if (line.words[i].isItAPalindrome)
			line.palindromeWordCount++;
	}
	for (int i = 0; i < line.enteredLine.length(); i++)
	{
		char ch = line.enteredLine[i];
		if (isPunctuationMark(ch))
			line.punctuation.append(1, ch);
	}
}
