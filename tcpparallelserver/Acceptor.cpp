#include "stdafx.h"
#include "Acceptor.h"


Acceptor::~Acceptor()
{
}


Acceptor::Acceptor(boost::asio::io_service& ios, unsigned int port_no) :
	ios(ios), acceptor(ios, boost::asio::ip::tcp::endpoint(boost::asio::ip::address_v4::any(), port_no))
{
	acceptor.listen();
}


void Acceptor::Accept()
{
	std::shared_ptr<boost::asio::ip::tcp::socket> sock(new boost::asio::ip::tcp::socket(ios));
	acceptor.accept(*sock.get());
	(new Service)->StartHandlingClient(sock);
}
