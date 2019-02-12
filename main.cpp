#include <iostream>
#include "Functions.hpp"
using namespace std;


int main()
{
    srand(time(0));
    std::string guesses;
    std::string word = random_word("hangman.txt.txt");
    int tries = 0;
    bool win = false;
    do
    {
        system("cls");
        print_title("HANGMAN");
        draw_hangman(tries);
        available_letters(guesses);
        print_title("Guess the word");
        win = game(word, guesses);

        if(win)
            break;

        char x;
        cout << ">>";
        cin >> x;
        if(guesses.find(x) == std::string::npos)
            guesses += x;

        tries = tries_left(word, guesses);

    } while(tries < 10);

    if(win)
        print_hangman("YOU WON!");
    else print_hangman("YOU LOSE");

    system("pause");
    return 0;
}
