echo "Deleting existing solution and project files"
del /F /Q .\godot.sln
del /F /Q .\godot.vcxproj

.\RunSconsGenerateProject.bat
cmd /k

