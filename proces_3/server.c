#define WIN32_LEAN_AND_MEAN

#include <stdlib.h>
#include <stdio.h>
#include <xmlrpc-c/base.h>
#include <xmlrpc-c/server.h>
#include <xmlrpc-c/server_abyss.h>


static xmlrpc_value * sample_add(
			xmlrpc_env *   const envP,
			xmlrpc_value * const paramArrayP,
			void *         const serverInfo,
			void *         const channelInfo) {

    char* inputString;
    xmlrpc_decompose_value( envP, paramArrayP, "(s)", &inputString);
    if (envP->fault_occurred)
        return NULL;

    // Przetwarzanie otrzymanego stringa
    printf("Odebrano wiadomosc: %s\n", inputString);

    // Zwolnienie zasobów
    free(inputString);
	// zwrot wyniku
    return xmlrpc_build_value(envP, "i", 0);
}
//======================================================================
int main( void ){
	
	int  port   = 1234;
    struct xmlrpc_method_info3 const methodInfo = {
        /* .methodName     = */ "sample.add",
        /* .methodFunction = */ &sample_add,
    };
    
    xmlrpc_server_abyss_parms serverparm;
    xmlrpc_registry * registryP;
    xmlrpc_env env;

    // inicializacja serwera
    xmlrpc_env_init(&env);

	//rejestracja zmiennych
    registryP = xmlrpc_registry_new(&env);
    if (env.fault_occurred){
        printf( "xmlrpc_registry_new(): %s\n", env.fault_string);
        exit(1);
    }

	// rejestracja metod
    xmlrpc_registry_add_method3( &env, registryP, &methodInfo );
    if (env.fault_occurred) {
        printf( "xmlrpc_registry_add_method3(): %s\n", env.fault_string );
        exit(1);
    }

	// ustawienie parametrow serwera
    serverparm.config_file_name = NULL;
    serverparm.registryP        = registryP;
    serverparm.port_number      = port;
    serverparm.log_file_name    = "/tmp/xmlrpc_log";

	// uruchomienie serwerwa
    xmlrpc_server_abyss(&env, &serverparm, XMLRPC_APSIZE(log_file_name));
    if( env.fault_occurred ){
        printf("xmlrpc_server_abyss(): %s\n", env.fault_string);
        exit(1);
    }

    return 0;
}