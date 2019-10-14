/*
 * RaptorClishPlugin.c
 *
 */

#include "ont_cli.h"
#include <signal.h>
#include <stdlib.h>

static void sighandler(int signo)
{
    if ((signo == SIGHUP) ||
        (signo == SIGILL) ||
        (signo == SIGINT) ||
        (signo == SIGTERM))
    {
        exit(0);
    }

    signo = signo; /* Happy compiler */

    return;
}

CLISH_PLUGIN_INIT(ont_cli)
{
    /* Setupo signal handling */
    if (signal(SIGHUP,  sighandler) == SIG_ERR)
        printf("\ncan't catch %d\n", __LINE__);
    if (signal( SIGILL, sighandler) == SIG_ERR)
        printf("\ncan't catch %d\n", __LINE__);
    if (signal( SIGINT, sighandler) == SIG_ERR)
        printf("\ncan't catch %d\n", __LINE__);
    if (signal( SIGTERM, sighandler) == SIG_ERR)
        printf("\ncan't catch %d\n", __LINE__);

    clish_plugin_add_psym(plugin, clish_show, "clish_show");

    clish_shell = clish_shell; /* Happy compiler */

    return 0;
}

