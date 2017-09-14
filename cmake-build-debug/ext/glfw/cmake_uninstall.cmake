
if (NOT EXISTS "/home/meriki/Documents/5th Sem/CG/Assignment02_code/cmake-build-debug/ext/glfw/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: \"/home/meriki/Documents/5th Sem/CG/Assignment02_code/cmake-build-debug/ext/glfw/install_manifest.txt\"")
endif()

file(READ "/home/meriki/Documents/5th Sem/CG/Assignment02_code/cmake-build-debug/ext/glfw/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")

foreach (file ${files})
  message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  if (EXISTS "$ENV{DESTDIR}${file}")
    exec_program("/home/meriki/App_files/clion-2017.2.1/bin/cmake/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
                 OUTPUT_VARIABLE rm_out
                 RETURN_VALUE rm_retval)
    if (NOT "${rm_retval}" STREQUAL 0)
      MESSAGE(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
    endif()
  elseif (IS_SYMLINK "$ENV{DESTDIR}${file}")
    EXEC_PROGRAM("/home/meriki/App_files/clion-2017.2.1/bin/cmake/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
                 OUTPUT_VARIABLE rm_out
                 RETURN_VALUE rm_retval)
    if (NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing symlink \"$ENV{DESTDIR}${file}\"")
    endif()
  else()
    message(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
  endif()
endforeach()

