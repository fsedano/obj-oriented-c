#ifndef __CONN_H
#define __CONN_H

typedef struct conn conn_t;


typedef int (*con_func)(conn_t *this, void *ctx);

struct conn {
    struct conn_impl *impl;
    con_func read;
    con_func write;
    int type;
};

int con_init(conn_t *con, void *ctx);

#endif