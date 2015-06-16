#include "client.hpp"

Client::Client(const string first_name, const string last_name, const bool gender) : first_name(first_name), last_name(last_name), gender(gender)
{
}

const string Client::get_first_name()
{
    return first_name;
}

const string Client::get_last_name()
{
    return last_name;
}

const bool Client::get_gender()
{
    return gender;
}

const string Client::to_string()
{
    return first_name + " " + last_name;
}
