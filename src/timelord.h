#ifndef TIMELORD
#define TIMELORD

#include <string>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int check_command(char* argv[]);
char get_command_char(string command);
string start_timelord();
string quit_timelord();
string display_help();

const string extension = ".txt";

char get_command_char(string command) {
    string command_arr[3] = {"quit", "start", "help"};

    for (int i = 0; i < (sizeof(command_arr)/sizeof(string));++i) {
        if (command.compare(command_arr[i]) == 0) {
            return command_arr[i][0];
        }
    }
    return 'e';
}

string start_timelord(std::string project_name) {
    // TODO: Declare and initialize new TimelordProject object
    
    std::string project_file_path = project_name + extension;

    fstream project_file;
    project_file.open(project_file_path, ios::in | ios::out);
    project_file << "Hi";
    
    string data;
    project_file >> data;

    cout << data << endl;

    std::string message = "Clocked you into " + project_name + " with timelord!";
    // TODO: Write clock in in millis to clockin.txt
    return message;
}


string quit_timelord() {
    // TODO: Retrieve most recent(last line) clock in time from clockin.txt
    //       Calculate difference between clock in and clock out
    //       Store difference in seconds to database
    return "Clock out recorded!";
}

string display_help() {
    // TODO: Display desc/commands of timelord
    string help_message = ("Commands:\ntimelord start [project] --Clocks you in with timelord\ntimelord quit [project] --Clocks you out of timelord(records time worked)\ntimelord help --Displays this message");
    return (help_message);
}

int check_command(char* argv[]) {
    // Ensure required commands were given at command line
    if (argv[1] == 0 || argv[2] == 0) {
        cout << "Proper usage: timelord [command] [project_name]" << endl;
        return 1;
    }

    switch (get_command_char(argv[1])) {
            case 's':
            // Description: Start timelord by logging current time
                
                // If a file project path is supplied at command line
                // then it'll feed that to the function and avoid searching for/creating
                // a project file
                
                cout << start_timelord(argv[2]) << endl;
                break;
            case 'q':
            // Description: Quit timelord by getting difference between most recent
            // clock in and current time. Log this time to database in seconds.
                cout << quit_timelord() << endl;
                break;
            case 'h':
            // Description: Display all possible commands for timelord
                cout << display_help() << endl;
                break;
            default:
                cout << "Invalid Arg.\nUse: timelord help for more usage information" << endl;
                return 1;
    };  
    return 0;
};
#endif