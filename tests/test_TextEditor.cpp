#include "TextEditor.h"
#include <cassert>
#include <iostream>

void testInsert() {
    TextEditor editor;
    editor.insertText(0, "Hello");
    assert(editor.toString() == "Hello");
}

void testDelete() {
    TextEditor editor;
    editor.insertText(0, "Hello");
    editor.deleteText(0, 2);
    assert(editor.toString() == "llo");
}

void testUndo() {
    TextEditor editor;
    editor.insertText(0, "Hello");
    editor.deleteText(0, 2);
    editor.undo();
    assert(editor.toString() == "Hello");
}

void testRedo() {
    TextEditor editor;
    editor.insertText(0, "Hello");
    editor.deleteText(0, 2);
    editor.undo();
    editor.redo();
    assert(editor.toString() == "llo");
}

void testCopyPaste() {
    TextEditor editor;
    editor.insertText(0, "Hello");
    editor.copy(0, 2);
    editor.paste(5);
    assert(editor.toString() == "HelloHe");
}

int main() {
    testInsert();
    testDelete();
    testUndo();
    testRedo();
    testCopyPaste();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
