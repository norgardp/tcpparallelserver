#pragma once
class Service
{
public:
	Service();
	~Service();
	void StartHandlingClient(std::shared_ptr<boost::asio::ip::tcp::socket> sock);
private:
	void HandleClient(std::shared_ptr<boost::asio::ip::tcp::socket> sock);
};

