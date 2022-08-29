#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "../headers/kkiapay.h"
#include "../headers/constants.h"

Test(init_kkiapay_values, fields_not_empty)
{
    kkiapay_t *kkiapay = malloc(sizeof(*kkiapay));

    if (!kkiapay) return;
    init_kkiapay_values(kkiapay, "xxxxxxxxxxxxxxxxxxx", "xxxxxxxxxxxxxxxx",
                        "xxxxx", false);
    cr_assert_not_null(kkiapay->private_key);
    cr_assert_not_null(kkiapay->public_key);
    cr_assert_not_null(kkiapay->secret);
    cr_assert_not(kkiapay->sandbox);
}