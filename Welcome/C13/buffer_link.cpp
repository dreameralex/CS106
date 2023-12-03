#include "buffer_link.h"
#include "charstack.h"
#include <iostream>
using namespace std;
#include <string>


EditorBuffer_Link::EditorBuffer_Link(){}
EditorBuffer_Link::~EditorBuffer_Link(){}


void EditorBuffer_Link::moveCursorForward(){

    if(!after.isEmpty()){
        before.push(after.pop());
    }
}

void EditorBuffer_Link::moveCursorBackward(){

    if(!before.isEmpty()){
        after.push(before.pop());
    }
}

void EditorBuffer_Link::moveCursorToStart(){
    while(!before.isEmpty()){
        after.push(before.pop());
    }
}

void EditorBuffer_Link::moveCursorToEnd(){
    while(!after.isEmpty()){
        before.push(after.pop());
    }
}

void EditorBuffer_Link::insertCharacter(char ch){
    before.push(ch);
}

void EditorBuffer_Link::deleteCharacter(){
    while(!after.isEmpty()){
        after.pop();
    }
}

string EditorBuffer_Link::getText() const{
    CharStack beforecopy = before;
    CharStack aftercopy = after;
    string str = "";
    while(!beforecopy.isEmpty()){
        str = beforecopy.pop() + str;
    }
    while (!aftercopy.isEmpty()) {
        str += aftercopy.pop();
    }
    return str;
}

int EditorBuffer_Link::getCursor(){
    return before.size();
}

























