#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>

using namespace std;

//Functions
int getNumberOfLine();
string getMisteryWord(int randomWordLine);
string shuffleWord(string word);


int main(){

    //initialize srand to be able to generate random number
    srand(time(0));
    int randomLine;
    string mysteryWord;
    string wordShuffled;
    string userGuess;
    char userContinue = 'y';
    int userChoice;

    while (userContinue == 'y' || userContinue == 'Y')
    {

        do
        {
            randomLine = rand() % getNumberOfLine();
            mysteryWord = getMisteryWord(randomLine);
            wordShuffled = shuffleWord(mysteryWord);
        } while (mysteryWord == wordShuffled);
        


        cout<<endl<<"\t\tWELCOME IN THE GUESS WORD GAME"<<endl<<endl<<"\t\t\t\tMENU"<<endl<<"--------------------------------------------------------------------"<<endl<<"\t\t\t\t1 - Play"<<endl<<"\t\t\t\t2 - Help"<<endl<<"\t\t\t\t3 - Quit"<<endl<<"--------------------------------------------------------------------"<<endl<<endl<<"\t\t\tYour choice : ";

        cin>>userChoice;

        if (userChoice == 1)
        {
            cout<<endl<<"You have to the word which is shuffled as : "<<wordShuffled<<endl<<endl<<"You have to try "<<wordShuffled.size()<<" times"<<endl<<endl<<"Let's gooooo"<<endl<<endl;

            int i = 0;
            while (i < wordShuffled.size())
            {
                cout<<endl<<"Try "<<(i+1)<<endl<<endl<<"What is the word : ";
                cin>>userGuess;

                if (userGuess == mysteryWord)
                {
                    cout<<endl<<endl<<"Congratulations, you made it in "<<(i+1)<<" try"<<endl<<"The word was effectively "<< mysteryWord<<endl<<endl;
                    i = wordShuffled.size();
                }
                else
                {
                    if (i == wordShuffled.size())
                        cout<<endl<<"Sorry, you didn't find it"<<endl<<"The word was : "<<mysteryWord<<endl<<endl;
                    else
                        cout<<endl<<"No match, try again"<<endl;
                }
                i+=1;
            }

            
        }
        else if (userChoice == 2)
        {
            cout<<endl<<"HELP"<<endl<<"--------"<<endl<<"In this game you are given a word which is shuffled and you have to guess the original one, hope you will enjoy the game"<<endl<<endl;
        }
        else if (userChoice == 3)
            break;

        cout<<endl<<"Do you want to play again (y/n) : ";
        cin>>userContinue;
    }

    cout<<endl<<endl<<"End of game, hope you enjoy!!!"<<endl;
    
    
    return 0;
}

int getNumberOfLine(){

    ifstream fileReader("mystery_words.txt");
    int numberOfLine = 0;
    string line;

    if (fileReader)
        while (getline(fileReader, line))
            numberOfLine += 1;
    else
        cout<<endl<<"Impossible to open the file to read the number of line"<<endl;

    return numberOfLine;
}

string getMisteryWord(int randomWordLine){

    string randomWord;
    int i= 0;

    ifstream fileReader("mystery_words.txt");

    while (getline(fileReader, randomWord))
    {
        if (i==randomWordLine)
            return randomWord;
        i++;
    } 
    return randomWord;
}

string shuffleWord(string word){

    string shuffleWord;
    int tpm_position;

    while (word.size()!=0)
    {
        tpm_position = rand() % word.size();
        shuffleWord += word[tpm_position];
        word.erase(tpm_position, 1);
    }
   return shuffleWord;
}