##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Challenge14(Exceptions)
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :="C:/Users/Professional/Documents/C++ All Projects/C++ OOP"
ProjectPath            :="C:/Users/Professional/Documents/C++ All Projects/C++ OOP/Challenge14(Exceptions)"
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Challenge14(Exceptions)
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Professional
Date                   :=15/12/2023
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/Users/Professional/Documents/C++ All Projects/C++ OOP/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/mingw64/bin/windres.exe
LinkOptions            :=  -static
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/mingw64/bin/ar.exe -r
CXX      := C:/mingw64/bin/g++.exe
CC       := C:/mingw64/bin/gcc.exe
CXXFLAGS :=  -O0 -gdwarf-2 -std=c++17 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Trust_Account.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Savings_Account.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_I_Printable.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Account_Util.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Checking_Account.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Account.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Trust_Account.cpp$(ObjectSuffix): ../../../../Downloads/Section18/Challenge/Trust_Account.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Professional/Downloads/Section18/Challenge/Trust_Account.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Trust_Account.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Trust_Account.cpp$(PreprocessSuffix): ../../../../Downloads/Section18/Challenge/Trust_Account.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Trust_Account.cpp$(PreprocessSuffix) ../../../../Downloads/Section18/Challenge/Trust_Account.cpp

$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Savings_Account.cpp$(ObjectSuffix): ../../../../Downloads/Section18/Challenge/Savings_Account.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Professional/Downloads/Section18/Challenge/Savings_Account.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Savings_Account.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Savings_Account.cpp$(PreprocessSuffix): ../../../../Downloads/Section18/Challenge/Savings_Account.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Savings_Account.cpp$(PreprocessSuffix) ../../../../Downloads/Section18/Challenge/Savings_Account.cpp

$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_I_Printable.cpp$(ObjectSuffix): ../../../../Downloads/Section18/Challenge/I_Printable.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Professional/Downloads/Section18/Challenge/I_Printable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_I_Printable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_I_Printable.cpp$(PreprocessSuffix): ../../../../Downloads/Section18/Challenge/I_Printable.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_I_Printable.cpp$(PreprocessSuffix) ../../../../Downloads/Section18/Challenge/I_Printable.cpp

$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Account_Util.cpp$(ObjectSuffix): ../../../../Downloads/Section18/Challenge/Account_Util.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Professional/Downloads/Section18/Challenge/Account_Util.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Account_Util.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Account_Util.cpp$(PreprocessSuffix): ../../../../Downloads/Section18/Challenge/Account_Util.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Account_Util.cpp$(PreprocessSuffix) ../../../../Downloads/Section18/Challenge/Account_Util.cpp

$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Checking_Account.cpp$(ObjectSuffix): ../../../../Downloads/Section18/Challenge/Checking_Account.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Professional/Downloads/Section18/Challenge/Checking_Account.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Checking_Account.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Checking_Account.cpp$(PreprocessSuffix): ../../../../Downloads/Section18/Challenge/Checking_Account.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Checking_Account.cpp$(PreprocessSuffix) ../../../../Downloads/Section18/Challenge/Checking_Account.cpp

$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_main.cpp$(ObjectSuffix): ../../../../Downloads/Section18/Challenge/main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Professional/Downloads/Section18/Challenge/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_main.cpp$(PreprocessSuffix): ../../../../Downloads/Section18/Challenge/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_main.cpp$(PreprocessSuffix) ../../../../Downloads/Section18/Challenge/main.cpp

$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Account.cpp$(ObjectSuffix): ../../../../Downloads/Section18/Challenge/Account.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Professional/Downloads/Section18/Challenge/Account.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Account.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Account.cpp$(PreprocessSuffix): ../../../../Downloads/Section18/Challenge/Account.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_up_Downloads_Section18_Challenge_Account.cpp$(PreprocessSuffix) ../../../../Downloads/Section18/Challenge/Account.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


