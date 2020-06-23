/*
 * File: init.h
 * ------------
 * This file contains code to check whether the Stanford C++ library has been
 * initialized, and if not, to initialize it.
 * This file must be included by every student-facing header in the Stanford
 * C++ library to make sure that the library is initialized before it is used.
 *
 * There used to be a group of files such as private/main.h, main.cpp, and
 * startup.cpp that contained various initialization code.  These were removed
 * and replaced with this style of initialization for the following reasons:
 *
 * - simplicity/consolidation
 * - allow student to NOT include console.h and use plain text console
 *
 * @version 2018/08/28
 * - refactor to use stanfordcpplib namespace and init.cpp
 * @version 2018/07/03
 * - add code to handle Qt GUI library initialization
 * @version 2017/04/25
 * - wrap library initializer in an #ifndef to avoid multiple declaration
 *
 * TODO: figure out how to support both 0-arg and 2-arg main()
 */

#ifndef _init_h
#define _init_h

#include <cstdlib>
#include <stdio.h>

namespace stanfordcpplib {

bool exitEnabled();
void initializeLibrary(int argc, char** argv);
void runMainInThread(int (* mainFunc)(void));
void runMainInThreadVoid(void (* mainFuncVoid)(void));
void setExitEnabled(bool enabled);
void shutdownLibrary();
void staticInitializeLibrary();

#ifndef StanfordCppLibraryInitializer_created
#define StanfordCppLibraryInitializer_created
class StanfordCppLibraryInitializer {
public:
    /*
     * Code to initialize the library.
     * Implemented as a class constructor so that it will run before the
     * student's main function.
     * Here we put anything that we need to initialize during the static
     * phase before main() runs.
     * Presently there is nothing that requires such initialization,
     * so this is blank.
     */
    StanfordCppLibraryInitializer() {
        staticInitializeLibrary();
    }
};
static StanfordCppLibraryInitializer __stanfordcpplib_init;
#endif // __StanfordCppLibraryInitializer_created

} // namespace stanfordcpplib

// keep in sync with definition in private/mainwrapper.cpp
#ifndef QT_NEEDS_QMAIN
#define main studentMain
#endif // QT_NEEDS_QMAIN

// bypass std::exit function
namespace std {
void __stanfordcpplib__exitLibrary(int status);
} // namespace std

#define STD_EXIT __std_exit_function_
#define exit __stanfordcpplib__exitLibrary

#ifdef SPL_OVERLOAD_PROBLEMATIC_POINTER_ARITHMETIC
#include "pointers.h"
#endif // SPL_OVERLOAD_PROBLEMATIC_POINTER_ARITHMETIC

#endif // _init_h
