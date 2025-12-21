#pragma once

class Base
{
private:
    int m_x, m_y;

public:
    Base(int x, int y);

    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);
};
