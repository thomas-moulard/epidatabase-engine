@echo off
cd "C:\epiDatabase\sql"
echo ========== FLEX  ==========
flex -d sql.l
echo ========== BISON ==========
bison -d --debug --verbose sql.y
pause
@echo on