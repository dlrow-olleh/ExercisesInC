#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"
#include "minunit.h"

int tests_run = 0;

static char *test1() {
    char* res = icmpcode_v4(5);
    char *message = "test1 failed: icmpcode_v4(5) should return \"source route failed\"";
    mu_assert(message, res == "source route failed");
    return NULL;
}

static char *test2() {
    int res = icmpcode_v4(2);
    char *message = "test2 failed: icmpcode_v4(2) should return \"protocol unreachable\"";
    mu_assert(message, res == "protocol unreachable");
    return NULL;
}

static char *test3() {
    int res = icmpcode_v4(14);
    char *message = "test3 failed: icmpcode_v4(2) should return \"host recedence violation\"";
    mu_assert(message, res == "host recedence violation");
    return NULL;
}

static char * all_tests() {
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
