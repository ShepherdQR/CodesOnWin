#语法规则
# targets...:prerequisites...
# 目标文件...:先决条件
# target 这 一 个 或 多 个 的 目 标 文 件 依 赖 于 	prerequisites 中 的 文 件
#	command

#https://www.coonote.com/linux-note/makefile-simple-tutorial.html

# -fmodule-header
CFLAG=-std=c++2b -fmodules-ts
COMPLIAR=g++ $(CFLAG)

ALL: std_headers studyF_Module.o studyF_ModuleImp.o main

# DEPS_PUBLIC = AA.h

std_headers:
	$(COMPLIAR) -xc++-system-header iostream
	$(COMPLIAR) -xc++-system-header string


#%.o:%.cc #$(DEPS_PUBLIC)
#	$(COMPLIAR) -c $< -o $@


studyF_Module.o: studyF_Module.cc
	$(COMPLIAR) -c $< -o $@

studyF_ModuleImp.o: studyF_Module.cpp
	$(COMPLIAR) -c $< -o $@

main: studyF_ModuleMain.cpp studyF_Module.o studyF_ModuleImp.o
	$(COMPLIAR) $^ -o $@



.PHONY:clean
clean:
	-rm testMakeFile

#.PHONY 意思表示 clean 是一个“伪目标”
#而在 rm 命令前面加了一个小减号的意思就是,也许某些文件出现问题,但不要管,继续做后面的事。
#当然，也可以这样
#clean:
#	-rm hello
#但这是不推荐的，如果在当前目录下，存在一个clean，那么就不执行clean后面的规则了