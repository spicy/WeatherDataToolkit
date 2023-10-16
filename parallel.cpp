#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

std::vector<pid_t> children;

void fetchWeatherForLocationParallel(double latitude, double longitude, int fileCounter)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        // Print required details
        std::cout << "Child PID: " << getpid() << " Parent PID: " << getppid() << std::endl;
        std::cout << "UID: " << getuid() << " GID: " << getgid() << std::endl;

        std::string filename = "file" + std::to_string(fileCounter) + ".json";
        std::string url = "https://api.open-meteo.com/v1/forecast?latitude=" + std::to_string(latitude) +
                          "&longitude=" + std::to_string(longitude) + "&currentweather=True";

        execlp("/usr/bin/curl", "curl", "-o", filename.c_str(), url.c_str(), NULL);
        perror("execlp");
        exit(1);
    }
    else if (pid < 0)
    {
        perror("fork");
        exit(1);
    }
}

int main()
{
    std::ifstream inputFile("locations.txt");
    std::string line;
    int fileCounter = 1;
    int numberOfLocations = 0;

    while (getline(inputFile, line))
    {
        std::istringstream iss(line);
        double latitude, longitude;
        iss >> latitude >> longitude;
        fetchWeatherForLocationParallel(latitude, longitude, fileCounter++);
        numberOfLocations++;
    }

    // waits for all children to complete
    for (int i = 0; i < numberOfLocations; i++)
    {
        wait(NULL);
    }

    inputFile.close();
    return 0;
}
