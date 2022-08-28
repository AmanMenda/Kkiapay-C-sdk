#include "./headers/constants.h"
#include "./headers/kkiapay.h"

int main(void)
{
    kkiapay_t *kkiapay = (kkiapay_t *)malloc(sizeof(*kkiapay));

    kkiapay->public_key = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    kkiapay->private_key = "xxxxxxxxxxxxxxxxxxxxxxxxxxx";
    kkiapay->secret = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    verify_transaction(kkiapay, "xxxxxxxxx");
}