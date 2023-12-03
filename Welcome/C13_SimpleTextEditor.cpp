#include <cctype>
#include <iostream>
#include "buffer.h"
#include <istream>
#include "simpio.h"
using namespace std;

void executeCommand(EditorBuffer & buffer, string line);

void displayBuffer(EditorBuffer & buffer);

void printHelpText();

int main_C13_buffer(){
    EditorBuffer buffer;
    printHelpText();
    cout << endl << "Here we go" << endl << "________________________________________________" << endl;
    while(true){
        string cmd = getLine("*");
        if(cmd != "") executeCommand(buffer,cmd);
    }
    return 0;
}


void executeCommand(EditorBuffer & buffer, string line){
    switch (toupper(line[0])) {
    case 'I':
        cout << "Insert:" << endl;
        for (int i=1; i< line.size();i++) {
            buffer.insertCharacter(line[i]);
        }
        displayBuffer(buffer);
        break;
    case 'D': buffer.deleteCharacter(); cout << "Delete:" << endl;displayBuffer(buffer); break;
    case 'F': buffer.moveCursorForward(); cout << "Forward:" << endl; displayBuffer(buffer); break;
    case 'B': buffer.moveCursorBackward(); cout << "Backward:" << endl; displayBuffer(buffer); break;
    case 'J': buffer.moveCursorToStart(); cout << "ToStart:" << endl; displayBuffer(buffer); break;
    case 'E': buffer.moveCursorToEnd(); cout << "ToEnd:" << endl; displayBuffer(buffer); break;
    case 'H': buffer.moveCursorToEnd();printHelpText(); break;
    case 'Q': exit(0);

    default:cout << "Illegal command" << endl; break;
    }
}

void displayBuffer(EditorBuffer & buffer){
    string str = buffer.getText();
    for(int i = 0; i < str.length(); i++){
        cout << " " << str[i];
    }
    cout << endl;
    cout << string(2 * buffer.getCursor(), ' ') << "^" << endl;
}

void printHelpText(){
    cout << "Editor commands:" << endl;
    cout << "Iabc Insert character abc at the cursor position" << endl;
    cout << "F    Moves the cursor forward one character" << endl;
    cout << "B    Moves the cursor backward one character" << endl;
    cout << "D    Deletes the character after the cursor" << endl;
    cout << "J    Jumps to the beginning of the buffer" << endl;
    cout << "E    Jumps to the end of the buffer" << endl;
    cout << "H    Prints this message" << endl;
    cout << "Q    Exits form the editor program" << endl;
}
