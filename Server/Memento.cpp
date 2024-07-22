#include "Memento.h"

Memento::Memento(const QByteArray &state) : state(state) {}

QByteArray Memento::getState() const
{
    return state;
}
