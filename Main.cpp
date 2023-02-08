#include <iostream>
#include <string>

using namespace std;

string Monkey[] = { "rock", "paper", "scissors", "lizard", "spock" };

void print_greeting();

int input_throw(string thrower, string opponent);

int calc_winner(int throw1, int throw2);

int imagine[5][5] = {

                   2, 0, 1, 1, 0,
                   1, 2, 0, 0, 1,
                   0, 1, 2, 1, 0,
                   0, 1, 0, 2, 1,
                   1, 0, 1, 0, 2
};

int main() {
    print_greeting();
    string name1;
    string name2;
    cout << "Please enter Player 1's name: " << endl;
    cin >> name1;
    cout << "          " << endl;
    cout <<"Please enter Player 2's name: " << endl;
    cin >> name2;

    int throw1 = input_throw(name1, name2);
    int throw2 = input_throw(name2, name1);

    int winner = calc_winner(throw1, throw2);

    while (winner == 2) {
        cout << "It's a tie; both players will throw again." << endl;
        int throw1 = input_throw(name1, name2);
        int throw2 = input_throw(name2, name1);
        int winner = calc_winner(throw1, throw2);

        if (winner == 1) {
            cout << Monkey[throw1], "defeats", Monkey[throw2] + ".";
            cout << name1, "defeats", name2 + ".";
        }
        else {
            cout << Monkey[throw2], "defeats", Monkey[throw1] + ".";
            cout << name2, "defeats", name1 + ".";
        }
    }
}

void print_greeting() {
    cout << "Welcome to Rock-Paper-Scissors-Lizard-Spock!" << endl;

}
void print_gestures() {
    cout << "Choices are:" << endl; 
        cout << "(0) Rock, (1) Paper, (2) Scissors, (3) Lizard, (4) Spock" << endl;

}

int input_throw(string thrower, string opponent) {

    cout << "It is", thrower + "'s turn.";
    print_gestures();
    cout << "No peeking,", opponent + ".";
    int the_throw;
    cin >> the_throw;

    while (the_throw < 0 || the_throw >= sizeof(Monkey) / sizeof(Monkey[0])) {
        cout << "Invalid choice; try again.";
        cout << thrower << " what is your throw" << endl;
        cin >> the_throw;

    }
    cout << thrower, "throws", Monkey[the_throw] + ".";

    return the_throw;
}

int calc_winner(int throw1, int throw2) {
    return imagine[throw1][throw2];

}
