//
// Created by 4ndre on 17/05/2024.
//

#ifndef POO2024_DICE_H
#define POO2024_DICE_H

#include <random>
#include "C:\Users\4ndre\AppData\Local\Programs\Python\Python311\include\Python.h"
#include <iostream>


class Dice {
public:

    static double roll() {
        Py_Initialize();

        PyObject * name, *load_module, *func, *callfunc, *args;
        name = PyUnicode_FromString((char *) "HW1CedAnd/src/utilities/randomlib.py");
        load_module = PyImport_Import(name);
        func = PyObject_GetAttrString(load_module, (char *) "random_number");
        callfunc = PyObject_CallObject(func, NULL);
        int fun1_out = int(PyFloat_AsDouble(callfunc));
        return fun1_out;
    }

};


#endif //POO2024_DICE_H
