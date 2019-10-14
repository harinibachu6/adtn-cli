/**
 * @file    ClishRaptor.cpp
 * @brief   
 */

#include "ClishRaptor.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <grp.h>
#include <assert.h>
#include <string.h>
#include <iostream>
#include "ubus_main.c"

void ClishRaptorInit( void )
{
    //Set Environment variable for prompt
    setenv("PATH", "/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin", 1);
}

int clish_show(void *clish_context,
                 const char *script,
                 char **out)
{
    clish_shell_t *this = clish_context__get_shell(clish_context);
    int argc;
    char **argv;
    tinyrl_t *tinyrl = clish_shell__get_tinyrl(this);
    tinyrl_printf(tinyrl, "Inside C function: Before ubus\n");
    ubus_main(argc, argv);
    tinyrl_printf(tinyrl, "Inside C function: After ubus main\n");
    script = script; /* Happy compiler */
    out = out; /* Happy compiler */

    return 0;
}
