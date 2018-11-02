#include "stdafx.h"
#include "Service.h"


Service::Service()
{
}


Service::~Service()
{
}


void Service::StartHandlingClient(std::shared_ptr<boost::asio::ip::tcp::socket> sock)
{
	std::thread thd(([this, sock]()
	{
		HandleClient(sock);
	}));

	thd.detach();
}


void Service::HandleClient(std::shared_ptr<boost::asio::ip::tcp::socket> sock)
{
	try {
		boost::asio::streambuf request;
		boost::asio::read_until(*sock.get(), request, '\n');

		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		std::string response{ "Response\n" };
		boost::asio::write(*sock.get(), boost::asio::buffer(response));
	}
	catch (std::system_error& e)
	{
		std::cout << "Error " << e.code() << " occurred." << std::endl;
		std::cout << "Error Message: " << e.what() << std::endl;
	}

	delete this;
}
