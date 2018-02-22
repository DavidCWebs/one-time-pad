#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdio>
#define GetCurrentDir getcwd
// g++ create-pads.cpp -o create-pads -std=c++17
//
/**
 * @see https://answers.yahoo.com/question/index?qid=20120103153728AAh2PjZ
 * @see https://stackoverflow.com/a/145309/3590673
 * @param cCurrentPath [description]
 */
void currentPath(char &cCurrentPath) {
    // char cCurrentPath[FILENAME_MAX];
    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    {
        //return errno;
    }

    //cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
    return 0;
}

int main(int argc, char const *argv[])
{
    int status;
    const char* report;

    // status = mkdir("/home/david/aaa1234", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    // report = (status != 0) ? "FAIL" : "SUCCESS";
    // std::cout << "Status: " << report << std::endl;

    // define cCurrentPath as the maximum permissible path + filename
    char cCurrentPath[FILENAME_MAX];
    currentPath(cCurrentPath);
    printf ("The current working directory is '%s'\n", cCurrentPath);
    printf ("FILENAME_MAX is '%d'\n", FILENAME_MAX);
    // std::cout << "Current directory: " << ExePath() << std::endl;
    return 0;
}
