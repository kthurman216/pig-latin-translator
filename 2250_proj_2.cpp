/*
 * 2250_proj_2.cpp
 *
 *  Created on: Feb 23, 2021
 *      Author: Kayla
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Word {
	string english;
	string piglatin;
};

Word * splitSentence(const string, int &);
void convertToPigLatin(Word [], int);
void displayPigLatin(Word[], int);

int main()
{
	string sentence;		//stores user's input sentence
	int size = 0;			//stores number of words in sentence
	Word * wptr = nullptr; 	//stores pointer to word array

	cout << "Please enter a sentence to convert to Pig Latin:\n";
	getline(cin, sentence);	//gets user input

	wptr = splitSentence(sentence, size);

	convertToPigLatin(wptr, size);

	displayPigLatin(wptr, size);

	//deletes word pointer
	delete [] wptr;

	//resets pointer to null
	wptr = nullptr;


	return 0;
}

/*takes a string and counts the number of words in the string object; this is returned to
 * main through the parameter. dynamically allocates an array of Word structures. Each word
 * is then added to the 'english' member of its corresponding Word structure. This function
 * also changes all uppercase letters to lowercase and eliminates non-alpha characters*/
Word * splitSentence(const string words, int &size)
{
	int wordNum = 0,
		strSize = words.length();

	/*counts the number of words in the string and returns the number to main via the size
	 * variable*/
	for (int i = 0; i < strSize; i++)
	{
		if (isalpha(words[i]) && !isalpha(words[i + 1]))
		{
			size++;
		}

	}

	//dynamically allocate array of word structure
	Word * wordArr = new Word[size];


	/*loops through full string. Checks if the current character in the string and the next
	 * character are both alpha; if they are, letter is added to the current Word structure. if
	 * current character is alpha and the next letter is not (either whitespace or punctuation),
	 * the current character is added to the Word structure and the wordNum variable is
	 * incremented as long as it is not the final Word structure in the array. else statement
	 * is included to make loop continue in case current character in the string is punctuation
	 * or other non-alpha character. also changes any uppercase letters to lowercase as they
	 * are added to the Word structure.
	 * */
	for (int i = 0; i < strSize; i++)
	{
		if (isalpha(words[i]) && isalpha(words[i + 1]))
		{
			wordArr[wordNum].english += tolower(words[i]);
		}
		else if (isalpha(words[i]) && !isalpha(words[i + 1]))
		{
			wordArr[wordNum].english += tolower(words[i]);

			if (wordNum < size)
				wordNum++;
		}
		else
			continue;
	}


	return wordArr;
}

/*This function loops through each word in an array of Word structures and checks if the first
 * character in the word is a vowel; if true, "way" is added to the end of the word. If the
 * word starts with a consonant, the first letter of the word is stored in a temp character
 * and the word, from the second character to the end is copied into the piglatin member of the
 * Word structure. Afterward, the temp character and "ay" are appended to the piglatin member*/
void convertToPigLatin (Word wordArr[], int size)
{
	char temp = ' ';
	string end = "ay";
	for (int i = 0; i < size; i++)
	{
		if (wordArr[i].english[0] == 'a' || wordArr[i].english[0] == 'e'
		|| wordArr[i].english[0] == 'i' || wordArr[i].english[0] == 'o'
		|| wordArr[i].english[0] == 'u')
		{
			wordArr[i].piglatin = wordArr[i].english + "way";
		}
		else
		{
			temp = wordArr[i].english[0];
			wordArr[i].piglatin = wordArr[i].english.substr(1, wordArr[i].english.length());
			wordArr[i].piglatin.append(1, temp);
			wordArr[i].piglatin.append(end);
		}
	}

}

/*function to display piglatin member of each element in word array separated by a space*/
void displayPigLatin(Word wordArr[], int size)
{

	for (int i = 0; i < size; i++)
		cout << wordArr[i].piglatin << " ";

}
