#include "./headers/constants.h"
#include "./headers/kkiapay.h"

char *retrieve_x_api_key(kkiapay_t *kkiapay)
{
    char *x_api_key = "\0";
    
    x_api_key = malloc(sizeof(char) * 52);
    strcpy(x_api_key, "X-API-KEY: ");
    strcat(x_api_key, kkiapay->public_key);

    return (x_api_key);
}

char *retrieve_x_private_key(kkiapay_t *kkiapay)
{
    char *x_private_key = "\0";
    
    x_private_key = malloc(sizeof(char) * 52);
    strcpy(x_private_key, "X-PRIVATE-KEY: ");
    strcat(x_private_key, kkiapay->private_key);

    return (x_private_key);
}

char *retrieve_x_secret_key(kkiapay_t *kkiapay)
{
    char *x_secret_key = "\0";
    
    x_secret_key = malloc(sizeof(char) * 52);
    strcpy(x_secret_key, "X-SECRET-KEY: ");
    strcat(x_secret_key, kkiapay->secret);

    return (x_secret_key);
}

char *retrieve_transaction_id(kkiapay_t *kkiapay, void *transaction_id)
{
    char *transactionId = "\0";
    
    transactionId = malloc(sizeof(char) * 52);
    strcpy(transactionId, "transactionId=");
    strcat(transactionId, (char *)transaction_id);

    return (transactionId);
}