#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:
        Board();
        virtual ~Board();
        void setUpBoard();
        void setPieceInColumn(int player, int column);
        void setRandomPiece(int player);
        void takeTopPieceFromColumn(int column);
        bool checkHorizontal();
        bool checkVertical();
        bool checkDiagonalGoingUp();
        bool checkDiagonalGoingDown();
        void clearBoard();
        void printBoard();
    protected:
    private:
        int connectBoard[7][7];
};

#endif // BOARD_H
