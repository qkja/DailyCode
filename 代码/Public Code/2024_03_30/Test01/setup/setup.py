from cx_Freeze import setup, Executable

setup(name="YourProgram",
      version="0.1",
      description="Description of your program",
      executables=[Executable("../test.cpp")])
