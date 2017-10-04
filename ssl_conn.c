#include "ssl_conn.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ssl_conn_impl {
    char ssl_prop[128];
} ssl_conn_impl_t;


static void
ssl_method (int x)
{
    puts("En SSL method");
}

static void
ssl_conn_bind(ssl_conn_t *ssl_conn)
{
    ssl_conn->ssl_method = &ssl_method;
}
int ssl_conn_init(conn_t *conn, void *ctx)
{
    ssl_conn_t *ssl_conn = (ssl_conn_t*)conn;
    // need to call super_init ssl_conn->super
    puts("En ssl_con_init");
    ssl_conn_bind(ssl_conn);
    //strcpy(ssl_conn->supe)
    ssl_conn->super.type = 2;
    return 0;
}