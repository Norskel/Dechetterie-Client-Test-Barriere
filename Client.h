#pragma once
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;
using namespace System::Text;

delegate void DelegateReceiveMessage(array<unsigned char, 1>^);

ref class Client
{
private:
	Boolean _isConnected = false;
	Socket^ _clSocket;
	IPAddress^ ipServeur;
	int portServeur;
	Thread^ waitMessage;
public:

	event DelegateReceiveMessage^ ReceiveMessage;

	Client()
	{
		TcpClient^ tcl = gcnew TcpClient();
		_clSocket = tcl->Client;
		waitMessage = gcnew Thread(gcnew ThreadStart(this, &Client::Receive));
	}
	Boolean Connect(IPAddress^ ip, int port)
	{
		//Console::WriteLine(port);
		this->ipServeur = ip;
		this->portServeur = port;
		
		return this->Connect();
	}
	Boolean Connect()
	{
		try
		{
			_clSocket->Connect(ipServeur, portServeur);
			_isConnected = true;

			return true;
		}
		catch (...)
		{
			_isConnected = false;
			return false;
		}
	}

	Boolean Send(array<Byte>^ data)
	{
		try
		{
			_clSocket->Send(data);
			return true;
		}
		catch (...)
		{
			return false;
		}
	}

	void Receive()
	{
		while (true)
		{
			array<Byte>^ data = gcnew array<Byte>(255);
			try
			{
				_clSocket->Receive(data);
				ReceiveMessage( data);
			}
			catch (...)
			{

			}
		}
	}

	Socket^ getSocket()
	{
		return _clSocket;
	}
};

