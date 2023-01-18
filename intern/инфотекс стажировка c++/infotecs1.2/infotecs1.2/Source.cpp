
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>

#pragma warning(disable: 4996)

int main() {
	//WSAStartup
	while (true) {
		WSAData wsaData;
		

		WORD DLLVersion = MAKEWORD(2, 1);
		if (WSAStartup(DLLVersion, &wsaData) != 0) {
			std::cout << "Error" << std::endl;
			exit(1);
		}

		SOCKADDR_IN addr;
		int sizeofaddr = sizeof(addr);
		addr.sin_addr.s_addr = inet_addr("127.0.0.1");
		addr.sin_port = htons(1111);
		addr.sin_family = AF_INET;

		SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
		bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
		listen(sListen, SOMAXCONN);

		SOCKET newConnection;
		int result;
		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
	
		int i = 0;
		int j = 0;
		
		if (newConnection == 0) {
			std::cout << "Error #2\n";
		}
		else {
			std::cout << "Client Connected!\n";
			
			while (true) {
				char msg[255];
				result=recv(newConnection, msg, sizeof(msg), NULL);
				if (result == -1) {
					closesocket(newConnection);
					closesocket(sListen);
					break;
				}
				while (msg[i] != -52) {

					i++;
				}
				if ((i > 2) && (i % 32 == 0)) {
					std::cout << "Success! Data Downloaded\n";
				}
				else {
					std::cout << "Error!\n";
				}
				
				i = 0;
			}
		}
	}

	system("pause");
	return 0;
}