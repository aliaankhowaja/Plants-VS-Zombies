//#include "LeaderBoard.h"
//
//
//Leaderboard::Leaderboard() : numPlayers(0) {}
//
//
//void Leaderboard::addPlayer(const Players& Players1_new) {
//    if (numPlayers < MAX_PLAYERS) {
//       
//        players[numPlayers++] = Players1_new;
//    }
//}
//
//void Leaderboard:: sortPlayers() {
//    for (int i = 0; i < numPlayers - 1; i++) {
//        for (int j = 0; j < numPlayers - i - 1; j++) {
//            if (players[j].getScore() < players[j + 1].getScore()) {
//                
//                Players temp = players[j];
//                Players[j] = players[j + 1];
//                Players[j + 1] = temp;
//            }
//        }
//    }
//}
//   
//string* GetTopThree() {
//    // Allocate memory for the array on the heap
//    string* ptr = new string[3];
//
//    // Populate the array
//    for (int i = 0; i < 3; i++) {
//  
//    }
//
//    // Return the pointer 
//    return ptr;
//}
//
//void display(const string* leaders) const {
//    
//}
//
//
