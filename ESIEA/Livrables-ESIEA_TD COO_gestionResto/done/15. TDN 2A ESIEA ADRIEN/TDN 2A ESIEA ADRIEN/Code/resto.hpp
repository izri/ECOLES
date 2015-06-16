#ifndef PRINTABLE_H
#define PRINTABLE_H


class Printable
{
    public:
        Printable();
        virtual ~Printable();
        Printable(const Printable& other);
        Printable& operator=(const Printable& other);
    protected:
    private:
};

#endif // PRINTABLE_H
