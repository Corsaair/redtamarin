@echo off
xcopy mozilla\js\tamarin\shell\*.as libs\shell /Y
xcopy mozilla\js\tamarin\extensions\*.as libs\shell /Y
java -jar bin\asc.jar -import libs\global.abc libs\toplevel.as
xcopy libs\toplevel.h mozilla\js\tamarin\shell\ /Y
xcopy libs\toplevel.cpp mozilla\js\tamarin\shell\ /Y