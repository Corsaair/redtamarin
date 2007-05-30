@echo off
del test.exe
cd ..
java -jar bin\asc.jar -exe bin\avmplus_sd.exe -import tests\global.abc tests\test.as
cd tests
test.exe