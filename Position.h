#ifndef POSITION_H
#define POSITION_H


class Position
{
    public:
        Position(int pos_x, int pos_y);
        int pos_x, pos_y;
        virtual ~Position();
    protected:
    private:
};

#endif // POSITION_H
