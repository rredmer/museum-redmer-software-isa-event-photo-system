
echo OFF
cls

rem     Windows NT 4.0  loader of Win Driver libraries

copy windrvr.sys    %windir%\system32\drivers


wd433reg install


echo You must reboot your system for the changes to take place
