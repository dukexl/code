#include <iostream>

int main()
{
    using namespace std;
    cout << "C++ version = " << __cplusplus << endl;
    cout << "gcc version = " << __VERSION__ << endl;
    cout << "gcc major = " << __GNUC__ << endl;
    cout << "gcc minor = " << __GNUC_MINOR__ << endl;
    cout << "gcc patch = " << __GNUC_PATCHLEVEL__ << endl;

    // check __GLIBCXX__ for macos
#ifndef __GLIBCXX__
#define __GLIBCXX__ "unkown version,please check or config your gcc path,or your OS not surpport."
#endif

    cout << "libstdc++ = " << __GLIBCXX__ << endl;
}