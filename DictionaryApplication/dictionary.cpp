#include "dictionary.h"

using namespace std;

Dictionary::Dictionary(string const &path)
{
    filePath = path;
    ifstream inFile(filePath.c_str());
	if(!inFile)
	{
		cout << "Couldn't open the file" << endl;
		quit();
	}

	for(int i = 0; i < 1000; i++)
    {
        word[i] = " ";
        mean[i] = " ";
    }

	string line;
	while( getline(inFile, line)  )
        {
            if(line != " ")
            {
                if(isWord)
                    word[loop] = line;
                else
                {
                    mean[loop] = line;
                    loop++;
                }

                isWord = !isWord;

            }
        }

        wordSize = loop;
}

void Dictionary::addWord()
{
    string newWord = " ";
    string newMean = " ";

    while(1)
    {
        cout << "What word do you want to add : " ;
        cin >> newWord;

        cout << "What is the meaning of " << newWord << " ? " << endl;
        getline(cin, newMean);
        while (newMean.length() == 0 )
            getline(cin, newMean);

        addWord(newWord, newMean);

        cout << "Do you want to add another word ? if not type q" << endl;
        cin >> newWord;
        if(newWord == "q")
            break;
    }
}

void Dictionary::addWord(string const &newWord,string const &newMean)
{
    word[loop] = newWord;
    mean[loop] = newMean;
    loop++;
    wordSize++;
    if(wordSize > 1000)
        wordSize = 1000;
    if(loop == 1000)
    {
        cout << "Dictionary size exceeded .. overwriting the dictionary" << endl;
        loop = 0;
    }
}

void Dictionary::updateWord()
{
    string updatedWord = " ";
    string updatedMean = " ";
    string answer = " ";

    while(1)
    {
        cout << "What word do you want to update : " ;
        cin >> updatedWord;

        int found = searchWord(updatedWord);

        if(found > 0)
        {
            updatedWord = word[found];
            updatedMean = mean[found];

            cout << "The word is found!" << endl;
            cout << "Do you want to update the word ? (YES or NO) " << endl;
            cin >> answer;
            for_each(answer.begin(), answer.end(), [](char & c) {c = ::tolower(c);});

            if(answer == "yes")
            {
                cout << "Enter the update for the word : " << endl;
                cin >> updatedWord;
            }
            else if(answer != "no")
                cout << "undefined answer" << endl;

            cout << "Do you want to update the mean ? (YES or NO) " << endl;
            cin >> answer;
            for_each(answer.begin(), answer.end(), [](char & c) {c = ::tolower(c);});

            if(answer == "yes")
            {
                cout << "Enter the update for the mean : " << endl;
                getline(cin, updatedMean);
                while (updatedMean.length() == 0 )
                    getline(cin, updatedMean);
            }

            else if(answer != "no")
                cout << "undefined answer" << endl;

            updateWord(updatedWord, updatedMean, found);
        }

        else
        {
            cout << "The word is not found" << endl;
            cout << "Do you want to add it ? (YES or NO) " << endl;

            cin >> answer;

            for_each(answer.begin(), answer.end(), [](char & c) {c = ::tolower(c);});

            if(answer == "yes")
            {
                cout << "What is the meaning of " << updatedWord << " ? ";
                getline(cin, updatedMean);
                while (updatedMean.length() == 0 )
                    getline(cin, updatedMean);

                addWord(updatedWord, updatedMean);
                cout << "Added!!" << endl;
            }
            else if(answer != "no")
                cout << "undefined answer" << endl;
        }

        cout << "Do you want to update another word ? if not type q" << endl;
        cin >> updatedWord;
        if(updatedWord == "q")
            break;
    }
}

void Dictionary::updateWord(string const &newWord,string const &newMean, int index)
{
    word[index] = newWord;
    mean[index] = newMean;
}

