#ifndef CLIENT_H
#define CLIENT_H


class Client
{
    public:
        Client();
        virtual ~Client();
        Client(const Client& other);
        Client& operator=(const Client& other);
    protected:
    private:
};

#endif // CLIENT_H
