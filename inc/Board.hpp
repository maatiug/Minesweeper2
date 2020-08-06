#pragma once

#include "Vector2D.hpp"
#include "Field.hpp"
#include "Const.hpp"

/**
 * \brief Board of game
 *
 * TODO:
 *  todo: tworzenie mapy, losowanie pozycji min
 *  todo: wykonywanie ruchu
 *  todo:
 */
class Board {
private:
    Vector2D size {0,0};        //< Size od board
    Field** board {NULL};       //< Array of fields on the board. Coordinates: Board[ x ][ y ]
    short unsigned int mines;   //< Number of mines.

public:
    /**
     * \brief Construct a new Board object
     */
    Board() = default;

    /**
     * \brief Destroy the Board object
     */
    ~Board();

public:
    /**
     * \brief Set values on the board
     * \param w - width
     * \param h - height
     * \param m - number of minse
     * \post Modifly `size` and `mines`
     */
    void set( unsigned int w, unsigned int h, unsigned int m );

    /**
     * \brief Uncover the choosen field
     * \param pos - position of the field
     */
    void uncover( const Vector2D& pos );

    /**
     * \brief Set a flag on the field.
     * \param pos -
     */
    inline void flag( const Vector2D& pos )
    { (*this)(pos).flag(); }


    /**
     * \brief Display debug.
     */
    void debug() const;

public:
    /**
     * \brief Width of board
     * \return unsigned int -
     */
    inline int w() const
    { return this->size.x; }

    /**
     * \brief Height of board
     * \return unsigned int -
     */
    inline int h() const
    { return this->size.y; }

    /**
     * \brief Is array created?
     * \return true - yes
     * \return false - no
     */
    inline bool created() const
    { return this->board != NULL; }

public:
    /**
     * \brief Value of field. Without checking a correct of position!
     * \param vec -
     * \return Field& -
     */
    inline const Field& operator () ( const Vector2D& vec ) const
    { return board[ vec.x ][ vec.y ]; }

private:
    /**
     * \brief Value of field. Without checking a correct of position!
     * \param vec -
     * \return Field& -
     */
    inline Field& operator () ( const Vector2D& vec )
    { return board[ vec.y ][ vec.x ]; }

private:
    /**
     * \brief Create a array of board.
     * Default value of field is: empty, covered.
     * \post Modify only `board`.
     * \param size_ - Vector2D of new boards sizes.
     */
    void alloc();

    /**
     * \brief Free memory if board array exist.
     */
    void free();

    /**
     * \brief Rand mines position on the board.
     * \exception
     *  - Too much mines!
     *      Maximum number of mines is area of board - 9 (first click is on the empty field!)
     *  - Too least mines!
     *      Minumum number of mines is const in Const.hpp.
     * \param num_mines -
     */
    void randMines( const Vector2D& click );

};