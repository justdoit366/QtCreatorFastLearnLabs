@echo off
cd "%~dp0"
echo ������GitHub�ֿ�Pull�ļ�������
git pull
echo �������ļ�Push��GitHub
set /p commit=����������:
git add .
git commit -m "%commit%"
git push
pause