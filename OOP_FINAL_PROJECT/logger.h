#ifndef LOGGER_H
#define LOGGER_H

#include <cstdio>

class Logger {
public:
    static void logEvent(const char* message) {
        FILE* file = fopen("log.txt", "a");
        if (file) {
            fprintf(file, "%s\n", message);
            fclose(file);
        }
    }
};

#endif
