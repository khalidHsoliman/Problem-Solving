#include "dictionary.h"

int main()
{
    Dictionary myDictionary("data.txt");

    while(1)
    {
        char answer;
        cout << endl;
        cout << "***Dictionary Operations***" << endl
             << "1.Add word." << endl
             << "2.Update word." << endl
             << "3.Delete word." << endl
             << "4.Search for word." << endl
             << "5.Save to file." << endl
             << "6.Display all words." << endl
             << "7.Undo last operation." << endl
             << "8.Display the most popular words." << endl
             << "9.Quit." << endl << endl
             << "Please choose an operation by writing its number..." << endl;

        cin >> answer;

        switch(answer)
        {
        case '1':
            myDictionary.addWord();
            break;
        case '2':
            myDictionary.updateWord();
            break;
        case '3':
            myDictionary.deleteWord();
            break;
        case '4':
            myDictionary.searchWord();
            break;
        case '5':
            myDictionary.saveToFile();
            break;
        case '6':
            myDictionary.displayAll();
            break;
        case '7':
            myDictionary.undoLastOp();
            break;
        case '8':
            myDictionary.displayMostPopular();
            break;
        case '9':
            myDictionary.quit();
            break;
        default:
            cout << "Wrong number .. try a number from 1-9" << endl;
        }
    }
    return 0;
}
