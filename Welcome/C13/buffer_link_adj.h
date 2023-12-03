#ifndef BUFFER_LINK_ADJ_H
#define BUFFER_LINK_ADJ_H
#include <string>
class EditorBuffer_Link_Adj
{
public:
    /*
    * Constructor: EditorBuffer
    * Usage: EditorBuffer buffer:
    * Create an empty editor buffer.
    */
    EditorBuffer_Link_Adj();

    /*
    * Destructor : ~EditorBuffer
    * Usage: usually implicit
    * Frees any heap storage associated with this buffer
    */
    ~EditorBuffer_Link_Adj();

    /*Methods: moveCursorForward, moveCursorBackward;
     *Usage: buffer.moveCursorForward();
     *       buffer.moveCursorBackward();
     *
     */
    void moveCursorForward();
    void moveCursorBackward();

    /*
     * Methods: moveCursorToStart, moveCursorToEnd
     * Usage: buffer.moveCursorToStart();
     *        buffer.moveCursorToEnd();
    */
    void moveCursorToStart();
    void moveCursorToEnd();

    /*
     *Method: insertCharacter
     *Usage:  buffer.insertCharacter(ch);
    */
    void insertCharacter(char ch);

    /*
     *Method: deleteCharacter
     *Usage:  buffer.deleteCharacter();
    */
    void deleteCharacter();

    /*
     *Method: getText
     *Usage:  string str = buffer.getText();
    */
    std:: string getText() const;

    /*
     *Method: getCursor
     *Usage:  int cursor = buffer.getCursor();
    */
    int getCursor();

    /* Private section */
private:
    struct Cell {
        char ch;
        Cell *link;
    };

    /* Instance variables */
    Cell *start;
    Cell *cursor;


    /* Make it illegal to copy editor buffers */
    EditorBuffer_Link_Adj(const EditorBuffer_Link_Adj & value) {}
    const EditorBuffer_Link_Adj & operator = (const EditorBuffer_Link_Adj & rhs) { return * this;}
};

#endif // BUFFER_LINK_ADJ_H
