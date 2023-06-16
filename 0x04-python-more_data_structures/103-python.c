#include <Python.h>
#include <stdio.h>

/**
 * print_python_bytes - Prints information about a Python bytes object
 * @p: Pointer to the Python bytes object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t i, size, bytes_to_print;
	char *str;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = PyBytes_Size(p);
	str = PyBytes_AsString(p);

	printf("  size: %zd\n", size);
	printf("  trying string: %s\n", str);

	bytes_to_print = (size + 1 < 10) ? size + 1 : 10;
	printf("  first %zd bytes:", bytes_to_print);
	for (i = 0; i < bytes_to_print; i++)
		printf(" %02hhx", str[i]);
	printf("\n");
}

/**
 * print_python_list - Prints information about a Python list object
 * @p: Pointer to the Python list object
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t i, size;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %zd\n", PyList_Size(p));
	printf("[*] Allocated = %zd\n", ((PyListObject *)p)->allocated);

	for (i = 0, size = PyList_Size(p); i < size; i++)
	{
		printf("Element %zd: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
		if (strcmp(Py_TYPE(PyList_GetItem(p, i))->tp_name, "bytes") == 0)
			print_python_bytes(PyList_GetItem(p, i));
	}
}
