#pragma once

#include "Service.h"

class Acceptor
{
public:
	~Acceptor();
	Acceptor(boost::asio::io_service& ios, unsigned int port_no);
	void Accept();

private:
	boost::asio::io_service& ios;
	boost::asio::ip::tcp::acceptor acceptor;	
};

