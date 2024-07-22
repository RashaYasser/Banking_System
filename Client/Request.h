#ifndef REQUEST_H
#define REQUEST_H

#include <QJsonObject>
#include <QString>

// Abstract base class for all requests
class Request
{
public:
    // Pure virtual function to serialize request data to JSON
    virtual QJsonObject toJson() const = 0;
    virtual ~Request() = default;
};

#endif // REQUEST_H
