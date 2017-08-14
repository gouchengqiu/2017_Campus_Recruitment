////Server 端程序源代码: 
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
//	struct sockaddr_in local; 
//	struct sockaddr_in from; 
//	int fromlen =sizeof(from); 
//	local.sin_family=AF_INET; 
//	local.sin_port=htons(8000); ///监听端口 
//	local.sin_addr.s_addr=INADDR_ANY; ///本机 
//	socket1=socket(AF_INET,SOCK_DGRAM,0); 
//	bind(socket1,(struct sockaddr*)&local,sizeof(local)); 
//	while (1) 
//	{ 
//		char buffer[1024]="\0"; 
//		printf("waiting for message from others-------------\n"); 
//		if (recvfrom(socket1,buffer,sizeof(buffer),0,(struct sockaddr*)&from,&fromlen)!=SOCKET_ERROR) 
//		{ 
//			printf("Received datagram from %s--%s\n",inet_ntoa(from.sin_addr),buffer); 
//			////给cilent发信息 
//			sendto(socket1,buffer,sizeof(buffer),0,(struct sockaddr*)&from,fromlen); 
//		} 
//		//Sleep(1000); 
//	} 
//	closesocket(socket1);
//	WSACleanup();    
//} 

//UDP server  
//listen port 9102  
//receive string and display it  

//Visual C++ 6.0  

#include <stdio.h>  
#include <winsock2.h>  

#pragma comment(lib,"ws2_32.lib")  

#define BUFLEN 1024  

int main(void)  
{  
	SOCKET soc;  
	SOCKADDR_IN addr;  
	char buf[BUFLEN];  
	int len;  

	WSADATA wsa;  
	WSAStartup(MAKEWORD(1,1),&wsa); //initial Ws2_32.dll by a process  

	memset(&addr, 0, sizeof(addr));  

	if((soc = socket(AF_INET,SOCK_DGRAM,0)) <= 0)  
	{  
		printf("Create socket fail!\n");  
		return -1;  
	}  


	addr.sin_family = AF_INET;  
	addr.sin_port = htons(8000);  
	addr.sin_addr.s_addr = htonl(INADDR_ANY);  

	if(bind(soc,(struct sockaddr *)&addr,sizeof(struct sockaddr))!=0)  
	{  
		printf("Bind fail!\n");  
		return -1;  
	}  


	len = sizeof(addr);  
	printf("start listen...\n");  
	while(1) {  
		recvfrom(soc, buf, BUFLEN, 0,(struct sockaddr*)&addr, &len);  
		printf("%s\n",buf);  
	}  

	WSACleanup();                     //关闭  
	return 0;  
}