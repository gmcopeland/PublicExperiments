#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

bool getKey(int key, int rands[], int guesses[], int size){
    
    bool status = true;
    
    int i;
    for(i = 0; i <= size; i++)
    {
        
        rands[i] = (rands[i] + key);
        int j = i;
        if((rands[j] >= 10))
        {
            
            rands[j] = rands[j] - 10;
            
        }
    }
 
    bool check; 
    check = false;
    int correctnum;
    correctnum = 0;
        for(int i = 0; i <= size; i++){
            int j = i;
            if(int(guesses[j]) == int(rands[j])){
                
                
                status = true;
                
                correctnum++;
            
            }
            else if(int(guesses[j]) != int(rands[j])) {   
                
                
                status = false;
            }
        }
        if(correctnum == 4){check = true;}
        else check = false;
    
    
    return check;
}

int main(){

    
    bool playstate = true;

    cout << "Welcome to the 104th Hacking Simulator! It is a bit buggy but works!" << endl;
    cout << "Please follow the directions! They are simple but crucial!" << endl;
    cout << "         1: All numbers must be 0-9 when entered       " << endl;
    cout << "         2: Seperate all numbers with atleast one space" << endl;
    cout << "         3: If input other than numbers is required, it will be in single 'quotes' " << endl;
    cout << "                type it exactly as presented. It is case sensitive" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    while (playstate == true)
    {
        int randomvalues[3];
        int roundnum = 1;
        while (roundnum < 5) {

            char guessArray[3];
            int guess2[3];
            int key = 0;
            cout << "Round Number: " << roundnum << "/5" << endl << endl;
            

            cout << "The Encrypted Passcode is: " << endl;
            
           
            for(int i = 0; i <= 3; i++) {
                int newval;
                newval = (rand() %10);
                
                randomvalues[i] = newval;
                cout << randomvalues[i];
                
            }
            cout << endl;
            key = (rand() %9);
            cout << "Key to decrypt is: " << key << endl;
            cout << "Please decrypt the key and enter your answer" << endl;
            cout << "Place a space between the numbers" << endl;
 
            cin >> guess2[0] >> guess2[1] >> guess2[2] >> guess2[3];

            if(getKey(key,randomvalues,guess2,3)==true)
            {
                cout << "Correct" << endl;
                roundnum++;
            }
            else {
                cout << "Incorrect" << endl;
                roundnum = 1;
            }

        }
        cout << "Hack completed. Try again? Type 'Yes' or 'No'" << endl;
        string inp;
        cin >> inp;
        if (inp == "No")
            {
                playstate = false;
                roundnum = 1;
            }


    }


}