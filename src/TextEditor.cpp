#include "TextEditor.h"

// Insert text at a specified position
void TextEditor::insertText(int position, const std::string& str) {
    if (position < 0 || position > text.size()) {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    // Save the current state for undo
    undoStack.push(std::string(text.begin(), text.end()));
    redoStack = std::stack<std::string>(); // Clear redo stack
    text.insert(text.begin() + position, str.begin(), str.end());
}

// Delete text from a specified position
void TextEditor::deleteText(int position, int length) {
    if (position < 0 || position + length > text.size()) {
        std::cout << "Invalid position or length" << std::endl;
        return;
    }
    // Save the current state for undo
    undoStack.push(std::string(text.begin(), text.end()));
    redoStack = std::stack<std::string>(); // Clear redo stack
    text.erase(text.begin() + position, text.begin() + position + length);
}

// Undo the last operation
void TextEditor::undo() {
    if (undoStack.empty()) {
        std::cout << "Nothing to undo" << std::endl;
        return;
    }
    redoStack.push(std::string(text.begin(), text.end())); // Save current state for redo
    std::string lastState = undoStack.top();
    undoStack.pop();
    text.clear();
    text.assign(lastState.begin(), lastState.end());
}

// Redo the last undone operation
void TextEditor::redo() {
    if (redoStack.empty()) {
        std::cout << "Nothing to redo" << std::endl;
        return;
    }
    undoStack.push(std::string(text.begin(), text.end())); // Save current state for undo
    std::string lastState = redoStack.top();
    redoStack.pop();
    text.clear();
    text.assign(lastState.begin(), lastState.end());
}

// Copy text to the clipboard
void TextEditor::copy(int position, int length) {
    if (position < 0 || position + length > text.size()) {
        std::cout << "Invalid position or length" << std::endl;
        return;
    }
    std::string copiedText(text.begin() + position, text.begin() + position + length);
    clipboard.push(copiedText);
}

// Paste text from the clipboard
void TextEditor::paste(int position) {
    if (position < 0 || position > text.size()) {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    if (clipboard.empty()) {
        std::cout << "Clipboard is empty" << std::endl;
        return;
    }
    std::string textToPaste = clipboard.front();
    undoStack.push(std::string(text.begin(), text.end())); // Save current state for undo
    redoStack = std::stack<std::string>(); // Clear redo stack
    text.insert(text.begin() + position, textToPaste.begin(), textToPaste.end());
}

// Display the current text
void TextEditor::display() const {
    std::cout << "Current text: ";
    for (char c : text) {
        std::cout << c;
    }
    std::cout << std::endl;
}
