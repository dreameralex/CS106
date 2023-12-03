#include "buffer_link_adj.h"
#include <iostream>
using namespace std;

EditorBuffer_Link_Adj::EditorBuffer_Link_Adj(){
    start = cursor = new Cell;
    start -> link = NULL;
}

EditorBuffer_Link_Adj::~EditorBuffer_Link_Adj(){
    Cell *cp = start;
    while(cp != NULL){
        Cell *next = cp->link;
        delete cp;
        cp = next;
    }
}



void EditorBuffer_Link_Adj::moveCursorForward(){
    if(cursor->link != NULL){
        cursor = cursor->link;
    }
}

void EditorBuffer_Link_Adj::moveCursorBackward(){
    Cell *cp = start;
    if (cursor != start){
        while (cp->link != cursor){
            cp = cp->link;
        }
        cursor = cp;
    }
}

void EditorBuffer_Link_Adj::moveCursorToStart(){
    cursor = start;
}

void EditorBuffer_Link_Adj::moveCursorToEnd(){
    while(cursor->link != NULL){
        cursor = cursor->link;
    }
}

void EditorBuffer_Link_Adj::insertCharacter(char ch){
    Cell *cp = new Cell;
    cp->ch = ch;
    cp->link = cursor->link;
    cursor->link = cp;
    cursor = cp;
}

void EditorBuffer_Link_Adj::deleteCharacter(){
    if(cursor->link != NULL){
        Cell *oldCell = cursor->link;
        cursor->link = cursor->link->link;
        delete oldCell;
    }
}

string EditorBuffer_Link_Adj::getText() const{
    string str = "";
    for (Cell *cp = start->link; cp != NULL; cp = cp->link){
        str += cp->ch;
    }
    return str;
}

int EditorBuffer_Link_Adj::getCursor(){
    int nChars = 0;
    for (Cell *cp = start; cp != cursor; cp = cp->link){
        nChars++;
    }
    return nChars;
}

























