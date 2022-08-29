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
// Test(get_public_key, public_key_is_not_empty)
// {
//     kkiapay_t *kkiapay = {0};
//     char *public_key = "\0";

//     kkiapay->public_key = "xxxxxxxxxxxxxxxxx";
//     public_key = get_public_key(kkiapay);
//     cr_assert_not_null(public_key);
// }

// Test(get_secret, secret_key_is_not_empty)
// {
//     kkiapay_t *kkiapay = {0};
//     char *secret_key = "\0";

//     kkiapay->secret = "xxxxxxxxxxxxxxxxx";
//     secret_key = get_secret(kkiapay);
//     cr_assert_not_null(secret_key);
// }
