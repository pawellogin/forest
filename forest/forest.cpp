#include "tree.h"
#include "forest.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

// cout forest, 
// all in classes 
//class tree and forest that can print lots of trees

using namespace std;

int arrow_menu(vector<string> options, const int MAX_OPTIONS);
void disable_cursor(bool run);
void add_tree();
void add_forest();
void change_tree(int& tree_option);
void change_forest(int& forest_option);

vector<tree*> tree_list;

vector<forest*> forest_list;

int main() {

	int choice = 0;
    int tree_option = 0;
    int forest_option = 0;

    vector<string> options = { "add_tree()","add_forest()", "print_tree()","print_forest()", "change_tree()","change_forest()", "exit(0)"};

    disable_cursor(1);

    tree_list.push_back(new tree());
    forest_list.push_back(new forest());
    

	while (1) {
        


        Sleep(300);
        switch (arrow_menu(options, options.size())) {

        case 1: add_tree(); break;
        case 2: add_forest(); break;
        case 3: system("cls"); 
                tree_list[tree_option]->printTree(); break;
        case 4: system("cls");
                forest_list[forest_option]->print_forest(*tree_list[tree_option]);  break;
        case 5: change_tree(tree_option); break;
        case 6: change_forest(forest_option); break;
		case 7: exit(0); break;
		default: break;
		}
		
	}

	return 0;
}

void change_tree(int& tree_option) {
    Sleep(300);
   
    system("cls");
    cout << "chose tree" << endl;
    cin >> tree_option;
    cin.clear();
    system("cls");
   
   
}

void change_forest(int& forest_option) {
    system("cls");
    Sleep(300);

   
    
    cout << "chose forest" << endl;
    cin >> forest_option;
    cin.clear();
    system("cls");
   
}

void add_tree() {

    int height;
    char symbol;
    int color;

    system("cls");
    Sleep(300);

    cin.clear();
    fflush(stdin);
   
    cout << "type in height, symbol, color (0-15) of a tree"<<endl;
    cin >> height;
    cin >> symbol;
    cin >> color;
    cin.clear();
    system("cls");
   

    tree_list.push_back(new tree(height, symbol, color));

   
}

void add_forest() {
    int num;


    system("cls");
    Sleep(300);
   
    cout << "type in number of trees in forest"<<endl;
    cin >> num;
    cin.clear();
    system("cls");

    forest_list.push_back(new forest(num));

   
}


void disable_cursor(bool run) {
    
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(consoleHandle, &cursorInfo);
        cursorInfo.bVisible = !run; 
        SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    
}

int arrow_menu(vector<string> options, const int MAX_OPTIONS) {

    const int ARROW_DELAY_MS = 300; // delay time in milliseconds for changing options with arrow keys

    int current_option = 1; // start with the first option selected
    int key; // to store the keyboard input
    bool is_arrow_key_pressed = false; // flag to indicate if an arrow key is currently pressed
    unsigned long arrow_key_last_pressed_time = 0; // last time an arrow key was pressed (in milliseconds)

    do {


        //display menu

        cout << endl;

        for (int i = 1; i <= MAX_OPTIONS; i++) {
            if (i == current_option) {
                cout << " --> " << options[i - 1] << endl;
            }
            else {
                cout << "     " << options[i - 1] << endl;
            }
        }

        //deleting menu

        string temp = "\033[" + to_string(MAX_OPTIONS + 1) + "A";
        cout << temp;
        for (int i = 0; i < MAX_OPTIONS + 1; i++) {
            cout << "\033[K";
        }


        key = 0; // reset the value of key to 0
        while (key == 0) { // wait for a key press
            for (int i = 8; i <= 256; i++) { // scan all possible virtual key codes
                if (GetAsyncKeyState(i) & 0x8000) { // check if the key is currently pressed
                    key = i; // store the virtual key code
                    break; // exit the loop
                }
            }
        }

        switch (key) {
        case 38: // up arrow
            if (!is_arrow_key_pressed || (GetTickCount64() - arrow_key_last_pressed_time >= ARROW_DELAY_MS)) {
                // check if the arrow key is not currently pressed, or if it was pressed more than ARROW_DELAY_MS milliseconds ago
                current_option--;
                if (current_option < 1) {
                    current_option = MAX_OPTIONS;
                }
                is_arrow_key_pressed = true; // set the arrow key pressed flag
                arrow_key_last_pressed_time = GetTickCount64(); // update the last pressed time
            } break;
        case 40: // down arrow
            if (!is_arrow_key_pressed || (GetTickCount64() - arrow_key_last_pressed_time >= ARROW_DELAY_MS)) {
                // check if the arrow key is not currently pressed, or if it was pressed more than ARROW_DELAY_MS milliseconds ago
                current_option++;
                if (current_option > MAX_OPTIONS) {
                    current_option = 1;
                }
                is_arrow_key_pressed = true; // set the arrow key pressed flag
                arrow_key_last_pressed_time = GetTickCount64(); // update the last pressed time

            }break;

        default: break;
        }

    } while (key != 13); // repeat until the Enter key is pressed

    return current_option;
}