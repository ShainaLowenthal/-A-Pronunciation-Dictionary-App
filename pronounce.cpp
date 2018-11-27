/*
Author: Shaina Lowenthal
Course: CSCI-135
Instructor: Maryash
Assignment: Project 2!

Discription:
Let the user input a word (W)
If the word is not found in the dictionary, print “Not found”. 
otherwise , report:
Pronunciation : the pronunciation of the word W (as given in the dictionary),
Identical : other words from the dictionary with the same pronunciation as W,
Add phoneme : words that can be obtained from W by adding one phoneme,
Remove phoneme : words that can be obtained from W by removing one phoneme,
Replace phoneme : words that can be obtained from W by replacing one phoneme.
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <cctype>


using namespace std;

//DECLARE functions prior to main
string fixWord(string word); //changes word to upper case so the user input word is not case sensitive
string findPhonemes(string fixedword); //reads the dictionary file and prints pronounciation 
void splitOnSpace(string s, string & before, string & after); //splits lines of dict. into the word and its pronounciation  
string findIdentical(string& currentpro, string word); //prints words that are made up of the same sequence of phonemes
int find_occurence(string afterSpace); //finds the size of the phoneme by checking for spaces
string replacePhoneme(string currentpro);//finds the words that has one phoneme difference
string addPhoneme(string currentpro);//finds the words with an addition phonemne
string removePhoneme(string currentpro); //finds the word with one less phoneme
	

int main()
	
{
	cout << "Enter word: " << endl;
	string word;
	cin >> word;
	int find = 0;
	//make sure it doesnt have numbers or letters therefore call the next function
	string fixedword = fixWord(word);
	//compare it to dictionary with boolean 
	string currentpro=findPhonemes(fixedword);
	string a = findIdentical(currentpro, fixedword);
	int y = find_occurence(currentpro);
	string x = replacePhoneme(currentpro);
	string z = addPhoneme(currentpro);
	string r = removePhoneme(currentpro);
	
		
}

string findPhonemes(string fixedWord)
{
	bool found = false; //use this to look for word in dict.  
	string word; //store current word in dict to this as we look through it
	string phonemes; //store it first before its afterSpace
	string beforeSpace; //variable for word
	string afterSpace; //variable for phoneme
	string line;
	ifstream fin;
	
	fin.open("cmudict.0.7a.txt"); //open dictionary file
	while (getline(fin, line)) //read while taking in words for dictionary
	{
		splitOnSpace(line, beforeSpace, afterSpace); // get rid of first space
		if(beforeSpace == fixedWord)
		{
			found = true;
			cout << "pronunciation: " << afterSpace << endl;
			fin.close(); //close file when done
			return afterSpace; //return the list of phonemes
			
		}
	}
	if(!found)
	{
		cout << "Not found." << endl;
		
		
	}
	
	fin.close();
	return "";

}
string fixWord(string word)
{
	char letter;
	string fixedWord;
	for(int i = 0; i < word.length(); i++)
	{
		
		letter = word[i];
		if(((int)letter < 65 && (int)letter > 0) || ((int)letter > 122 && (int)letter < 127)) //if its a symbol, we want to ignore it
		{
			fixedWord += letter;
		}
		//we want uppercase words
		else if (isupper(letter)){
			fixedWord += letter;
		}
		
    // If character is lowercase, subtracting 32 from the ASCII value of the letter will make it lowercase
    // then add it to fixedword
		
		else if (islower(letter))
		{
			letter = (char)(int)letter - 32;
			fixedWord += letter; 
		}
		
		
		else 
		{
			return "";
		}
	}
	return fixedWord;
}

	
//parse each line of dict. takes value of a string and split it into before and after
void splitOnSpace(string s, string & before, string & after) 
{
  // reset strings
  	before = ""; 
  	after = "";
  // accumulate before space
  	int i = 0;
  	while (i < s.size() && not isspace(s[i])) 
	  { 
		  before += s[i]; i++; 
	  }
  // skip the space
  	i++;
  // accumulate after space
  	while (i < s.size()) 
	  { 
		  after += s[i]; i++; 
	  }
}

//PHASE 2!!!

string findIdentical(string& currentpro, string fixedword) 
{
	string phonemes; //store it first before its afterSpace
	string beforeSpace; //variable for word
	string afterSpace; //variable for phoneme
	ifstream fin;
	string identical = "";
	//new string to store phoneme/after:
	string line;
	
	
	fin.open("cmudict.0.7a.txt"); 
	while (getline(fin, line)) 
	{
		
			
			splitOnSpace(line, beforeSpace, afterSpace); // get rid of first space
			
		
			if(currentpro == afterSpace && beforeSpace != fixedword)
			{
				identical = identical + beforeSpace + " ";		
				
			}	
			
	}
	cout << "Identical: " << identical << endl;
	return identical;
}


//PHASE 3!!!

int find_occurence(string currentpro)
{
	string line;
	string beforeSpace;
	
	int find = 0;

		for( int i = 0; i <= currentpro.length(); i++)
		{
			if(isspace(currentpro[i])) //counts spaces
			{
				find++;
			}
		}
	return find;
	
	
} 

string replacePhoneme(string currentpro)   
					
					
					//first, check if the amount of spaces are the same.
					//next, read through the line and count the amount of times it is not equal on the line
					//store it in variable
					//if error > 1, then move on and exit bc we dont want that
					//if error = 1, then store it in replace to print                                                               
{
   
		ifstream fin;
		string junk;
	
		fin.open("cmudict.0.7a.txt"); 
		
		for (int i = 0; i < 54; i++)
		{
			getline(fin, junk);
		}
		
	
	    string phonemes = "";     
		string beforeSpace = "";   
		string afterSpace = "";

		string replace = "";

		string line = "";          //new string to store phoneme/after
		string Newbefore = "";
		string Newbefore2 = "";
		string fixedWord = "";
		
		string a = "";
		int s; 
		int l;
		
	
		while (getline(fin, line)) //read while taking in words for dictionary
		{
		    splitOnSpace(line, beforeSpace, afterSpace); // get rid of first space
			
			
			
			a = currentpro; //we do this because the variable is changed each time.
				
			
			s = find_occurence(currentpro); //this was the issue!! (not a)
			l = find_occurence(afterSpace);
			
				 
				int count = 0;
				
				for(int i = 0; i <= find_occurence(currentpro); i++) 
				{
					
					splitOnSpace(a, Newbefore, a); //splitting the line again so the phoneme is split  
				
					splitOnSpace(afterSpace, Newbefore2, afterSpace);
				
					if(Newbefore != Newbefore2)
					{
						count++;		
					}	
					
			}
  		  if(beforeSpace[beforeSpace.length()-1] == ')')
  		  {
  			  count = 0;
  		  }
					
		if((count == 1) && (s == l))    //this was my major issue all along. store it in a variable bc it changes over time!!
		{
			replace = replace + beforeSpace + " ";
		}

	}
	cout << "Replace phoneme: "  << replace << endl;
	return replace;
	
}

//PHASE 4!!
//ADD PHONEME
///ONE MORE SPACE

string addPhoneme(string currentpro)
	
{
   
	string junk;
	ifstream fin;

	fin.open("cmudict.0.7a.txt"); 
	
    string phonemes = "";      
	string beforeSpace = ""; 
	string afterSpace = "";
	
	string replace = "";
	
	string line = "";         
	string Newbefore = "";
	string Newbefore2 = "";
	string fixedWord = "";
	int count = 0;
	string a = "";
	
	int s; 
	int l;
	string add = "";
	
	while (getline(fin, line)) //read while taking in words for dictionary
	{
	    splitOnSpace(line, beforeSpace, afterSpace); // get rid of first space
		
		a = currentpro; //we do this because the variable is changed each time.
		
		s = find_occurence(currentpro); //this was the issue!! (a)
		l = find_occurence(afterSpace);

		int count = 0;
		
			for(int i = 0; i <= (s+ 1); i++) //s
			{
				
				
				splitOnSpace(a, Newbefore, a); //splitting the line again so the phome is split 
				splitOnSpace(afterSpace, Newbefore2, afterSpace);
				
				
			
				if(Newbefore != Newbefore2) 
				{
					
					count++;
					splitOnSpace(afterSpace, Newbefore2, afterSpace);
					if(Newbefore != Newbefore2)
					{
						count++;
					}
						
				}
				
				
			}
		  if(beforeSpace[beforeSpace.length()-1] == ')')
		  {
			  count = 0;
		  }

			
			  if(count == 1 && (( s+ 1) == l))                              
			  {
				  
				  add = add + beforeSpace + " ";
			  }
				 
			  
			
	
			  count = 0;
		  }
	
cout << "Add phoneme: " << add << endl;
return add;
}

//PHASE 5!

string removePhoneme(string currentpro)
{
	string junk;
	ifstream fin;

	fin.open("cmudict.0.7a.txt"); 
	
	
    string phonemes = "";     
	string beforeSpace = "";   
	string afterSpace = "";
	
	
	
	string line = "";          //new string to store phoneme/after
	string Newbefore = "";
	string Newbefore2 = "";
	string fixedWord = "";
	int count = 0;
	string a = "";
	int s; 
	int l;
	string subtract = "";
	
	while (getline(fin, line)) //read while taking in words for dictionary
	{
	    splitOnSpace(line, beforeSpace, afterSpace); // get rid of first space
		
		a = currentpro; //we do this because the variable is changed each time.
		
		s = find_occurence(currentpro); 
		l = find_occurence(afterSpace);

		int count = 0;
		
			for(int i = 0; i <= (s+1); i++) //s
			{
				
				
				splitOnSpace(a, Newbefore, a); //splitting the line again so the phome is split into  
				splitOnSpace(afterSpace, Newbefore2, afterSpace);
				
			
				if(Newbefore != Newbefore2) 
				{
					
					count++;
					splitOnSpace(a, Newbefore, a); //splitting the line again so the phome is split
					
					if(Newbefore != Newbefore2)
					{
						count++;
					}
						
				}
				
				
				
			}
			
		  if(beforeSpace[beforeSpace.length()-1] == ')')
		  {
			  count = 0;
		  }

			
			  if(count == 1 && (( s - 1) == l))                              
			  {
				  subtract = subtract + beforeSpace + " ";
			  }
				 
	
			  count = 0;
		  }
	
cout << "Remove phoneme: " << subtract << endl;
return subtract;
}