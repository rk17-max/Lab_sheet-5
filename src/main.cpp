#include "TextEditor.h"

int main() {
    TextEditor editor;

    editor.insertText(0, "Hello");
    editor.display();

    editor.insertText(5, " World");
    editor.display();

    editor.deleteText(5, 1);
    editor.display();

    editor.undo();
    editor.display();

    editor.redo();
    editor.display();

    editor.copy(0, 5);
    editor.paste(6);
    editor.display();

    return 0;
}
