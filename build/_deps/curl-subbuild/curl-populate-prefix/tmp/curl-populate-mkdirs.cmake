# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/C-All-Projects/build/_deps/curl-src"
  "D:/C-All-Projects/build/_deps/curl-build"
  "D:/C-All-Projects/build/_deps/curl-subbuild/curl-populate-prefix"
  "D:/C-All-Projects/build/_deps/curl-subbuild/curl-populate-prefix/tmp"
  "D:/C-All-Projects/build/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
  "D:/C-All-Projects/build/_deps/curl-subbuild/curl-populate-prefix/src"
  "D:/C-All-Projects/build/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/C-All-Projects/build/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/C-All-Projects/build/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
