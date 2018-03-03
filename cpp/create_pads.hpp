#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdio>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <ctime>
#include <sstream>
#include "random.hpp"

std::string getcwd();
std::string currentTimestamp();

std::string currentTimestamp()
{
    time_t now = time(0); // seconds since start of UNIX epoch
    tm *ltm = localtime(&now);
    std::stringstream timestamp;

    timestamp << std::setfill('0') << std::setw(2) << ltm->tm_mday << "-"
        << std::setfill('0') << std::setw(2) << ltm->tm_mon + 1 << "-"
        << ltm->tm_year + 1900 << ":"
        << std::setfill('0') << std::setw(2) << ltm->tm_hour << ":"
        << std::setfill('0') << std::setw(2) << ltm->tm_min << ":"
        << std::setfill('0') << std::setw(2) << ltm->tm_sec;

    return timestamp.str().c_str();
}

/**
* @see https://answers.yahoo.com/question/index?qid=20120103153728AAh2PjZ
* @see https://stackoverflow.com/a/145309/3590673
* @param cCurrentPath [description]
*/
std::string getcwd()
{
    const size_t chunkSize = 255;
    const int maxChunks = 10240; // 2550 KiBs of current path are more than enough
    char stackBuffer[chunkSize]; // Stack buffer for the "normal" case

    if (getcwd(stackBuffer, sizeof(stackBuffer)) != NULL) {
        return stackBuffer;
    }

    if (errno != ERANGE) {
        // It's not ERANGE, so we don't know how to handle it
        throw std::runtime_error("Cannot determine the current path.");
    }
    // Ok, the stack buffer isn't long enough; fallback to heap allocation
    for(int chunks=2; chunks < maxChunks; chunks++) {
        std::unique_ptr<char> cwd(new char[chunkSize*chunks]);
        if(getcwd(cwd.get(),chunkSize*chunks) != NULL) {
            return cwd.get();
        }
        if(errno != ERANGE) {
            // It's not ERANGE, so we don't know how to handle it
            throw std::runtime_error("Cannot determine the current path.");
        }
    }
    throw std::runtime_error("Cannot determine the current path; the path is apparently unreasonably long");
}
