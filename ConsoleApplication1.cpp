 // ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class TextEditor {
    string str;
public:    
    TextEditor() {}

    TextEditor(TextEditor* text) {
          this->str = text->getStr();
      }
      string getStr() {
          return str;
      }
      void setStr(string str) {
          this->str = str;
      }
};

class SimpleTextEditor : public TextEditor {
public:
    SimpleTextEditor() : TextEditor() {
        setStr("Base text");
    }
    SimpleTextEditor(TextEditor* text) : TextEditor(text) {
        setStr(text->getStr() + " Simple text");
    }
};

class SpellChecker : public TextEditor {
public:
    SpellChecker() : TextEditor() {};
    SpellChecker(TextEditor* text) : TextEditor(text) {
        setStr(text->getStr() + " Spell text");
    }
};

class SyntaxHighlighter : public TextEditor {
public:    
    SyntaxHighlighter() : TextEditor() {};
    SyntaxHighlighter(TextEditor* text) : TextEditor(text) {
        setStr(text->getStr() + " Syntax text");
    }
};

class AutoSave : public TextEditor {
public:
    AutoSave() : TextEditor() {};
    AutoSave(TextEditor* text) : TextEditor(text) {
        setStr(text->getStr() + " Auto text");
    }
};

int main()
{
    TextEditor* editor = new SimpleTextEditor();
    editor = new SimpleTextEditor(editor);
    editor = new SpellChecker(editor);
    editor = new SyntaxHighlighter(editor);
    editor = new AutoSave(editor);

    cout << "Result: " << editor->getStr();

    delete editor;

}