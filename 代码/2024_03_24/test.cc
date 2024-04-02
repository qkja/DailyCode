#include <iostream>

class X
{
    friend std::istream& operator>>(std::istream&, X&);
    public:
    X(int sz = 1024)
    {
        ptr = new char[sz];
    } 
    private:
    char* ptr;
};


X buf;

int main()
{
    std::cin >> setw(1024) >> buf;
    return 0;
}