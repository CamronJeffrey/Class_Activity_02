// Class_Activity_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <ctime>
#include <string>
using namespace std;

    class BlackJack
    {
    public:
        void playGame()
        {
            srand((int)time(0));
            int person = dealCards(2, "Your Cards:");
            cout << "=" << person << endl;
            int dealer = dealCards(2, "Dealer Cards:");
            cout << " = " << dealer << endl;
            hit(person);
            cout << endl;
            while ((dealer < person) && (dealer <= 21) && (person <= 21))
            {
                dealer = dealer + dealCards(1, "The Dealer takes a card ");
                cout << endl;
            }
            determineWinner(person, dealer);
        }
    public:
        void hit(int& playerScore)
        {
            int cardCount = 0;
            char wantCard = "y" || "n";
            int cardTotal = 0;
            cardTotal = playerScore;
            cout << "Would you like another card?";
            cin >> wantCard;
            while (wantCard == 'Y' || wantCard == 'y')
            {
                if ((cardTotal > 0) && (cardTotal < 21))
                {
                    cardCount = cardCount + 1;
                }
                cardTotal = cardTotal + Random(0, 10);
                cout << "\nYour total is: " << cardTotal;
                cout << "\nDo you want another card?";
                cin >> wantCard;
                if (wantCard == 'Y' || wantCard == 'y')
                    cout << cardTotal + dealCards(1, "\nYou take a card.");
                else
                    cout << "\nYou decide to stand";
                if (cardTotal > 21)
                    cout << "\nYou have gone over 21, You Lose" << endl;
            }
        }
    public:
        int dealCards(int numberOfCards, string message)
        {
            int return_value = 0;
            int value = 0;
            cout << " " << message << endl;
            for (int a = 0; a <= numberOfCards; a++)
            {
                int cards = a;
                while (cards--)
                {
                    value = Random(0, 10);
                    cout << value << " ";
                    if (cards)
                        cout << " , ";
                    return_value += value;
                }
            }
            return return_value;
        }
    public:
        void determineWinner(int humanScore, int dealerScore)
        {
            if (humanScore == 21)
                cout << "You have 21. You win!" << endl;
            else if ((humanScore < 21) && (humanScore > dealerScore))
                cout << "You have the closer hand to 21. You win!" << endl;
            else
                cout << "The Dealer wins, sorry try again." << endl;
        }
    public:
        int Random(int lowerLimit, int upperLimit)
        {
            return 1 + rand() % (upperLimit - lowerLimit + 1);
        }
    };
    int main()
    {
        int option = 0;
        BlackJack obj;
        cout << "\n===============================" << endl;
        cout << "Welcome to the game BlackJack 21!" << endl;
        cout << "===============================" << endl;
        do {
            obj.playGame();
            cout << "\n would you like play again?" << endl;
            cout << " press 1-continue ,0-exit" << endl;
            cin >> option;
        } while (option == 1);
        cout << "\nThanks for playing!" << endl;
        return 0;
    }


