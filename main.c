#include <stdio.h>
#include <stdlib.h>
#include "fetch/include/Fetch.h"

int main() {
    Fetch *fetch = setup_fetch("localhost:3000");
    if (fetch) {
        char* header = "Content-Type: application/json";
        char* body = "{\"name\":\"test\"}";
        cJSON* response = fetch->post(fetch, body, header);
        printf("%s", cJSON_Print(response));
    }
    return 0;
}
