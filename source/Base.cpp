#include "Base.hpp"

Base::Base(int x, int y) : m_x(x), m_y(y) {}

int Base::getX() const { return m_x; }
int Base::getY() const { return m_y; }

void Base::setX(int x) { m_x = x; }
void Base::setY(int y) { m_y = y; }
