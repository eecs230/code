# Install script for directory: /Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/libUnitTest++.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libUnitTest++.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libUnitTest++.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libUnitTest++.a")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/UnitTest++" TYPE FILE FILES
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/AssertException.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/CheckMacros.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/Checks.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/CompositeTestReporter.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/Config.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/CurrentTest.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/DeferredTestReporter.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/DeferredTestResult.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/ExceptionMacros.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/ExecuteTest.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/HelperMacros.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/MemoryOutStream.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/ReportAssert.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/ReportAssertImpl.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/Test.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/TestDetails.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/TestList.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/TestMacros.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/TestReporter.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/TestReporterStdout.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/TestResults.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/TestRunner.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/TestSuite.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/TimeConstraint.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/TimeHelpers.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/UnitTest++.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/UnitTestPP.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/XmlTestReporter.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/UnitTest++/Posix" TYPE FILE FILES
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/Posix/SignalTranslator.h"
    "/Users/tov/school/eecs230/code/lec05/.eecs230/lib/unittest-cpp/UnitTest++/Posix/TimeHelpers.h"
    )
endif()

