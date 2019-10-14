#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <libubox/blobmsg_json.h>
#include <libubus.h>

static void ifStatusCb(struct ubus_request *req, int type, struct blob_attr *msg)
{
    printf("Harini invoked status on sample object from test \n");
}

int ubus_main(int argc, char **argv)
{
    const char *ubus_socket = NULL;
    static struct ubus_context *ctx;
    int ret;
    int ch;

    printf("HARINI in main\n");
    while ((ch = getopt(argc, argv, "cs:")) != -1) {
        switch (ch) {
        case 's':
            ubus_socket = optarg;
            break;
        default:
            break;
        }
    }

    argc -= optind;
    argv += optind;
    signal(SIGPIPE, SIG_IGN);

    ctx = ubus_connect(ubus_socket);
    if (!ctx) {
        fprintf(stderr, "Failed to connect to ubus\n");
        return -1;
    }

   printf("Socket connected to ubus \n");
   uint32_t id;
   ret = ubus_lookup_id(ctx, "sample", &id);
    
   if (ret != UBUS_STATUS_OK) {
       printf("Failed to fetch id: %s\n", ubus_strerror(ret));
       return;
   }

   struct blob_buf bb;
   ret = blob_buf_init(&bb, 0);
   printf("HARINI after buf init \n");

   ret = ubus_invoke(ctx, id, "status", bb.head, ifStatusCb, &ret, 1000);
   
   if (ret != UBUS_STATUS_OK) {
       printf("Failed to invoke method: %s\n", ubus_strerror(ret));
       return;
   }
    
    printf("Harini invoked method of sample from test \n");

    ubus_free(ctx);

    return 0;
}

