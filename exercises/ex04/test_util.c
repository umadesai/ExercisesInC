/* Test code for util.c in Software Systems class at Olin College.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "trout/util.h"
#include "minunit.h"

int tests_run = 0;

static char *test1() {
    char *res = icmpcode_v4(0);
    char *message = "test1 failed: icmpcode_v4(0) should return 'network unreachable'";
    mu_assert(message, strcmp(res, "network unreachable") == 0);
    return NULL;
}

static char *test2() {
    char *res = icmpcode_v4(2);
    char *message = "test1 failed: icmpcode_v4(0) should return 'protocol unreachable'";
    mu_assert(message, strcmp(res, "protocol unreachable") == 0);
    return NULL;
}

static char *test3() {
    char *res = icmpcode_v4(15);
    char *message = "test1 failed: icmpcode_v4(0) should return 'network unreachable'";
    mu_assert(message, strcmp(res, "precedence cutoff in effect") == 0);
    return NULL;
}

static char *all_tests() {
    mu_run_test(test1);
    mu_run_test(test2);
    mu_run_test(test3);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
