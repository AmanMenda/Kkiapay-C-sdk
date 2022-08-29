#include "./headers/constants.h"
#include "./headers/kkiapay.h"

int main(void)
{
    kkiapay_t *kkiapay = (kkiapay_t *)malloc(sizeof(*kkiapay));

    kkiapay->sandbox = true;
    kkiapay->public_key = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    kkiapay->private_key = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    kkiapay->secret = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    verify_transaction(kkiapay, "xxxxxxxxx");
    free(kkiapay);
}