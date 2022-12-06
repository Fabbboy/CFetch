#include <stdio.h>
#include <stdlib.h>
#include "fetch/include/Fetch.h"

int main() {
    Fetch *fetch = setup_fetch("https://api.coingecko.com/api/v3/simple/price?ids=bitcoin&vs_currencies=usd");
    if (fetch) {
        cJSON *response = fetch->get(fetch);
        char* btcusd = cJSON_Print(cJSON_GetObjectItem(cJSON_GetObjectItem(cJSON_GetObjectItem(response, "data"), "bitcoin"), "usd"));
        printf("BTC/USD: %s", btcusd);
    }
    return 0;
}
