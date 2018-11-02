#include "stdafx.h"
#include "Server.h"


Server::Server() : stop(false)
{
}


Server::~Server()
{
}


void Server::Start(unsigned int port_no)
{
	thread.reset(new std::thread([this, port_no]()
	{
		Run(port_no);
	}));
}


void Server::Stop()
{
	stop.store(true);
	thread->join();
}


void Server::Run(unsigned int port_no)
{
	Acceptor acc(ios, port_no);

	while (!stop.load())
		acc.Accept();
}
