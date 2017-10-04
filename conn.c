
#include "conn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct conn_impl {
    char name[128];
} conn_impl_t;


static int
conn_read(conn_t *this, void *ctx)
{
    printf("CON read, type=%d\n", this->type);
    return 0;
}

static void
con_bind(conn_t *conn)
{
    conn->read = &conn_read;
}

int con_init(conn_t *con, void *ctx)
{
    puts("En con_init");
    con->impl = calloc(1,sizeof(conn_impl_t));

    con_bind(con);
    strcpy(con->impl->name, "SOY CONN");
    con->type = 1;
    return 0;
}