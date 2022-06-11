@echo off
cd "%~dp0"
echo 即将从GitHub仓库Pull文件到本地
git pull
echo 即将把文件Push到GitHub
set /p commit=请输入描述:
git add .
git commit -m "%commit%"
git push
pause