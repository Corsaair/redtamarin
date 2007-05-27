@echo off
cd ..
java -jar bin\asc.jar -exe bin\avmplus_sd.exe tests\bug_File_exists.as
cd tests
bug_File_exists.exe