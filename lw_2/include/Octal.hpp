#pragma once 
#include <initializer_list>
#include <iostream>
class Octal{
    private:
        size_t size = 0;
        unsigned char *data;
    public:
        Octal();
        ~Octal();
        Octal(const Octal &given);
        Octal(const std::initializer_list<unsigned char > &init);
        explicit Octal(const std::string &x);
        Octal(Octal&& given) noexcept;
        void setting_the_size();

        bool operator>(const Octal &given) const;
        bool operator<(const Octal &given) const;
        bool operator==(const Octal &ex);
        bool operator!=(const Octal &ex);

        Octal& operator+=(const Octal &given);
        Octal operator+(const Octal& given) const;
        Octal& operator=(const Octal &given);
        Octal& operator-=(const Octal &given);
        Octal operator-(const Octal&given) const;

        friend std::ostream& operator<<(std::ostream &out, const Octal &ex);

}; 