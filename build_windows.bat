call xmake project -k vsxmake -a "x64"
call xmake config -y  -P . -p windows -m debug -a "x64" -o "build"
PAUSE