/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calc.h"


void
calcprog_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	int  add_1_arg;
	int  *result_2;
	int  mul_1_arg;
	void  *result_3;
	int  init_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCPROG, CALCVERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

        init_1_arg = 100;
	result_3 = init_1(&init_1_arg, clnt);
	if (result_3 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
		printf ("init fait: \n");
         
        add_1_arg = 12;
	result_1 = add_1(&add_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf ("result: %d \n", *result_1);
        
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	calcprog_1 (host);
exit (0);
}
