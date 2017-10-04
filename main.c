#include <stdio.h>
#include "conn.h"
#include "ssl_conn.h"


conn_t conns[2];

int main()
{
    con_init(&conns[0], NULL);

    //conns[0].read(NULL);

    con_init(&conns[1], NULL);
    ssl_conn_init(&conns[1], NULL);

    conns[0].read(NULL);
    conns[1].read(NULL);
    return 0;
}