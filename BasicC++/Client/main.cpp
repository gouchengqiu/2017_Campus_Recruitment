////Client端源代码: 
//#include <stdio.h> 
//#include <Winsock2.h> 
//void main() 
//{ 
//	SOCKET socket1; 
//	//InitWinsock(); 
//	WSADATA wsaData; 
//	int iErrorCode; 
//	if (WSAStartup(MAKEWORD(2,1),&wsaData)) //调用Windows Sockets DLL 
//	{ 
//		printf("Winsock无法初始化!\n"); 
//		WSACleanup(); 
//		return; 
//	} 
//	printf("服务器开始创建SOCKET。\n"); 
//	struct sockaddr_in server; 
//	int len =sizeof(server); 
//	server.sin_family=AF_INET; 
//	server.sin_port=htons(8000); ///server的监听端口 
//	server.sin_addr.s_addr=inet_addr("192.168.18.132"); ///server的地址 
//	socket1=socket(AF_INET,SOCK_DGRAM,0); 
//	while (1) 
//	{ 
//		char buffer[1024]="\0"; 
//		printf("input message\n"); 
//		scanf("%s",buffer); 
//		//     printf("%s",buffer); 
//		if (strcmp(buffer,"bye")==0) 
//		{ 
//			printf("退出!\n"); 
//			Sleep(100); 
//			closesocket(socket1); 
//			break; 
//		} 
//		if (sendto(socket1,buffer,sizeof(buffer),0,(struct sockaddr*)&server,len)!=SOCKET_ERROR) 
//		{ 
//			//printf("sending..\n"); 
//			Sleep(100); 
//			if (recvfrom(socket1,buffer,sizeof(buffer),0,(struct sockaddr*)&server,&len) != SOCKET_ERROR) 
//				printf("rece from server:%s\n",buffer); 
//		} 
//	} 
//	closesocket(socket1);
//	WSACleanup();   
//}
//UDP client  
//client send string to server  

//Visual C++ 6.0  

#include <stdio.h>  
#include <winsock2.h>  

#pragma comment(lib,"ws2_32.lib")  

#define BUFLEN 1024  

int main(void)  
{  
	SOCKET soc;  
	SOCKADDR_IN addr;  
	unsigned char buf[BUFLEN];  

	WSADATA wsa;  
	WSAStartup(MAKEWORD(2,2),&wsa); //initial Ws2_32.dll by a process  

	memset(&addr, 0, sizeof(addr));  


	if((soc = socket(AF_INET,SOCK_DGRAM,0)) <= 0)  
	{  
		printf("Create socket fail!\n");  
		return -1;  
	}  

	addr.sin_family = AF_INET;  
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");  
	addr.sin_port = htons(8000);  
	bind(soc,(struct sockaddr *)&addr,sizeof(addr));  


	while(1) {  
		scanf("%s", buf);  
		sendto(soc, (const char*)buf, strlen((const char*)buf)+1, 0, (struct sockaddr *)&addr, sizeof(addr));  
	}  

	WSACleanup();   //clean up Ws2_32.dll  
	return 0;  
}