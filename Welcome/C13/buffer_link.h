#ifndef BUFFER_LINK_H
#define BUFFER_LINK_H

using namespace std;
#include <string>
#include "charstack.h"
class EditorBuffer_Link
{
public:
    /*
    * Constructor: EditorBuffer
    * Usage: EditorBuffer buffer:
    * Create an empty editor buffer.
    */
    EditorBuffer_Link();

    /*
    * Destructor : ~EditorBuffer
    * Usage: usually implicit
    * Frees any heap storage associated with this buffer
    */
    ~EditorBuffer_Link();

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
    CharStack before;
    CharStack after;

    /* Make it illegal to copy editor buffers */
    EditorBuffer_Link(const EditorBuffer_Link & value) {}
    const EditorBuffer_Link & operator = (const EditorBuffer_Link & rhs) { return * this;}
};
#endif // BUFFER_LINK_H
