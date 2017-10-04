#include <stdio.h>
#include "conn.h"
#include "ssl_conn.h"


conn_t conns[2];


void perform_ssl(conn_t *conn)
{
    ssl_conn_t *ssl_conn = (ssl_conn_t*)conn;
    ssl_conn->ssl_method(ssl_conn, 1);
}

void perform(conn_t *conn)
{
    conn->read(conn, NULL);
    conn->write(conn, NULL);
    if (conn->type == 2) {
        perform_ssl(conn);
    }
}

int main()
{
    con_init(&conns[0], NULL);

    con_init(&conns[1], NULL);
    ssl_conn_init(&conns[1], NULL);

    puts("\nPERFORM 1\n========\n");
    perform(&conns[0]);
    puts("\nPERFORM 2\n========\n");
    perform(&conns[1]);

    return 0;
}