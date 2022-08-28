#include "./headers/constants.h"
#include "./headers/kkiapay.h"
#include <openssl/sha.h>

static char *last_response;

unsigned char *hash(kkiapay_t *kkiapay, char *hash)
{   
    hash = calloc(SHA224_DIGEST_LENGTH, sizeof(char));
    if (get_secret(kkiapay) == NULL) {
        fprintf(stderr, "Secret key has not been set");
        return (unsigned char *)EXIT_FAILURE;
    }
    SHA256(get_secret(kkiapay), strlen(kkiapay->secret), (unsigned char *)hash);
    return (unsigned char *)hash;
}

size_t gather_response(void *ptr, size_t size, size_t nmemb)
{
    strcat(last_response, (const char *)ptr);
    return (size * nmemb);
}

void free_resources(char *x_api_key, char *x_private_key, char *x_secret_key, char *transactionId)
{
    free(x_api_key);
    free(x_private_key);
    free(x_secret_key);
    free(transactionId);
}

void c_cleanup(struct curl_slist *headers, CURL *curl)
{
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

char *verify_transaction(kkiapay_t *kkiapay, void *transaction_id)
{
    CURL *curl;
    CURLcode response;
    char url[120] = {0};
    char readbuffer[512] = {0};
    struct curl_slist *headers = NULL;
    char *x_api_key = retrieve_x_api_key(kkiapay);
    char *x_private_key = retrieve_x_private_key(kkiapay);
    char *x_secret_key = retrieve_x_secret_key(kkiapay);
    char *payload = retrieve_transaction_id(kkiapay, transaction_id);
    long code;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "curl initialisation failure\n");
    }

    if (kkiapay->sandbox) {
        strcpy(url, KKIAPAY_SANDBOX_URL);
    } else {
        strcpy(url, KKIAPAY_BASE_URL);
    }
    strcat(url, "/api/v1/transactions/status");
    printf("URL: %s\n", url);

    headers = curl_slist_append(headers, "Accept: application/json");

    if (!x_api_key)
        fprintf(stderr, "Public key is undefined");
    headers = curl_slist_append(headers, x_api_key);

    if (!x_private_key)
        fprintf(stderr, "Private key is undefined");
    headers = curl_slist_append(headers, x_private_key);

    if (!x_secret_key)
        fprintf(stderr, "Secret key is undefined");
    headers = curl_slist_append(headers, x_secret_key);

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    if (!payload)
        fprintf(stderr, "Secret key is undefined");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    response = curl_easy_perform(curl);
    if (response != CURLE_OK) {
        fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(response));
    }
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
    printf("%ld", code);

    // last_response = "";
    // curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, gather_response);
    // curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readbuffer);
    // response = curl_easy_perform(curl);
    // printf("readbuffer --> %s\n", readbuffer);

    c_cleanup(headers, curl);
    free_resources(x_api_key, x_private_key, x_secret_key, payload);
}

