#ifndef _ILLEGALBALANCEEXCEPTION_H_
#define _ILLEGALBALANCEEXCEPTION_H_

class IllegalBalanceException : public std::exception
{
public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException() = default;
    virtual const char* what() const noexcept
    {
        return "Illegal balance exceptions";
    }
};

#endif // _ILLEGALBALANCEEXCEPTION_H_
