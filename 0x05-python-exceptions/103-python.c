#include <Python.h>
#include <floatObject.h>
#include <stdio.h>

void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);
/**
 * print_python_list - prints some basic info about Python lists
 * @p: pointer to PyObject
 */
void print_python_list(PyObject *p)
{
    if (!PyList_Check(p))
    {
        fprintf(stderr, "  [ERROR] Invalid PyListObject\n");
        return;
    }

    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t i;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++)
    {
        PyObject *item = PyList_GetItem(p, i);
        const char *type = item->ob_type->tp_name;
        printf("Element %ld: %s\n", i, type);
    }
}

/**
 * print_python_bytes - prints some basic info about Python bytes objects
 * @p: pointer to PyObjec
 */
void print_python_bytes(PyObject *p)
{
    if (!PyBytes_Check(p))
    {
        fprintf(stderr, "  [ERROR] Invalid PyBytesObject\n");
        return;
    }

    Py_ssize_t size = PyBytes_Size(p);
    char *str = PyBytes_AsString(p);
    Py_ssize_t i;
    int max_bytes = (size > 10) ? 10 : size;

    printf("[.] bytes object info\n");
    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", str);

    printf("  first %d bytes: ", max_bytes);
    for (i = 0; i < max_bytes; i++)
        printf("%02x%c", (unsigned char)str[i], (i == max_bytes - 1) ? '\n' : ' ');

    if (size <= 10)
        printf("  end of string\n");
}

/**
 * print_python_float - prints some basic info about Python float objects
 * @p: pointer to PyObject
 */
void print_python_float(PyObject *p)
{
    if (!PyFloat_Check(p))
    {
        fprintf(stderr, "  [ERROR] Invalid PyFloatObject\n");
        return;
    }

    double value = PyFloat_AsDouble(p);

    printf("[.] float object info\n");
    printf("  value: %lf\n", value);
}
