#ifndef MEMENTO_H
#define MEMENTO_H

#include <QByteArray>

class Memento
{
public:
    // Constructor that creates a Memento with the given state.
    explicit Memento(const QByteArray &state);

    // Gets the state of the Memento.
    // Returns a QByteArray containing the state.
    QByteArray getState() const;

private:
    // State stored in the Memento.
    QByteArray state;
};

#endif // MEMENTO_H
