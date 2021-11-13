/* Levels 1-3 code
   Created by Gavin MacDonnell.
   13/11/21.*/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "colour-set-levels.h"

using namespace std::chrono_literals; //for time delays
using namespace std;

int counter;

string colours[4] = { "red","green","blue","pink" };
string allColours;
string choice;

void coloursClass::level1() {
    //level 1 - step by step yes or no modification
    cout << "L e v e l  1\n";
    int counter = 0;
    allColours = "{" + colours[0] + ", " + colours[1] + ", " + colours[2] + ", " + colours[3] + "}\n";
    cout << "The colour set is as follows: \n" << allColours << "\n";
    cout << "As seen above, ";

    while (counter < 4) {

        cout << "colour " << counter + 1 << " = " << colours[counter] << "\n" << "Would you like to change this colour? \n";
        string answer;
        cin >> answer;
        cout << "\n";

        if (answer == "Yes") {
            cout << "Write the new colour: ";
            cin >> colours[counter];
            cout << "Colour " << counter + 1 << " is " << colours[counter] << "\n\n";
        }
        else if (answer == "No") {
            //do nothing, move on
        }
        else if (answer == "Skip") {
            counter = 5;
        }
        else {
            cout << "I didn't get that, let's start over.\n";
        }
        counter = counter + 1;
    }
    allColours = "{" + colours[0] + ", " + colours[1] + ", " + colours[2] + ", " + colours[3] + "}\n";
    cout << "The most up to date colour set is as follows: \n" << allColours << "\n";

    //end of level 1
    cout << "You have sucessfully modified the colour set. Now let's get a bit more customiseable.\n\n";

}


void coloursClass::level2() {
    //level 2 - can type the colour to change the colour
    cout << "\n\nL e v e l  2\n";
    counter = 0;
    allColours = "{" + colours[0] + ", " + colours[1] + ", " + colours[2] + ", " + colours[3] + "}\n";
    cout << "The colour set is as follows: \n" << allColours << "\n";

    while (counter < 2) {
        cout << "Pick a colour to change a colour in the colour set, or just Skip.\n";
        string choice;
        cin >> choice;
        cout << "\n";

        for (int slot = 0; slot < 4; slot++) { //checks if what the user wrote is part of the colour set
            if (choice == colours[slot]) {
                cout << "You have chosen to modify the colour in slot " << slot + 1 << " which is " << colours[slot] << ".\n";
                cout << "Write the new colour: ";
                cin >> colours[slot];
                cout << "Colour in slot " << slot + 1 << " is now " << colours[slot] << "\n\n";
                counter = 1;
            }
            else if (choice == "Skip") {
                counter = 2;
            }
        } // can leave this loop without anything happeneing if the user didn't write one of the colours in the set or "Skip"

        if (counter == 0) { //would only enter this statement if the user didnt type a correct colour or type "Skip"
            cout << "I didn't get that, let's start over.\n";
        }

        allColours = "{" + colours[0] + ", " + colours[1] + ", " + colours[2] + ", " + colours[3] + "}\n";
        cout << "\nThe most up to date colour set is as follows: \n" << allColours << "\n";
    }

    //end of level 2
    cout << "You have intelligently modified the colour set. Now let's get even more customiseable.\n";
}


