cmake_minimum_required(VERSION 3.29)
project(picosec_cpp_analysis)

set(CMAKE_CXX_STANDARD 14)

include_directories(code)
include_directories(code/Bin2Tree)
include_directories(code/class_test)

add_executable(picosec_cpp_analysis
    code/Bin2Tree/bin2tree.cxx
    code/Bin2Tree/PathNames.h
    code/Bin2Tree/readLeCroyBinary.h
    code/class_test/read_waveform_fits.cpp
    code/class_test/WaveformFit.h
    code/class_test/write_waveform_fits.cpp
    code/analyseTree.cxx
    code/AnalyseTreePicosec.C
    code/AnalyseTreePicosec_akallits.C
    code/bin2tree.cxx
    code/ConstructDirTree.C
    code/Detector.cpp
    code/makeTree.cxx
    code/MakeTreefromRawTreePicosec.C
    code/MakeTreefromRawTreePicosec.cxx
    code/MyFunctions.C
    code/MyFunctions.h
    code/PathNames.h
    code/readLeCroyBinary.h
    code/tracks.C
    code/tracks.h)
