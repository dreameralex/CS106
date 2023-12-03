#ifndef BUFFER_H
#define BUFFER_H
using namespace std;
#include <string>
class EditorBuffer
{
public:
    /*
    * Constructor: EditorBuffer
    * Usage: EditorBuffer buffer:
    * Create an empty editor buffer.
    */
    EditorBuffer();

    /*
    * Destructor : ~EditorBuffer
    * Usage: usually implicit
    * Frees any heap storage associated with this buffer
    */
    ~EditorBuffer();

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
    int getCursor()const;

    /* Private section */
private:
    static const int INITIAL_CAPACITY = 10;

    /* Instace variables */
    char *array;
    int capacity;
    int length;
    int cursor;

    /* Make it illegal to copy editor buffers */
    EditorBuffer(const EditorBuffer & value) {}
    const EditorBuffer & operator=(const EditorBuffer & rhs) { return *this; }

    /* Private method prototype */
    void expandCapacity();
};

#endif // BUFFER_H