void coloursClass::level3() {
    //level 3 - user can make the set bigger or smaller if they would like
    cout << "\n\nL e v e l  3\n";
    counter = 0;
    int oldSetSize = 4;
    int setSize = oldSetSize;
    allColours = "{" + colours[0] + ", " + colours[1] + ", " + colours[2] + ", " + colours[3] + "}\n";
    cout << "The colour set is as follows: " << allColours << "\n";

    while (counter < 2) {

        string lessColours[5];
        string swapColours[5];
        string newColours[5];

        string threeColours[3];
        string fourColours[4];
        string fiveColours[5];


        cout << "1. Type a colour to change a colour in the colour set.\n";
        cout << "2. Type a new colour to add it.\n";
        cout << "3. Type 'delete' to remove a colour\n"; //done
        cout << "4. Type 'Skip' to move on.\n"; // done
        cout << "Set Size = " << setSize << ".\n";
        cout << "\n Input: ";
        cin >> choice;
        cout << "\n";

        if (choice == "delete") { //chose to delete a colour
            string removeColour;
            cout << "Remove: ";
            cin >> removeColour; //chosen colour to remove
            cout << "\n";

            for (int slot = 0; slot < setSize; slot++) {
                if (removeColour == colours[slot]) { //colour found
                    int value = 0;
                    while (value != slot) {
                        lessColours[value] = colours[value];
                        value++;
                    }
                    //value is now = slot
                    value++; //skipping the slot

                    while (value < setSize) { //for the rest of the array
                        lessColours[value - 1] = colours[value];
                        value++;
                        slot++;
                    }
                    cout << "Colour removed.\n";
                    setSize = setSize - 1;
                    if (setSize == 3) {
                        threeColours[0] = lessColours[0];
                        threeColours[1] = lessColours[1];
                        threeColours[2] = lessColours[2];
                        allColours = "{" + threeColours[0] + ", " + threeColours[1] + ", " + threeColours[2] + "}\n";
                    }
                    else if (setSize == 4) {
                        fourColours[0] = lessColours[0];
                        fourColours[1] = lessColours[1];
                        fourColours[2] = lessColours[2];
                        fourColours[3] = lessColours[3];
                        allColours = "{" + fourColours[0] + ", " + fourColours[1] + ", " + fourColours[2] + ", " + fourColours[3] + "}\n";
                    }
                    else if (setSize == 5) {
                        fiveColours[0] = lessColours[0];
                        fiveColours[1] = lessColours[1];
                        fiveColours[2] = lessColours[2];
                        fiveColours[3] = lessColours[3];
                        fiveColours[3] = lessColours[4];
                        allColours = "{" + fiveColours[0] + ", " + fiveColours[1] + ", " + fiveColours[2] + ", " + fiveColours[3] + ", " + fiveColours[4] + "}\n";
                    }


                    cout << "\nThe most up to date colour set (inside delete loop) is as follows: " << allColours << "\n";
                }
            } //only acts when colour found, and removes it
            counter = 1;
            setSize = 3;
        }

        else if (choice == "Skip") {
            counter = 2;
        }

        else if (choice == colours[0] || choice == colours[1] || choice == colours[2] || choice == colours[3]) { // colour input
            for (int slot = 0; slot < setSize; slot++) {
                if (choice == colours[slot]) { //replace a colour
                    string swapped = colours[slot];
                    cout << "Change " << colours[slot] << " to: ";
                    cin >> colours[slot];
                    cout << swapped << " is now " << colours[slot] << ".\n";
                    setSize = oldSetSize;

                    int value = 0;
                    while (value < setSize) {
                        swapColours[value] = colours[value];
                        value++;
                    }
                    allColours = "{" + swapColours[0] + ", " + swapColours[1] + ", " + swapColours[2] + ", " + swapColours[3] + "}\n";
                    slot = oldSetSize;
                }
            }
            counter = 1;
        }
        else {  // adding new colour
            newColours[0] = colours[0];
            newColours[1] = colours[1];
            newColours[2] = colours[2];
            newColours[3] = colours[3];
            newColours[4] = choice;
            allColours = "{" + newColours[0] + ", " + newColours[1] + ", " + newColours[2] + ", " + newColours[3] + ", " + newColours[4] + "}\n";
            counter = 1;
            setSize = setSize + 1;
        }
        cout << "Looking for changes...\n";
        this_thread::sleep_for(2s);
        cout << "The most up to date colour set is as follows: " << allColours << "\n";
    }
    //end of level 3
    cout << "You have super intelligently modified the colour set. Now let's get extremely intelligent.\n";
}