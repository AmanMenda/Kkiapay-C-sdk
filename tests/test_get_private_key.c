#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include "../headers/kkiapay.h"
#include "../headers/constants.h"

Test(get_private_key, private_key_is_not_empty)
{
    kkiapay_t *kkiapay = malloc(sizeof(*kkiapay));
    char *private_key = "\0";

    kkiapay->private_key = "xxxxxxxxxxxxxxxxx";
    private_key = get_private_key(kkiapay);
    cr_assert_not_null(private_key);
    free(kkiapay);
}

Test(get_private_key, expected_key)
{
    kkiapay_t *kkiapay = malloc(sizeof(*kkiapay));
    char *private_key = "\0";

    kkiapay->private_key = "xxxxxxxxxxxxxxxxx";
    cr_assert_str_eq(kkiapay->private_key, "xxxxxxxxxxxxxxxxx");
    free(kkiapay);
}
