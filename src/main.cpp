#include <iostream>
#include "timelord.h"

int main(int argc, char* argv[]){
    if (argc > 1) {
        if (checkCommand(argv) != 0) {
            return 1;
        }    
    };
    
    return 0;
}

