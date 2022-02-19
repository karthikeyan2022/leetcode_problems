:: set the path to your visual studio vcvars script, it is different for every version of Visual Studio.
set VS2022TOOLS="C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

:: make sure we found them
if not exist %VS2022TOOLS% (
    echo VS 2022 Build Tools are missing!
    exit
)

:: call that script, which essentially sets up the VS Developer Command Prompt
call %VS2022TOOLS%

:: run the compiler with your arguments
cl.exe /EHsc /Zi /Fe: %1.exe %1.cpp

exit
