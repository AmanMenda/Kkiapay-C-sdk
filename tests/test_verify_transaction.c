#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include "../headers/kkiapay.h"
#include "../headers/constants.h"

Test(free_resources, all_resources_are_freed)
{
    kkiapay_t *kkiapay = malloc(sizeof(*kkiapay));

    kkiapay->public_key = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    kkiapay->private_key = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    kkiapay->secret = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    char *x_api_key = retrieve_x_api_key(kkiapay);
    char *x_private_key = retrieve_x_private_key(kkiapay);
    char *secret_key = retrieve_x_secret_key(kkiapay);
    char *transactionId = retrieve_transaction_id(kkiapay, "xxxxxxxxx");

    free_resources(x_api_key, x_private_key, secret_key, transactionId);
    printf("%s", x_api_key);
    cr_assert_str_empty(x_api_key);
    cr_assert_str_empty(x_private_key);
    cr_assert_str_empty(secret_key);
    cr_assert_str_empty(transactionId);
}
