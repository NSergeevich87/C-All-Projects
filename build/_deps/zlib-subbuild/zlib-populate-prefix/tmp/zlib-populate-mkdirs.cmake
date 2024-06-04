# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/C-All-Projects/build/_deps/zlib-src"
  "D:/C-All-Projects/build/_deps/zlib-build"
  "D:/C-All-Projects/build/_deps/zlib-subbuild/zlib-populate-prefix"
  "D:/C-All-Projects/build/_deps/zlib-subbuild/zlib-populate-prefix/tmp"
  "D:/C-All-Projects/build/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp"
  "D:/C-All-Projects/build/_deps/zlib-subbuild/zlib-populate-prefix/src"
  "D:/C-All-Projects/build/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/C-All-Projects/build/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/C-All-Projects/build/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
