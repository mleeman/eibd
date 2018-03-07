/* SWIG interface spec for eibclient */
/*                                   */
/* has all eibclient interfaces in   */
/* (Martin's code THAT clean!) but   */
/* you will realize, some of them    */
/* cannot be called from Python      */
/* unless you SWIG code around them  */
/* analogous to the eibgetbusmonitorpacket */
/* I already did. Not hard.         */


/*
    EIBD client library
    Copyright (C) 2006 Tony Przygienda, Z2 GmbH

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    In addition to the permissions in the GNU General Public License,
    you may link the compiled version of this file into combinations
    with other programs, and distribute those combinations without any
    restriction coming from the use of this file. (The General Public
    License restrictions do apply in other respects; for example, they
    cover modification of the file, and distribution when not linked into
    a combine executable.)

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

%module eibclient
%{
#include "eibtypes.h"
#include "eibclient.h"
%}

%{
    
%}

%include exception.i       

%typemap(in, numinputs=0) (int maxlen, uint8_t *buf) (unsigned char temp[1024])
{
    $1 = sizeof(temp);
    $2 = temp;
}

%typemap(in, numinputs=0) (int max_len, uint8_t *buf) (unsigned char temp[1024])
{
    $1 = sizeof(temp);
    $2 = temp;
}

%typemap(in, numinputs=1) (int len, uint8_t * data)
{
    $1 = PyString_Size($input);
    $2 = PyString_AsString($input);
}

%typemap(argout) (int maxlen, uint8_t *buf)
{
    if (result < 0) {      /* Check for I/O error */
	PyErr_SetFromErrno(PyExc_IOError);
	return NULL;
    }
    PyObject *o;
    o = PyString_FromStringAndSize((char *)$2,result);
    if ((!$result) || ($result == Py_None)) {
            $result = o;
        } 
    else {
        if (!PyList_Check($result)) {
            PyObject *o2 = $result;
	    $result = PyList_New(0);
	    PyList_Append($result,o2);
	    Py_XDECREF(o2);
        }
    PyList_Append($result,o);
    Py_XDECREF(o);
    }
}


%typemap(argout) (int max_len, uint8_t *buf)
{
    if (result < 0) {      /* Check for I/O error */
	PyErr_SetFromErrno(PyExc_IOError);
	return NULL;
    }
    PyObject *o;
    o = PyString_FromStringAndSize((char *)$2,result);
    if ((!$result) || ($result == Py_None)) {
            $result = o;
        } 
    else {
        if (!PyList_Check($result)) {
            PyObject *o2 = $result;
	    $result = PyList_New(0);
	    PyList_Append($result,o2);
	    Py_XDECREF(o2);
        }
    PyList_Append($result,o);
    Py_XDECREF(o);
    }
}

%typemap(in, numinputs=0) (eibaddr_t *OUTPUT) (eibaddr_t temp)
{
    $1 = &temp;
}

%typemap(argout) (eibaddr_t *OUTPUT) {
    PyObject *o;
    o = PyInt_FromLong((long) *$1);    
    if ((!$result) || ($result == Py_None)) {
	$result = o;
    } 
    else {
	if (!PyList_Check($result)) {
	    PyObject *o2 = $result;
	    $result = PyList_New(0);
	    PyList_Append($result,o2);
	    Py_XDECREF(o2);
	}
    PyList_Append($result,o);
    Py_XDECREF(o);
    }
}

%typemap(in) (eibaddr_t INPUT) {
    $1 = ($type) PyInt_AsLong($input);
}

%typemap(in) (uint16_t age) {
    $1 = ($type) PyInt_AsLong($input);
}

%exception {
        Py_BEGIN_ALLOW_THREADS
        $function
	Py_END_ALLOW_THREADS
}

%apply eibaddr_t *OUTPUT { eibaddr_t *src };
%apply eibaddr_t *OUTPUT { eibaddr_t *dest };
%apply eibaddr_t  INPUT { eibaddr_t dest };

%include "eibtypes.h"
#define __BEGIN_DECLS
#define __END_DECLS
%include "eibclient.h"


%module(package="eibclient") xrc
