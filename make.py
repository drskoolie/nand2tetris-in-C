import glob
import os
import subprocess
from pathlib import Path

class CompileC:
    def __init__(self):
        self.src_dir = 'src'
        self.obj_dir = 'obj'

        self.debug_flags = ' -g'
        self.std_flags = ' -std=c17'
        self.include_flags = ' -Iinclude -Iunity'
        self.warnings_flags = ' -Wall -Wextra'

        self.flags = self.debug_flags + self.std_flags + self.include_flags + self.warnings_flags

    def compile_source_to_object(self, src_path, obj_path):
        """Compile a single source file to an object file."""
        command = ['gcc', self.flags, '-c', src_path, '-o', obj_path]
        subprocess.run(command, check = True)


if __name__ == "__main__":
    cc = CompileC()
    cc.compile_source_to_object("src/gates.c", "obj/gates.o")
    subprocess.run(['gcc', '-c', 'src/gates.c', '-o', 'obj/gates.o'], check = True)
