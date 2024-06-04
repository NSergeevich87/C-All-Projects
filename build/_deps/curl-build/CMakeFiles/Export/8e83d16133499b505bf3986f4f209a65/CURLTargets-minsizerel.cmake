#----------------------------------------------------------------
# Generated CMake target import file for configuration "MinSizeRel".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "CURL::libcurl_shared" for configuration "MinSizeRel"
set_property(TARGET CURL::libcurl_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(CURL::libcurl_shared PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "${_IMPORT_PREFIX}/lib/libcurl_imp.lib"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/bin/libcurl.dll"
  )

list(APPEND _cmake_import_check_targets CURL::libcurl_shared )
list(APPEND _cmake_import_check_files_for_CURL::libcurl_shared "${_IMPORT_PREFIX}/lib/libcurl_imp.lib" "${_IMPORT_PREFIX}/bin/libcurl.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
