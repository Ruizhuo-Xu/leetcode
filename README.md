# leetcode
Windows PowerShell 递归删除子目录下所有的.exe文件:
```shell
Get-ChildItem * -Include *.exe -Recurse | Remove-Item
```