#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <crow.h>
#include "User.hpp"

typedef struct Message {
    const crow::request& req;
    crow::response& res;
    User& user;
}Message;

#endif