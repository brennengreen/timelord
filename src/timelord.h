#ifndef TIMELORD
#define TIMELORD

#include <string>
#include <iostream>

using namespace std;

int checkCommand(char* argv[]);
char getCommandChar(string command);
string startTimelord();
string quitTimelord();
string displayHelp();

char getCommandChar(string command) {
    string commandArray[3] = {"quit", "start", "help"};

    for (int i = 0; i < (sizeof(commandArray)/sizeof(string));++i) {
        if (command.compare(commandArray[i]) == 0) {
            return commandArray[i][0];
        }
    }
    return 'e';
}

string startTimelord() {
    // TODO: Write clock in UTC time to clockin.txt
    return "Clocking you in with timelord!";
}


string quitTimelord() {
    // TODO: Retrieve most recent(last line) clock in time from clockin.txt
    //       Calculate difference between clock in and clock out
    //       Store difference in seconds to database
    return "Clock out recorded!";
}

string displayHelp() {
    // TODO: Display desc/commands of timelord
    string helpMessage = ("Commands:\ntimelord start --Clocks you in with timelord\ntimelord quit --Clocks you out of timelord(records time worked)\ntimelord help --Displays this message");
    return (helpMessage);
}

int checkCommand(char* argv[]) {
    switch (getCommandChar(argv[1])) {
            case 's':
            // Description: Start timelord by logging current time
                cout << startTimelord() << endl;
                break;
            case 'q':
            // Description: Quit timelord by getting difference between most recent
            // clock in and current time. Log this time to database in seconds.
                cout << quitTimelord() << endl;
                break;
            case 'h':
            // Description: Display all possible commands for timelord
                cout << displayHelp() << endl;
                break;
            default:
                cout << "Invalid Arg.\nUse: timelord help for more usage information" << endl;
                return 1;
    };  
    return 0;
};
#endif