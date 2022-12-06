#include "GlobalLibs.h"

//this is like node-fetch but in C


typedef struct Fetch{
    char* target;
    cJSON* response;

    cJSON* (*get)(struct Fetch* fetch);
    cJSON* (*post)(struct Fetch* fetch, char* body, char* header);
    double (*ping)(struct Fetch* fetch);
}Fetch;


Fetch* setup_fetch(char* target);

//write_callback
size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata);