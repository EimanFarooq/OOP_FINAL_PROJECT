#ifndef LOGGER_H
#define LOGGER_H

#define _CRT_SECURE_NO_WARNINGS  

#include <cstdio>

class Logger {
public:
    static void logEvent(const char* message) {
        FILE* file;
        fopen_s(&file, "log.txt", "a");
        if (file) {
            fprintf(file, "%s\n", message);
            fclose(file);
        }
    }
};

#endif
