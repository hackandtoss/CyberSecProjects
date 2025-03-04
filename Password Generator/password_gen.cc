#include <iostream>
#include <string> 
#include <random>
using namespace std;

void die(string msg = "BAD INPUT") {
    cout << msg << endl;
    // Star Wars reference
    exit(66);
}


int main() {
    
    // Random number generator
    random_device rd;
    mt19937_64 gen(rd());

    string password;
    
    // Constants for the characters
    const string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string LOWER = "abcdefghijklmnopqrstuvwxyz";
    const string NUM = "0123456789";
    const string SPECIAL = "!@#$%^&*()_+<>?:{}";
    
    // Length of the password
    int length = 0;

    cout << "Enter the length of the password: ";
    cin >> length; 

    // Check if the input is valid
    if (!cin) {
        die();
    }

    // Check if the length is between 1 and 100
    if (length < 1 || length > 100) {
        die("Invalid length (Password must be between 1 and 100 characters)");
    }

    // Menu for choosing the characters 1 - 6
    cout << "Choose the characters for the password: " << endl;
    cout << "1. Uppercase" << endl;
    cout << "2. Lowercase" << endl;
    cout << "3. Numbers" << endl;
    cout << "4. Upper and Lowercase" << endl;
    cout << "5. Upper, Lowercase, and Numbers" << endl;
    cout << "6. Upper, Lowercase, Numbers, and Special Characters" << endl;

    int choice = 0;
    cin >> choice; 

    // Check if the input is valid
    if (!cin) {
        die();
    }

    // Check if the choice is between 1 and 6
    if (choice < 1 || choice > 6) {
        die("Invalid choice");
    }

    string characters;

    switch (choice) {
        case 1:
            characters = UPPER;
            break;
        case 2:
            characters = LOWER;
            break;
        case 3:
            characters = NUM;
            break;
        case 4:
            characters = UPPER + LOWER;
            break;
        case 5:
            characters = UPPER + LOWER + NUM;
            break;
        case 6:
            characters = UPPER + LOWER + NUM + SPECIAL;
            break;
    }

    // Distribution for the characters
    uniform_int_distribution<int> dist(0, characters.size() - 1);

    for (int i = 0; i < length; i++) {
        password += characters[dist(gen)];
    }

    cout << "Generated password: " << password << endl;

    return 0;
}