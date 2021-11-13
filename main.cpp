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

int main() {
	coloursClass contruct;
	contruct.level1();
	contruct.level2();
	contruct.level3();
}