#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include "../headers/kkiapay.h"
#include "../headers/constants.h"

Test(retrieve_x_api_key, x_api_key_not_empty)
{
    kkiapay_t *kkiapay = malloc(sizeof(*kkiapay));

    if (!kkiapay) return;
    kkiapay->public_key = "xxxxxxxxxxxxxx";
    char *x_api_key = retrieve_x_api_key(kkiapay);
    cr_assert_not_null(x_api_key);
    free(kkiapay);
}

Test(retrieve_x_private_key, x_private_key_not_empty)
{
    kkiapay_t *kkiapay = malloc(sizeof(*kkiapay));

    if (!kkiapay) return;
    kkiapay->private_key = "xxxxxxxxxxxxxx";
    char *x_private_key = retrieve_x_private_key(kkiapay);
    cr_assert_not_null(x_private_key);
    free(kkiapay);
}

Test(retrieve_x_secret_key, x_secret_key_not_empty)
{
    kkiapay_t *kkiapay = malloc(sizeof(*kkiapay));

    if (!kkiapay) return;
    char *x_secret_key = retrieve_x_secret_key(kkiapay);
    cr_assert_not_null(x_secret_key);
    free(kkiapay);
}

Test(retrieve_transaction_id, transaction_id_not_empty)
{
    kkiapay_t *kkiapay = malloc(sizeof(*kkiapay));

    if (!kkiapay) return;
    char *transactionId = retrieve_transaction_id(kkiapay, "xxxxxxxxx");
    cr_assert_not_null(transactionId);
    free(kkiapay);
}