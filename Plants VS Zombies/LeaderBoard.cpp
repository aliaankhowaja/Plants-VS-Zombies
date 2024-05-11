#include "LeaderBoard.h"


Leaderboard::Leaderboard() : numPlayers(0) {}


//void Leaderboard::addPlayer(const Players& Players1_new) {
//    if (numPlayers < MAX_PLAYERS) {
//       
//        players[numPlayers++] = Players1_new;
//    }
//}

//////void Leaderboard::sortPlayers() {
//////    for (int i = 0; i < numPlayers - 1; i++) {
//////        for (int j = 0; j < numPlayers - i - 1; j++) {
//////            if (players[j].getScore() < players[j + 1].getScore()) {
//////                
//////                Players temp = players[j];
//////                players[j] = players[j + 1];
//////                players[j + 1] = temp;
//////            }
//////        }
//////    }
//////}
////
////string* GetTopThree() {
////    // Allocate memory for the array on the heap
////    string* ptr = new string[3];
////
////    // Populate the array
////    for (int i = 0; i < 3; i++) {
////    //////////////////    ptr[i] = new string(players[i].getPlayerName() + " Score: " + players[i].getScore());
////    }
////
////    // Return the pointer (caller becomes responsible for deallocation)
////    return ptr;
////}

//void display(const string* leaders) const {
    //sf::Font font;
    //font.loadFromFile("Resources/Fonts/TheZombieBirds.ttf");

    //sf::Text text;
    //text.setFont(font);
    //text.setCharacterSize(24);
    //text.setFillColor(sf::Color::White);
    //text.setPosition(10, 10);

    //for (int i = 0; i < 3; ++i) {
    //    // Check for null pointer before accessing (avoid potential crash)
    //    //////if (leaders[i] != nullptr) {
    //        text.setString(*leaders[i]); // Dereference to access the string content
    //    }
    //    else {
    //        // Handle case where leader wasn't populated (e.g., set default text)
    //        text.setString("N/A");
    //    }
    //    window.draw(text);
    //    text.move(0, 30);
    //}

    //window.display();

    // **Important: Caller must deallocate the array after use**
    // delete[] leaders;  // This would be done in the calling code
}


