#include <iostream>
#include <string>

using namespace std;

char getCommandChar(string command);
string runTimelord();
string quitTimelord();
string displayHelp();

int main(int argc, char **argv){
    if (argc > 1) {
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
        };  
    };
    return 0;
}

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
    return ("Commands:",
    "\ntimelord start --Clocks you in with timelor",
    "\ntimelord quit --Clocks you out of timelord(records time worked)",
    "\ntimelord help --Displays this message");
}