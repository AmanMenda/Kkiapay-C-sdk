#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include "../headers/kkiapay.h"
#include "../headers/constants.h"

Test(get_public_key, public_key_is_not_empty)
{
    kkiapay_t *kkiapay = malloc(sizeof(*kkiapay));
    char *public_key = "\0";

    kkiapay->public_key = "xxxxxxxxxxxxxxxxx";
    public_key = get_public_key(kkiapay);
    cr_assert_not_null(public_key);
    free(kkiapay);
}

Test(get_public_key, expected_key)
{
    kkiapay_t *kkiapay = malloc(sizeof(*kkiapay));
    char *public_key = "\0";

    kkiapay->public_key = "xxxxxxxxxxxxxxxxx";
    cr_assert_str_eq(kkiapay->public_key, "xxxxxxxxxxxxxxxxx");
    free(kkiapay);
}