void Dictionary::deleteWord()
{
    string deletedWord = " ";

    while(1)
    {
        cout << "What word do you want to delete : " ;
        cin >> deletedWord;

        int found = searchWord(deletedWord);
        if(found > 0)
        {
            deleteWord(found);
            cout << deletedWord << " is deleted for the dictionary" << endl;
        }
        else
            cout << "the word " << deletedWord << " does not exist" << endl;

        cout << "Do you want to delete another word ? if not type q" << endl;
        cin >> deletedWord;
        if(deletedWord == "q")
            break;
    }

}

void Dictionary::deleteWord(int index)
{
    word[index] = " ";
    mean[index] = " ";
}

void  Dictionary::searchWord()
{
    char answer;
    string searchedWord = " ";
    string matchedWords[1000];
    string matchedmeans[1000];

    int matchLoop = 0;

    for(int i = 0; i < 1000; i++)
        matchedWords[i] = " ";

    cout << "How do you want to search ? " << endl
         << "1. Equals." << endl
         << "2. Start with." << endl
         << "3. End With." << endl
         << "4. Conatains." << endl;

    cin >> answer;

    cout << "Enter what you want to search for : ";
    cin >> searchedWord;

    switch(answer)
    {
    case '1':
        {
            int index = searchWord(searchedWord);
            matchedWords[matchLoop] = word[index];
            matchedmeans[matchLoop] = mean[index];
            matchLoop++;
            break;
        }

    case '2':
        for(int i = 0; i < loop; i++)
            if(word[i].rfind(searchedWord, 0) == 0)
            {
                matchedWords[matchLoop] = word[i];
                matchedmeans[matchLoop] = mean[i];
                matchLoop++;
            }
        break;

    case '3':
        for(int i = 0; i < 1000; i++)
            if(hasEnding(word[i], searchedWord))
            {
                matchedWords[matchLoop] = word[i];
                matchedmeans[matchLoop] = mean[i];
                matchLoop++;
            }
        break;

    case '4':
        for(int i = 0; i < 1000; i++)
            if (word[i].find(searchedWord) != string::npos)
                {
                    matchedWords[matchLoop] = word[i];
                    matchedmeans[matchLoop] = mean[i];
                    matchLoop++;
                }
        break;

    default:
        cout << "Wrong number.." << endl;
    }

    if(matchLoop > 0)
    {
        cout << "Found !" << endl;
        for(int i = 0; i < matchLoop; i++)
        {
            cout << "Word : " << matchedWords[i] << endl
                 << "Meaning : " << matchedmeans[i] << endl;
        }
    }

}

int  Dictionary::searchWord(string const &searchedWord)
{
    // sequential search
    return seqSearch(word, 0, wordSize, searchedWord);

    //Binary search
    /* Not implemented */
}

void Dictionary::saveToFile()
{
    ofstream ofs(filePath, std::ofstream::trunc);
    for(int i = 0; i < 1000; i++)
    {
        if(word[i] != " ")
            ofs << word[i] << endl << mean[i] << endl;
    }

    ofs.close();
}

void Dictionary::displayAll()
{
    sortAscend();

    for(int i = 0; i < wordSize; i++)
    {
        if(word[i] == " ")
            continue;
        cout << word[i] << " : " << mean[i] << endl;
    }
}

void Dictionary::undoLastOp()
{
    // Not implemented
}

void Dictionary::redoLastOp()
{
    // Not implemented
}
void Dictionary::displayMostPopular()
{
    // Not implemented
}

void Dictionary::quit()
{
    exit(0);
}

bool Dictionary::hasEnding (std::string const &fullString, std::string const &ending)
{
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

int Dictionary::seqSearch(string a[], int start, int bounds, string const &key)
{
    while(start < bounds){
        if(a[start]==key)
            return start;
        else
            start++;
    }
    //no match found
    return -1;
}

void Dictionary::sortAscend()
{
    map <string, string> wordMean;
    int ii = 0;

    for(int i = 0; i < wordSize; i++)
    {
        wordMean[word[i]] = mean[i];
    }

    for(map<string,string>::iterator it = wordMean.begin(); it != wordMean.end(); it++)
    {
        word[ii] = it->first;
        mean[ii] = it->second;
        ii++;
    }
}

Dictionary::~Dictionary()
{
    quit();
}


