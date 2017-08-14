#include <WinSock2.h>
#include <Iphlpapi.h>
#include <iostream>
using namespace std;
#pragma comment(lib,"Iphlpapi.lib") //��Ҫ���Iphlpapi.lib��

//#include <boost/algorithm/string.hpp>
//bool isNetworkCardExistent(const std::string& vName)
//{
//	IP_ADAPTER_INFO* pIPAdapterInfo = new IP_ADAPTER_INFO;
//	unsigned long AdapterSize = sizeof(IP_ADAPTER_INFO);
//	int QueryResult = GetAdaptersInfo(pIPAdapterInfo, &AdapterSize);
//
//	if (QueryResult == ERROR_BUFFER_OVERFLOW)
//	{ 
//		delete pIPAdapterInfo;
//		pIPAdapterInfo = reinterpret_cast<IP_ADAPTER_INFO*>(new BYTE[AdapterSize]);
//		QueryResult = GetAdaptersInfo(pIPAdapterInfo, &AdapterSize);
//	}
//	if (QueryResult == ERROR_SUCCESS)
//	{
//		std::string NetworkCardDescription;
//		while (pIPAdapterInfo)
//		{
//			NetworkCardDescription = pIPAdapterInfo->Description;
//			NetworkCardDescription = boost::to_upper_copy(NetworkCardDescription);
//			if (boost::istarts_with(NetworkCardDescription, boost::to_upper_copy(vName))) return true;
//			pIPAdapterInfo = pIPAdapterInfo->Next;
//		}
//	}
//
//	if (pIPAdapterInfo)
//	{
//		delete[] pIPAdapterInfo;
//	}
//
//	return false;
//}

int main(int argc, char* argv[])
{
	//PIP_ADAPTER_INFO�ṹ��ָ��洢����������Ϣ
	PIP_ADAPTER_INFO pIpAdapterInfo = new IP_ADAPTER_INFO();
	
	//�õ��ṹ���С,����GetAdaptersInfo����
	unsigned long stSize = sizeof(IP_ADAPTER_INFO);
	
	//����GetAdaptersInfo����,���pIpAdapterInfoָ�����;����stSize��������һ��������Ҳ��һ�������
	int nRel = GetAdaptersInfo(pIpAdapterInfo,&stSize);

	//��¼��������
	int netCardNum = 0;
	//��¼ÿ�������ϵ�IP��ַ����
	int IPnumPerNetCard = 0;

	if (ERROR_BUFFER_OVERFLOW == nRel)
	{
		//����������ص���ERROR_BUFFER_OVERFLOW
		//��˵��GetAdaptersInfo�������ݵ��ڴ�ռ䲻��,ͬʱ�䴫��stSize,��ʾ��Ҫ�Ŀռ��С
		//��Ҳ��˵��ΪʲôstSize����һ��������Ҳ��һ�������
		//�ͷ�ԭ�����ڴ�ռ�
		delete pIpAdapterInfo;
		
		//���������ڴ�ռ������洢����������Ϣ
		pIpAdapterInfo = (PIP_ADAPTER_INFO)new BYTE[stSize];
		//�ٴε���GetAdaptersInfo����,���pIpAdapterInfoָ�����
		nRel=GetAdaptersInfo(pIpAdapterInfo,&stSize);  
	}
	if (ERROR_SUCCESS == nRel)
	{
		//���������Ϣ
		//�����ж�����,���ͨ��ѭ��ȥ�ж�
		while (pIpAdapterInfo)
		{
			cout<<"����������"<<++netCardNum<<endl;
			cout<<"�������ƣ�"<<pIpAdapterInfo->AdapterName<<endl;
			cout<<"����������"<<pIpAdapterInfo->Description<<endl;
			switch(pIpAdapterInfo->Type)
			{
			case MIB_IF_TYPE_OTHER:
				cout<<"�������ͣ�"<<"OTHER"<<endl;
				break;
			case MIB_IF_TYPE_ETHERNET:
				cout<<"�������ͣ�"<<"ETHERNET"<<endl;
				break;
			case MIB_IF_TYPE_TOKENRING:
				cout<<"�������ͣ�"<<"TOKENRING"<<endl;
				break;
			case MIB_IF_TYPE_FDDI:
				cout<<"�������ͣ�"<<"FDDI"<<endl;
				break;
			case MIB_IF_TYPE_PPP:
				printf("PP\n");
				cout<<"�������ͣ�"<<"PPP"<<endl;
				break;
			case MIB_IF_TYPE_LOOPBACK:
				cout<<"�������ͣ�"<<"LOOPBACK"<<endl;
				break;
			case MIB_IF_TYPE_SLIP:
				cout<<"�������ͣ�"<<"SLIP"<<endl;
				break;
			default:

				break;
			}
			cout<<"����MAC��ַ��";
			for (DWORD i = 0; i < pIpAdapterInfo->AddressLength; i++)
				if (i < pIpAdapterInfo->AddressLength-1)
				{
					printf("%02X-", pIpAdapterInfo->Address[i]);
				}
				else
				{
					printf("%02X\n", pIpAdapterInfo->Address[i]);
				}
				cout<<"����IP��ַ���£�"<<endl;
				//���������ж�IP,���ͨ��ѭ��ȥ�ж�
				IP_ADDR_STRING *pIpAddrString =&(pIpAdapterInfo->IpAddressList);
				do 
				{
					cout<<"�������ϵ�IP������"<<++IPnumPerNetCard<<endl;
					cout<<"IP ��ַ��"<<pIpAddrString->IpAddress.String<<endl;
					cout<<"������ַ��"<<pIpAddrString->IpMask.String<<endl;
					cout<<"���ص�ַ��"<<pIpAdapterInfo->GatewayList.IpAddress.String<<endl;
					pIpAddrString=pIpAddrString->Next;
				} while (pIpAddrString);
				pIpAdapterInfo = pIpAdapterInfo->Next;
				cout<<"--------------------------------------------------------------------"<<endl;
		}

	}
	//�ͷ��ڴ�ռ�
	if (pIpAdapterInfo)
	{
		delete pIpAdapterInfo;
	}

	//isNetworkCardExistent("Mellanox");

	system("pause");

	return 0;
}
