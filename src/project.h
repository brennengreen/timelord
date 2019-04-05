#ifndef TIMELORDPROJ
#define TIMELORDPROJ

#include <string>
#include <chrono>

class TimelordProject {
    public:
        TimelordProject(std::string projectName) {
            setProjectName(projectName);
            if (findProjectFile(projectName) == false) {
                writeProjectFile(projectName);
            }
        }
        
        void writeProjectClockIn(std::string projectFilePath);
        void writeProjectClockOut(std::string projectFilePath);

        void setProjectName(std::string projectName);
        void setProjectFilePathString(std::string projectFilePath);

        float receiveProjectHours();
        float receiveProjectHours();

        bool findProjectFile(std::string projectName);

        std::string writeProjectFile(std::string projectName);
        std::string getProjectName();
    private:
        std::string projectNameString;
        std::string projectFilePathString;
        // type projectStartTimeInMilliSec
};

#endif