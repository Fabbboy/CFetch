#include <stdlib.h>
#include "../include/GlobalLibs.h"
#include "../include/Fetch.h"
#include <string.h>

size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata){
    cJSON* response = (cJSON*)userdata;
    cJSON* data = cJSON_Parse(ptr);
    cJSON_AddItemToObject(response, "data", data);
    return size * nmemb;
};

cJSON* get(Fetch* fetch){
    CURL* curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, fetch->target);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fetch->response);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return fetch->response;
};

cJSON* post(struct Fetch* fetch, char* body, char* header){
    //Content-Type: application/json
    CURL* curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, fetch->target);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fetch->response);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body);
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, header);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return fetch->response;
};

double ping(Fetch* fetch){
    CURL* curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, fetch->target);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fetch->response);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);
        curl_easy_perform(curl);
        double time;
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &time);
        curl_easy_cleanup(curl);
        return time * 100;
    }
    return -1;
};

Fetch* setup_fetch(char* target){
    Fetch* fetch = (Fetch*)malloc(sizeof(Fetch));
    fetch->target = target;
    fetch->response = cJSON_CreateObject();
    fetch->get = get;
    fetch->post = post;
    fetch->ping = ping;
    return fetch;
};


