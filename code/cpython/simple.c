#include <Python.h>

static PyObject* simple_hello(PyObject* self, PyObject* args){
    char *msg = "Hola PyBerlin!";
    return Py_BuildValue("s", msg);
}

static char simple_docs[] =
    "hello(): prints hello message :P\n";

static PyMethodDef simple_funcs[] = {
    {"hello",                   // ml_name
     (PyCFunction)simple_hello, // ml_meth
     METH_NOARGS,               // ml_flags
     simple_docs},              // ml_doc
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef simplemodule = {
    PyModuleDef_HEAD_INIT, // m_base
    "simple",              // m_name
    NULL,                  // m_doc
    -1,                    // m_size
    simple_funcs           // m_methods
};

PyMODINIT_FUNC PyInit_simple(void){
    return PyModule_Create(&simplemodule);
}
