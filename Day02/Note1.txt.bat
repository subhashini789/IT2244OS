:: turn off command echoing to prevent displaying commands as they execute
@echo OFF

::user to enter their birth year and stores it in a variable 
set/p birthyear=Enter your birthyear:

::Calculates the age by subtracting the entered birth year from the current year.
set/a age=%date:~ 10,4% -%birthyear%
echo age:%age% yearold

::prevent the window closing immediately
pause
