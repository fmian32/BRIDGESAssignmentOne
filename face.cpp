#include "face.h" 
#include <iostream>

using namespace bridges::game;
using namespace std; 

face::face(int assignmentID, std::string username, std::string apikey): NonBlockingGame(assignmentID, username, apikey, 10, 10) {} 

virtual void face::initialize() override {
      // Set the title for the game which will show up as a title on the page
      setTitle("Face");
      // Set a description which will show under the title
      setDescription("Draw a happy face on your game grid \n key down and key up");

      int i,j;

      // do all of your drawing of the face here, two eyes and a smiley 
      //Nested for loops iterate over the board and create the initial smily
      for(i = 0; i<getBoardHeight(); i++) 
      { 
        for(j = 0; j<getBoardWidth();j++) 
        { 
          try {
          setBGColor(i,j,NamedColor::green); //backdrop 
          }catch(...) 
          { 
            cerr<<"Issue in assigning backdrop in initialize."<<endl;
          }
        if(i == eyelevel&&(j==eyeverticalone||j==eyeverticaltwo)) //create eyes
        {  
          //cout<<i<<" "<<j<<endl; 
          try{
          setBGColor(i,j,NamedColor::yellow); 
          drawSymbol(i,j,NamedSymbol::circle,NamedColor::black); 
          }catch(...) 
          { 
            cerr<<"Issue in assigning eye color initial state."<<endl;
          }
        }
        
        if(i==(smilelevel-2)&&(j==(eyeverticalone-1)||j==(eyeverticaltwo+1)))//create horizontal smile
        {  
          try{
          setBGColor(i,j,NamedColor::blue);  
          }catch(...) 
          { 
            cerr<<"Issue in assigning base smile."<<endl;
          }
        }
        if(i==(smilelevel-1)&&(j==eyeverticalone||j==eyeverticaltwo))//create dimple set 2
        {  
           try{
           setBGColor(i,j,NamedColor::blue); 
           }catch(...) 
           { 
             cerr<<"Issue in assigning dimple set 2."<<endl;
           }
        }
        
        if(i==smilelevel&&(j>=(eyeverticalone+1)&&j<=(eyeverticaltwo-1)))//create dimple set 1(first blue boxes from the middle)
        {  
          try{
         setBGColor(i,j,NamedColor::blue);
          }catch(...) 
          { 
            cerr<<"Issue in assigning dimple set 1."<<endl;
          }
        } 
        } 
      }
    }

    // Game loop must be overwriten to complete the abstract class however,
    // it will not be used here. It is called every frame of the game loop.
    virtual void face::gameLoop() override {

      // wont have anything here for this assignment   
      
      if(keyUp()) { 
        for(int i = 0; i<getBoardHeight();i++) 
        { 
          for(int j = 0; j<getBoardWidth();j++) 
          { try{
            setBGColor(i,j,NamedColor::ivory); //create backdrop 
          }catch(...) 
          { 
            cerr<<"Issue in assigning backdrop of gameloop()"<<endl;
          }
            if(i==eyelevel&&(j==eyeverticalone||j==eyeverticaltwo))//set eye backdrop
            { try{
              setBGColor(i,j,NamedColor::red); 
            }catch(...) 
            { 
              cerr<<"Issue in assigning eye backdrop of gameloop()"<<endl;
            }
            }
            if((i==smilelevel||i==smilelevel-4)&&(j>=eyeverticalone+1&&j<=eyeverticaltwo-1))//set base smile
            { 
              try{
              setBGColor(i,j,NamedColor::black);  
              }catch(...) 
              { 
                cerr<<"Issue in assigning base smile of gameloop()"<<endl;
              }
            }
            if((i==smilelevel-1||i==smilelevel-3)&&(j==eyeverticalone||j==eyeverticaltwo))//set dimple set 1
            { 
              try{
              setBGColor(i,j,NamedColor::black); 
              }catch(...) 
              { 
                cerr<<"Issue in assigning dimple set 1 of gameloop()"<<endl;
              }
            }
            if((i==smilelevel-2)&&(j==eyeverticalone-1||j==eyeverticaltwo+1)) //set dimple set 2
            { try{
              setBGColor(i,j,NamedColor::black); 
            }catch(...) 
            { 
              cerr<<"Issue in assigning dimple set 2 of gameloop()"<<endl;
            }
            }
            if((i==smilelevel-1||i==smilelevel-3)&&(j>=(eyeverticalone+1)&&j<=(eyeverticaltwo-1)))//color mouth set 1
            { 
              try{
              setBGColor(i,j,NamedColor::red); 
              }catch(...) 
              { 
                cerr<<"Issue in assigning mouth set 1 of gameloop()"<<endl;
              }
            }
            if((i==smilelevel-2)&&(j>=eyeverticalone&&j<=eyeverticaltwo))//color mout set 2(base mouth line)
            {  
              try{
              setBGColor(i,j,NamedColor::red); 
              }catch(...) 
              { 
                cerr<<"Issue in assigning mouth set 2 of gameloop()"<<endl;
              }
              if(j==eyeverticalone+1) 
              {  
                try{
                drawSymbol(i,j,NamedSymbol::B,NamedColor::white);//create BOO symbol (with bomb icon at the end) 
                }catch(...) 
                { 
                  cerr<<"Issue in assigning B symbol of gameloop()"<<endl;
                }
              }
              if(j==eyeverticalone+2||j==eyeverticalone+3) 
              {  
                try{
                drawSymbol(i,j,NamedSymbol::O,NamedColor::white);
                }catch(...) 
                { 
                  cerr<<"Issue in assigning o symbol of gameloop()"<<endl;
                }
              }
              if(j==eyeverticalone+4) 
              {  
                try{
                drawSymbol(i,j,NamedSymbol::bomb, NamedColor::black); 
                }catch(...) 
                { 
                  cerr<<"Issue in assigning bomb symbol of gameloop()"<<endl;
                }
              }
            }
          }
        } 

      } 
      
     /*
      if(keyUP()) 
      { 
        
      }*/

      if(keyDown()) 
      { 
        int i,j;
        /* 
         nested for loops repeated from initialize()/ allows user to toggle back and forth between boo! screen and original smiley
        */
        for(i = 0; i<getBoardHeight(); i++) 
      { 
        for(j = 0; j<getBoardWidth();j++) 
        { 
          try {
          setBGColor(i,j,NamedColor::green); //backdrop 
          }catch(...) 
          { 
            cerr<<"Issue in assigning backdrop in initialize."<<endl;
          }
        if(i == eyelevel&&(j==eyeverticalone||j==eyeverticaltwo)) //create eyes
        {  
          //cout<<i<<" "<<j<<endl; 
          try{
          setBGColor(i,j,NamedColor::yellow); 
          drawSymbol(i,j,NamedSymbol::circle,NamedColor::black); 
          }catch(...) 
          { 
            cerr<<"Issue in assigning eye color initial state."<<endl;
          }
        }
        
        if(i==(smilelevel-2)&&(j==(eyeverticalone-1)||j==(eyeverticaltwo+1)))//create horizontal smile
        {  
          try{
          setBGColor(i,j,NamedColor::blue);  
          }catch(...) 
          { 
            cerr<<"Issue in assigning base smile."<<endl;
          }
        }
        if(i==(smilelevel-1)&&(j==eyeverticalone||j==eyeverticaltwo))//create dimple set 2
        {  
           try{
           setBGColor(i,j,NamedColor::blue); 
           }catch(...) 
           { 
             cerr<<"Issue in assigning dimple set 2."<<endl;
           }
        }
        
        if(i==smilelevel&&(j>=(eyeverticalone+1)&&j<=(eyeverticaltwo-1)))//create dimple set 1(first blue boxes from the middle)
        {  
          try{
         setBGColor(i,j,NamedColor::blue);
          }catch(...) 
          { 
            cerr<<"Issue in assigning dimple set 1."<<endl;
          }
        } 
        } 
      }
      } 
       /*
      if(keyS()) 
      { 
        this.setDescription("Pressing S");
        
      } 
      */
      if(keyQ()) 
      { 
        exit(1);//exit program
      } 


    }