#ifndef REST_SERVER_H
#define REST_SERVER_H

#include <cpprest/asyncrt_utils.h>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <cpprest/uri.h>

using namespace utility;

class RestServer{
    public:
    RestServer();
    ~RestServer();
    void initialize(const string_t &address);

    private:
    web::http::experimental::listener::http_listener m_listener;


    pplx::task<void> open();
    pplx::task<void> close();
    void handleGetRequests(web::http::http_request message);
    void handlePostRequests(web::http::http_request message);

};


#endif