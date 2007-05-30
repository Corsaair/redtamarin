@echo off
del test.exe
cd ..
java -jar bin\asc.jar -exe bin\avmplus_sd.exe -import libs\global.abc tests\test.as
cd tests
test.exe