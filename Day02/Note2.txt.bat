:: turn off command echoing to prevent displaying commands as they execute
@echo off

::Extracts 2 characters starting from position 4 in the system date and stores it in the variable Month(the month part).
set/a Month=%date:~ 4,2%
::Displays the extracted month.
 echo your month is %Month%

::Extracts 2 characters starting from position 7.
set/a Day=%date:~ 7,2%
::Displays the extracted Day.
echo your Day is %Day%


if "%month%"=="1" set monthName=January
if "%month%"=="2" set monthName=February
if "%month%"=="3" set monthName=March
if "%month%"=="4" set monthName=April
if "%month%"=="5" set monthName=May
if "%month%"=="6" set monthName=June
if "%month%"=="7" set monthName=July
if "%month%"=="8" set monthName=August
if "%month%"=="9" set monthName=September
if "%month%"=="10" set monthName=October
if "%month%"=="11" set monthName=November
if "%month%"=="12" set monthName=December

echo The current month is %monthName%.

::prevent the window closing immediately
pause
