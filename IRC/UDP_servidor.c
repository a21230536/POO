/* Servidor basico UDP
   Destina-se a mostrar os conteudos dos datagramas recebidos.
   O porto de escuta encontra-se definido pela constante SERV_UDP_PORT.
   Assume-se que as mensagens recebida sao cadeias de caracteres (ou seja, 
   "strings"). */
#include <stdio.h>
#include <winsock.h>

#pragma comment(lib, "ws2_32.lib")

#define SERV_UDP_PORT 5432
#define BUFFERSIZE 4096

void Abort(char *msg);

int main( int argc , char *argv[] ){
	SOCKET sockfd;
	int iResult, nbytes, sLen = sizeof(struct sockaddr_in);
	struct sockaddr_in serv_addr, cli_addr;
	char buffer[BUFFERSIZE];
	WSADATA wsaData;

	system("cls");

	/* INICIA OS WINSOCKS */
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		getchar();
		exit(1);
	}

	/* CRIA O SOCKET PARA RECEPCAO/ENVIO DE DATAGRAMAS UDP */
	if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET){
		Abort("Impossibilidade de abrir socket");
	}

	/* ASSOCIA O SOCKET AO  ENDERECO DE ESCUTA
	   Define que pretende receber datagramas vindos de qualquer interface de
	   rede, no porto pretendido */
	memset( (char*)&serv_addr , 0, sizeof(serv_addr) );
	serv_addr.sin_family = AF_INET; /* Address Family: Internet */
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  /* Host TO Network Long */
	serv_addr.sin_port = htons(SERV_UDP_PORT);  /* Host TO Network Short */

	/* Associa o socket ao porto pretendido */
	if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
		Abort("Impossibilidade de registar-se para escuta");
	}

	/* PASSA A ATENDER CLIENTES INTERACTIVAMENTE */
	while(1){
		fprintf(stderr,"<SER1> Esperando datagram...\n");

		nbytes = recvfrom(sockfd , buffer , sizeof(buffer) , 0 , (struct sockaddr*)& cli_addr, &sLen);
		
		/* Envia a mensagem (de volta) ao cliente */
		sendto(sockfd, buffer, nbytes, 0, (struct sockaddr*)&cli_addr, sLen);

		if (nbytes == SOCKET_ERROR) {
			Abort("Erro na recepcao de datagrams");
		}
			
		buffer[nbytes]='\0'; /* Termina a cadeia de caracteres recebidos com '\0' */
		
		/* Mostra a mensagem recebida */
		printf("<SER1> Mensagem recebida {%s}\n\n", buffer);
	}
}

/* Abort
 * Mostra uma mensagem de erro e o código associado ao ultimo erro com Winsocks. 
 * Termina a aplicacao com "exit status" a 1 (constante EXIT_FAILURE)
 */
void Abort(char *msg) {
	fprintf(stderr, "<CLI1> Erro fatal: <%s> (%d)\n", msg, WSAGetLastError());
	exit(EXIT_FAILURE);
}
