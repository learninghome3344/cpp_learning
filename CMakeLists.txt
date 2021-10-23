cmake_minimum_required(VERSION 3.19)
project(cpp_learning)

set(CMAKE_CXX_STANDARD 14)

#add_executable(cpp_learning
#        cbiancheng_base/section2_class_and_object/const_member_function.cpp
#        cbiancheng_base/section2_class_and_object/const_object.cpp
#        cbiancheng_base/section2_class_and_object/friend_class.cpp
#        cbiancheng_base/section2_class_and_object/friend_function.cpp
#        cbiancheng_base/section2_class_and_object/static_member_function.cpp
#        cbiancheng_base/section2_class_and_object/static_member_variable.cpp
#        cbiancheng_base/section2_class_and_object/this_pointer.cpp)

# 遍历项目根目录下所有的 .cpp 文件
# https://zhuanlan.zhihu.com/p/157646534
file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
