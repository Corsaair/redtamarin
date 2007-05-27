@echo off
xcopy mozilla\js\tamarin\core\*.as libs\core /Y
java -jar bin\asc.jar libs\global.as