#include "./headers/constants.h"
#include "./headers/kkiapay.h"

char *retrieve_x_api_key(kkiapay_t *kkiapay)
{
    char *x_api_key = malloc(sizeof(char) * 52);

    strcpy(x_api_key, "\"");
    strcat(x_api_key, "X-API-KEY: ");
    strcat(x_api_key, kkiapay->public_key);
    strcat(x_api_key, "\"");
    printf("x-api-key: %s\n", x_api_key);

    return (x_api_key);
}

char *retrieve_x_private_key(kkiapay_t *kkiapay)
{
    char *x_private_key = malloc(sizeof(char) * 52);

    strcpy(x_private_key, "\"");
    strcat(x_private_key, "X-PRIVATE-KEY: ");
    strcat(x_private_key, kkiapay->private_key);
    strcat(x_private_key, "\"");
    printf("x-private-key: %s\n", x_private_key);

    return (x_private_key);
}

char *retrieve_x_secret_key(kkiapay_t *kkiapay)
{
    char *x_secret_key = malloc(sizeof(char) * 52);

    strcpy(x_secret_key, "\"");
    strcat(x_secret_key, "X-SECRET-KEY: ");
    strcat(x_secret_key, kkiapay->secret);
    strcat(x_secret_key, "\"");
    printf("x-secret-key: %s\n", x_secret_key);

    return (x_secret_key);
}

char *retrieve_transaction_id(kkiapay_t *kkiapay, void *transaction_id)
{
    char *transactionId = malloc(sizeof(char) * 52);

    strcpy(transactionId, "\"");
    strcat(transactionId, "transactionId: ");
    strcat(transactionId, (char *)transaction_id);
    strcat(transactionId, "\"");
    printf("transactionId: %s\n", transactionId);

    return (transactionId);
}