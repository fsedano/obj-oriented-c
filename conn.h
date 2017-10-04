#ifndef __CONN_H
#define __CONN_H

typedef struct conn conn_t;

struct conn {
    struct conn_impl *impl;
    int (*read)(void *ctx);
    int type;
};

int con_init(conn_t *con, void *ctx);

#endif