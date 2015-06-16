#ifndef PRODUCT_H
#define PRODUCT_H


class Product
{
    public:
        Product();
        virtual ~Product();
        Product(const Product& other);
        Product& operator=(const Product& other);
    protected:
    private:
};

#endif // PRODUCT_H
