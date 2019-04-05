#include <iostream>
#include "timelord.h"

int main(int argc, char* argv[]){
    if (argc > 1) {
        if (check_command(argv) != 0) {
            return 1;
        }    
    } else {
        std::cout << "Main: Proper usage: timelord [command] [projectname]" << std::endl;
        return 1;
    }
    
    return 0;
}

