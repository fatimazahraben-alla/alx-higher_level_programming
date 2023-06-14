#!/usr/bin/python3
def simple_delete(a_dictionary, key=""):
    return {k: v for k, v in a_dictionary.items() if k != key}

if __name__ == '__main__':
    a_dictionary = {'language': "C", 'Number': 89, 'track': "Low level"}
    new_dict = simple_delete(a_dictionary, 'track')
    print(sorted(new_dict.items()))
    print("--")
    print(sorted(a_dictionary.items()))
    print("--")

    new_dict = simple_delete(a_dictionary, 'c_is_fun')
    print(sorted(new_dict.items()))
    print("--")
    print(sorted(a_dictionary.items()))
    print("--")

    new_dict = simple_delete(a_dictionary)
    print(sorted(new_dict.items()))
    print("--")
    print(sorted(a_dictionary.items()))
    print("--")
