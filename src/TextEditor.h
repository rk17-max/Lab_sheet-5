#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

class TextEditor {
private:
    std::vector<char> text; // Using vector to store characters
    std::stack<std::string> undoStack; // Stack for undo functionality
    std::stack<std::string> redoStack; // Stack for redo functionality
    std::queue<std::string> clipboard; // Queue for clipboard management

public:
    void insertText(int position, const std::string& str);
    void deleteText(int position, int length);
    void undo();
    void redo();
    void copy(int position, int length);
    void paste(int position);
    void display() const; // Display current text
};

#endif // TEXTEDITOR_H
