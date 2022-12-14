# CFetch
CFetch is a Library that uses CURL and cJSON to fetch data from the web. You just have to use the functions.

## How to use
1. Download the library
2. Include the header file
3. Compile the library
```
mkdir build
cd build
cmake ..
make
```
4. Link the library

**!!IMPROTANT THIS WORKS IF YOU ON MACOSX AND INSTALLED THE LIBS WITH HOMEBREW!!
else you have to change the path to the libs**
## Usage
This example gets the current bitcoin price in USD
```c
int main() {
    Fetch *fetch = setup_fetch("https://api.coingecko.com/api/v3/simple/price?ids=bitcoin&vs_currencies=usd");
    if (fetch) {
        cJSON *response = fetch->get(fetch);
        char* btcusd = cJSON_Print(cJSON_GetObjectItem(cJSON_GetObjectItem(cJSON_GetObjectItem(response, "data"), "bitcoin"), "usd"));
        printf("BTC/USD: %s", btcusd);
    }
    return 0;
}
```
Sends a JSON POST request
```c
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
```