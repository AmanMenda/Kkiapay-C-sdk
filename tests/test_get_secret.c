#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "../headers/kkiapay.h"
#include "../headers/constants.h"

Test(get_secret, secret_key_is_not_empty)
{
    kkiapay_t *kkiapay = malloc(sizeof(*kkiapay));
    char *secret = "\0";

    kkiapay->secret = "xxxxxxxxxxxxxxxxx";
    secret = get_secret(kkiapay);
    cr_assert_not_null(secret);
    free(kkiapay);
}

Test(get_secret, expected_key)
{
    kkiapay_t *kkiapay = malloc(sizeof(*kkiapay));
    char *secret = "\0";

    kkiapay->secret = "xxxxxxxxxxxxxxxxx";
    cr_assert_str_eq(kkiapay->secret, "xxxxxxxxxxxxxxxxx");
    free(kkiapay);
}