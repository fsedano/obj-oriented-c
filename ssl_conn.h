#ifndef __SSL_CONN_H
#define __SSL_CONN_H

#include "conn.h"

typedef struct ssl_conn ssl_conn_t;


struct ssl_conn {
    conn_t super;
    struct ssl_conn_impl *impl;

    void (*ssl_method)(ssl_conn_t *this, int x);
};

int ssl_conn_init(conn_t *con, void *ctx);

#endif