/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-04-26 22:50:56
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-04-26 22:52:20
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include<iostream>
#include <WinSock2.h>
#pragma comment(lib,"Ws2_32.lib ")
void socketTest(unsigned short usPort)
{
	/**/WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(1,1);//2,2
	err = WSAStartup(wVersionRequested, &wsaData);

	SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	addr.sin_port = htons(usPort);
	bind(s, (LPSOCKADDR)&addr, sizeof(addr));
	if (WSAGetLastError() == WSAEADDRINUSE)
	{
		std::cout << usPort << ":\tUsed" << std::endl;
	}
	else
	{
		closesocket(s);
		std::cout << usPort << ":\t\tUnused" << std::endl;
	}

}
