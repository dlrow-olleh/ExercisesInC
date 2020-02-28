#include "util.h"

typedef struct rec {                /* outgoing UDP data */
  u_short seq;          /* sequence number */
} Rec;

#define max(a,b) ((a) > (b) ? (a) : (b))

Sockaddr *sasend;    /* socket addresses for various purposes */
Sockaddr *sarecv;
Sockaddr *salast;
Sockaddr *sabind;
int datalen;
socklen_t salen;
int max_ttl;

/* the following are prototypes for the Stevens utilities in util.c */

void sig_alrm (int signo);
int process_ip (struct ip *ip, int len);
int recv_dgram ();
void sub_tv (Timeval *plus, Timeval *minus, Timeval *res);
double time_to_double (Timeval *time);
void print_report ();
void send_dgram (int ttl);
int send_probes (int ttl);
void loop_ttl ();
