#include <Python.h>

#include "skunkhash.h"

static PyObject *skunk_hash_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    Skunk_Hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    Skunk_Hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef SkunkHashMethods[] = {
    { "getPoWHash", skunk_hash_getpowhash, METH_VARARGS, "Returns the proof of work hash using skunkhash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef SkunkHashModule = {
    PyModuleDef_HEAD_INIT,
    "Skunk_Hash",
    "...",
    -1,
    SkunkhashMethods
};

PyMODINIT_FUNC PyInit_Skunk_Hash(void) {
    return PyModule_Create(&SkunkHashModule);
}

#else

PyMODINIT_FUNC initSkunk_Hash(void) {
    (void) Py_InitModule("Skunk_Hash", SkunkHashMethods);
}
#endif
