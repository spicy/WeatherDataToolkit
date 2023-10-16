#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void fetchWeatherForLocation(double latitude, double longitude, int fileCounter)
{
    pid_t pid = fork();
    if (pid == 0)
    {
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
    wait(NULL);
}

int main()
{
    std::ifstream inputFile("locations.txt");
    std::string line;
    int fileCounter = 1;

    while (getline(inputFile, line))
    {
        std::istringstream iss(line);
        double latitude, longitude;
        iss >> latitude >> longitude;
        fetchWeatherForLocation(latitude, longitude, fileCounter++);
    }

    inputFile.close();
    return 0;
}
