#ifndef CONSTANTS_H
    #define CONSTANTS_H

    #define KKIAPAY_BASE_URL "https://api.kkiapay.me"
    #define KKIAPAY_SANDBOX_URL "https://api-sandbox.kkiapay.me"

    #define SUCCESS "SUCCESS"
    #define INVALID_TRANSACTION "INVALID_TRANSACTION"
    #define INVALID_TRANSACTION_TYPE "INVALID_TRANSACTION_TYPE"
    #define TRANSACTION_NOT_FOUND "TRANSACTION_NOT_FOUND"
    #define TRANSACTION_NOT_ELIGIBLE "TRANSACTION_NOT_ELIGIBLE"
    #define INSUFFICIENT_FUND "INSUFFICIENT_FUND"
    #define PENDING "PENDING"
    #define FAILED "FAILED"
    #define REVERTED "REVERTED"

    #include <stdlib.h>
    #include <curl/curl.h>
    #include <stdio.h>
    #include <string.h>
    #include "kkiapay.h"


extern char *retrieve_x_private_key(kkiapay_t *kkiapay);

extern char *retrieve_x_secret_key(kkiapay_t *kkiapay);

extern char *retrieve_transaction_id(kkiapay_t *kkiapay, void *transaction_id);

extern char *retrieve_x_api_key(kkiapay_t *kkiapay);

extern void free_resources(char *x_api_key, char *x_private_key, char *x_secret_key, char *transactionId);

#endif