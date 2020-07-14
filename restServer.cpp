#include "restServer.h"

RestServer::RestServer() : m_listener(_XPLATSTR("http://localhost:5000")){
  m_listener.support(web::http::methods::GET,
                     std::bind(&RestServer::handleGetRequests, this, std::placeholders::_1));
  m_listener.support(web::http::methods::POST,
                     std::bind(&RestServer::handlePostRequests, this, std::placeholders::_1));
  //initialize(m_listener.uri().to_string());
}

RestServer::~RestServer(){
    close();
}

void RestServer::initialize(const string_t &address) {
  std::cout << "Rest web server listening for requests at: " << address << std::endl;
  web::http::uri_builder uri(address);
  auto addr = uri.to_uri().to_string();
  open().wait();
}

pplx::task<void> RestServer::open() {
  return m_listener.open();
}

pplx::task<void> RestServer::close() {
  return m_listener.close();
}

void RestServer::handleGetRequests(web::http::http_request message) {

  if (message.relative_uri().path() == _XPLATSTR("/")) {
    return;
  }

  if (message.relative_uri().path() == _XPLATSTR("/map")) {
    return;
  }

  std::cout << "Requested path and method not implemented, " << message.method() << ": " << message.relative_uri().path() << std::endl;
  message.reply(web::http::status_codes::NotFound);
}

void RestServer::handlePostRequests(web::http::http_request message) {
  if (message.relative_uri().path() == _XPLATSTR("/map")) {
    return;
  }
  
  std::cout << "Requested path and method not implemented, " << message.method() << ": " << message.relative_uri().path() << std::endl;
  message.reply(web::http::status_codes::NotFound);
}