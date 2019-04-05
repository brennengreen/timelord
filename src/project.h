#ifndef TIMELORDPROJ
#define TIMELORDPROJ

#include <string>
#include <chrono>

class TimelordProject {
    public:
        TimelordProject(std::string projectName) {
            set_name(projectName);
            if (find_file(projectName) == false) {
                write_file(projectName);
            }
        }
        
        void clock_in(std::string path);
        void clock_out(std::string path);

        void set_name(std::string name);
        void set_path(std::string path);

        float receive_hours();

        bool find_file(std::string name);

        std::string write_file(std::string name);
        std::string get_name();
    private:
        std::string name_string;
        std::string path_string;
        // type projectStartTimeInMilliSec
};

#endif