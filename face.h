#ifndef _FACE_H_ 
#define _FACE_H_

#include "NonBlockingGame.h"
#include <iostream>

using namespace bridges::game;
using namespace std;

class face : public NonBlockingGame { 
  private: 
    int eyelevel = 2;
    int eyeverticalone = 2; 
    int eyeverticaltwo = 7;
    int smilelevel = 7; 
  public:
    // First the constructor must be overwritten and the size of the grid passed in
    face(int assignmentID, std::string username, std::string apikey)
      : NonBlockingGame(assignmentID, username, apikey, 10, 10){};

    virtual void initialize() override {
    }

    // Game loop must be overwriten to complete the abstract class however,
    // it will not be used here. It is called every frame of the game loop.
    virtual void gameLoop() override {

      // wont have anything here for this assignment   


    }

}; 
#endif
