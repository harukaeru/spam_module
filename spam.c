#include "Python.h"

// python: spam.system("ls -l")
// "self" equals to Module, "ls -l" is first value in arguments tuple
static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    // args ("ls -t",) assign to command
    // "s" is signature of 'Convert Unicode object to "char object of C" with UTF-8 encoding'
    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    // If you don't want to return anything, you should RETURN Py_None object as the following.
    // Py_RETURN_NONE;  // NOT "return Py_RETURN_NONE;"
    return PyLong_FromLong(sts);
}

static PyMethodDef SpamMethods[] = {
    {"system",  spam_system, METH_VARARGS,
     "Execute a shell command."},
    {NULL, NULL, 0, NULL}        /* Sentinel: If not found, return here. */
};

static struct PyModuleDef spammodule = {
   PyModuleDef_HEAD_INIT,
   "spam",   /* name of module */
   "DOCUMENT", /* module documentation, may be NULL */
   -1,       /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
   SpamMethods
};

PyMODINIT_FUNC
PyInit_spam(void)
{
    return PyModule_Create(&spammodule);
}
