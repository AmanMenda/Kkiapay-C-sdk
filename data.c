#include "./headers/constants.h"
#include "./headers/kkiapay.h"

char *get_private_key(kkiapay_t *kkiapay)
{
    return (kkiapay->private_key);
}

char *get_public_key(kkiapay_t *kkiapay)
{
    return (kkiapay->public_key);
}

char *get_secret(kkiapay_t *kkiapay)
{
    return (kkiapay->secret);
}

void
init_kkiapay_values(kkiapay_t *kkiapay, char *private_key, char *public_key,
                    char *secret, bool sandbox)
{
    kkiapay->private_key = private_key;
    kkiapay->public_key = public_key;
    kkiapay->secret = NULL;
    kkiapay->sandbox = false;
    //kkiapay->curl = 
}