#include "ssl_conn.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ssl_conn_impl {
    char ssl_prop[128];
} ssl_conn_impl_t;


static void
ssl_method (ssl_conn_t *this, int x)
{
    printf("En SSL method, type is %d\n", this->super.type);
}

static int
ssl_read(ssl_conn_t *this, void *ctx)
{
    printf("SSL read, type is %d\n",
        this->super.type);
    return 0;
}

static void
ssl_conn_bind(ssl_conn_t *ssl_conn)
{
    ssl_conn->ssl_method = &ssl_method;
}
int ssl_conn_init(conn_t *conn, void *ctx)
{
    ssl_conn_t *ssl_conn = (ssl_conn_t*)conn;
    puts("En ssl_con_init");
    ssl_conn_bind(ssl_conn);
    ssl_conn->super.type = 2;
    ssl_conn->super.read = (con_func)&ssl_read;
    return 0;
}