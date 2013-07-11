@echo off
cd "C:\epidatabase\sql"
echo ========== FLEX  ==========
flex sql.l
echo ========== BISON ==========
bison -d sql.y
pause
@echo on