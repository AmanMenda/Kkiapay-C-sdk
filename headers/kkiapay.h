#ifndef KKIAPAY_H
    #define KKIAPAY_H

    #include <stdbool.h>

typedef struct kkiapay {
    char *public_key;
    char *private_key;
    char *secret;
    char *curl;
    bool sandbox;
}kkiapay_t;

extern void init_kkiapay_values(kkiapay_t *ptr, char *private_key, char *public_key,
                                char *secret, bool sandbox);

extern char *get_secret(kkiapay_t *ptr);

extern char *get_private_key(kkiapay_t *ptr);

extern char *get_public_key(kkiapay_t *ptr);

extern void init_kkiapay_values(kkiapay_t *kkiapay, char *private_key,
                                char *public_key, char *secret, bool sandbox);

extern char *verify_transaction(kkiapay_t *kkiapay, void *transaction_id);

#endif