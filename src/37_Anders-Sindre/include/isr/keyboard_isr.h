#ifndef KEYBOARD_ISR_H
#define KEYBOARD_ISR_H

void keyboard_isr(void)
{
    // Read the data from the keyboard buffer
    unsigned char* keyboard_data = read_keyboard_data_from_buffer();
    
    // Check for any errors in the data
    if (check_keyboard_errors(keyboard_data) == KEYBOARD_ERROR) {
        return;
    }
    
    // Determine the type of keyboard event
    int event_type = get_keyboard_event_type(keyboard_data);
    
    // Handle the keyboard event
    if (event_type == KEY_PRESS) {
        handle_key_press(keyboard_data);
    }
    else if (event_type == KEY_RELEASE) {
        handle_key_release(keyboard_data);
    }
    
    // Notify the operating system that a keyboard event has occurred
    notify_os_keyboard_event();
}