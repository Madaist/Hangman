#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED

#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>

void print_title(std::string text)
{
    std::cout << "*^^^^^^^^^^^^^^^^^^^^^^^^^^^^*" << std::endl;
    std::cout << "|";
    bool front = true;
    for(int i = text.size(); i < 28; i++)
    {
        if(front)
            text = " " + text;
        else text = text + " ";
        front = !front;
    }

    std::cout << text;
    std::cout << "|" << std::endl;
    std::cout << "*^^^^^^^^^^^^^^^^^^^^^^^^^^^^*" << std::endl;
}

void print_hangman(std::string text)
{
    std::cout << "|";
    bool front = true;
    for(int i = text.size(); i < 28; i++)
    {
        if(front)
            text = " " + text;
        else text = text + " ";
        front = !front;
    }
    std::cout << text;
    std::cout << "|" << std::endl;

}

void draw_hangman(int wrong_guesses = 0)
{
    if(wrong_guesses >= 1)
        print_hangman("|");
    else print_hangman("");

    if (wrong_guesses >= 2)
        print_hangman("|");
    else
        print_hangman("");

    if (wrong_guesses >= 3)
        print_hangman("O");
    else
        print_hangman("");

    if (wrong_guesses == 4)
        print_hangman("/  ");

    if (wrong_guesses == 5)
        print_hangman("/| ");

    if (wrong_guesses >= 6)
        print_hangman("/|\\");
    else
        print_hangman("");

    if (wrong_guesses >= 7)
        print_hangman("|");
    else
        print_hangman("");

    if (wrong_guesses == 8)
        print_hangman("/");

    if (wrong_guesses >= 9)
        print_hangman("/ \\");
    else
        print_hangman("");
}

void print_letters(std::string word, char first, char last)
{
    std::string s;
    for(char i = first; i <= last; i++)
    {
        if(word.find(i) == std::string::npos)
        {
            s += i;
            s += " ";
        }
        else
            s += " ";
    }
    print_hangman(s);
}

void available_letters(std::string chosen_letters)
{
    print_title("Available letters");
    print_letters(chosen_letters, 'A', 'M');
    print_letters(chosen_letters, 'N', 'Z');

}

bool game(std::string word, std::string guessed)
{
    bool won = true;
    std::string s;
    for(unsigned int i = 0; i < word.length(); i++)
    {
        if(guessed.find(word[i]) == std::string::npos)
        {
            won = false;
            s = s + "_";
        }
        else
        {
            s = s + word[i];
            s = s + " ";
        }
    }
    print_hangman(s);
    return won;
}

std::string random_word(std::string file)
{
    std::string word;
    std::vector<std::string> words;
    std::ifstream f(file);
    if(f != NULL)
    {
        while(std::getline(f, word))
            words.push_back(word);

        int random_line = rand() % words.size();
        word = words.at(random_line);
        std::cout << word << std::endl;
        f.close();
    }
    return word;
}

int tries_left(std::string word, std::string guessed)
{
    int wrong_guesses = 0;
    for(unsigned int i = 0; i < guessed.length(); i++)
    {
        if(word.find(guessed[i]) == std::string::npos)
            wrong_guesses++;
    }
    return wrong_guesses;
}

#endif // FUNCTIONS_HPP_INCLUDED
