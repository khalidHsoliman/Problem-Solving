#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

// in this dictionary we assume that word is stored in line and the meaning of that word is stored in the following line
class Dictionary
{
    public:
        Dictionary(string const &path);
        virtual ~Dictionary();

        void addWord(); // Add new word
        void updateWord();   // update existing word
        void deleteWord();   // delete given word
        void searchWord();   // search for a word .. return index if founde, return -1 if not
        void saveToFile();   // save array of word to the file
        void displayAll();              // display all dictionary words sorted
        void undoLastOp();              // undo last operation
        void displayMostPopular();      // display most popluar - the words that appear most in a search -
        void quit();                    // quit the application

    private:
        void addWord(string const &newWord,string const &newMean);
        void updateWord(string const &newWord,string const &newMean, int index);
        void deleteWord(int index);
        int  searchWord(string const &searchedWord);
        void redoLastOp();


        // helper functions
        bool hasEnding(string const &fullString,string const &ending);
        int  seqSearch(string a[],int start, int bounds, string const &key);
        void sortAscend();


        string word[1000];              // array to store dictionary words
        string mean[1000];              // array to store the associated meaning
        string filePath = " ";

        int loop = 0;
        int wordSize = 0;
        bool isWord = true;
};

#endif // DICTIONARY_H
