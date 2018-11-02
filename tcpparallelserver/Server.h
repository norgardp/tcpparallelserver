#pragma once

#include "Acceptor.h"

class Server
{
public:
	Server();
	~Server();
private:
	std::unique_ptr<std::thread> thread;
	std::atomic<bool> stop;
	boost::asio::io_service ios;
public:
	void Start(unsigned int port_no);
	void Stop();
private:
	void Run(unsigned int port_no);
};

