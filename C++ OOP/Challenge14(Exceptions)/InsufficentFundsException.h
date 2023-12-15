#ifndef _INSUFFICENTFUNDSEXCEPTION_H_
#define _INSUFFICENTFUNDSEXCEPTION_H_

class InsufficentFundsException : public std::exception
{
public:
    InsufficentFundsException() noexcept = default;
    ~InsufficentFundsException() = default;
    virtual const char* what() const noexcept
    {
        return "Insufficent Funds Exception";
    }

};

#endif // _INSUFFICENTFUNDSEXCEPTION_H_
