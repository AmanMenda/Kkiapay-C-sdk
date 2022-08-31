#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include "../headers/kkiapay.h"
#include "../headers/constants.h"

Test(free_resources, sandbox_url)
{
    kkiapay_t *kkiapay = malloc(sizeof(*kkiapay));

    kkiapay->sandbox = true;
    char url[120] = {0};
    
    retrieve_url(kkiapay, url);
    cr_assert_str_eq(url, "https://api-sandbox.kkiapay.me/api/v1/transactions/status");
}

Test(free_resources, base_url)
{
    kkiapay_t *kkiapay = malloc(sizeof(*kkiapay));

    kkiapay->sandbox = false;
    char url[120] = {0};
    
    retrieve_url(kkiapay, url);
    cr_assert_str_eq(url, "https://api.kkiapay.me/api/v1/transactions/status");
}
